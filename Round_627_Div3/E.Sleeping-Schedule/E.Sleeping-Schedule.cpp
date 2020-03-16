#include<bits/stdc++.h>
#define ll long long
using namespace std;
    
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    
    vector<int>a(n);
    for (int i=0; i<n; i++)
        cin>>a[i];
    
    vector<int>dp(h,-1);
    dp[0] = 0;
    for (int i=0; i<n; i++)
    {
        vector<int>dp2(h,-1);
        for (int j=0; j<h; j++)
        {
            if (dp[(j+h-a[i])%h]!=-1)
            {
                dp2[j] = max(dp2[j], dp[(j+h-a[i])%h] + ((j>=l && j<=r)?1:0));
            }
            if (dp[(j+h-a[i]+1)%h]!=-1)
            {
                dp2[j] = max(dp2[j], dp[(j+h-a[i]+1)%h] + ((j>=l && j<=r)?1:0));
            }
        }
        dp = dp2;
    }
    
    int ret = 0;
    for (int j=0; j<h; j++)
        ret = max(ret, dp[j]);
    cout<<ret<<endl;
}
