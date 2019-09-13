#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
 
int main() {
    int n;
    cin>>n;
    auto graph = vector<vector<int>>(n+1,vector<int>(n+1,0));
    auto dp = vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX/2));
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=1; j<=n; j++)
        {
            graph[i][j] = s[j-1]-'0';
            if (graph[i][j]==1)
                dp[i][j] = 1;
        }
    }
    
    int m;
    cin>>m;
    vector<int>q(m);
    for (int i=0; i<m; i++)
        cin>>q[i];
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            for (int k=1; k<=n; k++)
            {
                if (i==j) 
                    dp[i][j] = 0;
                else if (dp[i][j] > dp[i][k]+dp[k][j])
                    dp[i][j] = dp[i][k]+dp[k][j];
            }
            
    vector<int>flag(m,1);
    for (int i=0; i<m; i++)
    {
        if (flag[i]==0) continue;
        int j = i+2;
        
        while (j<m && dp[q[i]][q[j-1]]+dp[q[j-1]][q[j]]==dp[q[i]][q[j]])
        {            
            flag[j-1] = 0;
            j++;
        }
    }
    
    int count = 0;
    for (auto x:flag) count+=(x==1);
    cout<<count<<endl;
    
    for (int i=0; i<m; i++)
    {
        if (flag[i]==1)
            cout<<q[i]<<" ";
    }
    return 0;
}
