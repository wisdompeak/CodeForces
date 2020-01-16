#include<bits/stdc++.h>
#define ll long long
using namespace std;

 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>p(n);
    for (int i=0; i<n; i++)
        cin>>p[i];
    sort(p.begin(),p.end());
    
    auto dp = vector<vector<int>>(n,vector<int>(3,0));
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    
    for (int i=1; i<n; i++)
    {        
        for (int k=-1; k<=1; k++)
        {
            if (p[i]+k==p[i-1]-1)
                dp[i][k+1] = dp[i-1][0];
            else if (p[i]+k==p[i-1])
                dp[i][k+1] = dp[i-1][1];
            else if (p[i]+k==p[i-1]+1)
                dp[i][k+1] = dp[i-1][2];
            else
                dp[i][k+1] = dp[i-1][0]+1;
        }
    }
    
    
    auto dp2 = vector<vector<int>>(n,vector<int>(3,0));
    dp2[0][0] = dp2[0][1] = dp2[0][2] = 1;
    
    for (int i=1; i<n; i++)
    {        
        for (int k=-1; k<=1; k++)
        {
            if (p[i]+k > p[i-1]+1)
                dp2[i][k+1] = dp2[i-1][2]+1;
            else if (p[i]+k==p[i-1]+1)
                dp2[i][k+1] = dp2[i-1][1]+1;
            else if (p[i]+k==p[i-1])
                dp2[i][k+1] = dp2[i-1][0]+1;
            else
                dp2[i][k+1] = dp2[i-1][0];
        }
    }    
    
    int a = dp[n-1][0];
    int b = dp2[n-1][2];
    
    cout<<a<<" "<<b<<endl;
    
}
