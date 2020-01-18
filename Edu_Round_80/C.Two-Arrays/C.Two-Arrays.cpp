#include<bits/stdc++.h>
#define ll long long
using namespace std;

 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    int MOD = 1e9+7;
    
    auto dp = vector<vector<ll>>(m+1,vector<ll>(n+1,0));
    for (int k = 1; k<=n; k++)
        dp[1][k] = 1;
    for (int i=2; i<=m; i++)
    {
        ll sum = 0;
        for (int k=1; k<=n; k++)
        {
            sum = (sum + dp[i-1][k])%MOD;
            dp[i][k] = sum;
        }
    }
    
    int ret = 0;
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
            ret = (ret+(dp[m][i]*dp[m][n-j+1])%MOD)%MOD;
    }
    
    cout<<ret<<endl;        
}
