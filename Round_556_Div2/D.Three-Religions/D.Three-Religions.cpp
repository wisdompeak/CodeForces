#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n,q;
    string s;
    cin>>n>>q>>s;
    
    int next[100003][26];
           
    for (int j=0; j<26; j++)
    {
        next[n+1][j] = n+2;
        next[n+2][j] = n+2;
    }
        
    for (int i=n; i>=1; i--)
    {
        for (int j=0; j<26; j++)
            next[i][j] = next[i+1][j];
        next[i][s[i-1]-'a'] = i;
    }
        
    int dp[251][251][251];
    int len[4];
    int str[4][251];
    
    for (int qq=0; qq<q; qq++)
    {
        char sign, ch;
        int x;
        cin>>sign>>x;
        if (sign=='+')
        {
            cin>>ch;
            len[x]++;
            str[x][len[x]] = ch-'a';
                        
            for (int i=(x==1)*len[1]; i<=len[1]; i++)
                for (int j=(x==2)*len[2]; j<=len[2]; j++)
                    for (int k=(x==3)*len[3]; k<=len[3]; k++)
                    {
                        dp[i][j][k] = n+1;
                        if (i>0)
                        {
                            int prevStatus = dp[i-1][j][k];
                            dp[i][j][k] = min(dp[i][j][k], next[prevStatus+1][str[1][i]]);                            
                        }
                        if (j>0)
                        {
                            int prevStatus = dp[i][j-1][k];
                            dp[i][j][k] = min(dp[i][j][k], next[prevStatus+1][str[2][j]]);                            
                        }
                        if (k>0)
                        {
                            int prevStatus = dp[i][j][k-1];
                            dp[i][j][k] = min(dp[i][j][k], next[prevStatus+1][str[3][k]]);                            
                        }   
                        
                    }            
        }
        else
            len[x]--;
        
        if (dp[len[1]][len[2]][len[3]]<=n)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        
    }
    
}
