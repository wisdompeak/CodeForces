// #include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solution(int n, int x, vector<ll>&nums)
{
    nums.insert(nums.begin(),0);
    auto dp = vector<vector<ll>>(n+1,vector<ll>(3,0));
    ll result = 0;
    
    for (int i=1; i<=n; i++)
    {
        dp[i][0] = dp[i-1][0]+nums[i];   
        dp[i][0]= max(0ll,dp[i][0]);
        
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + nums[i]*x;
        dp[i][1]= max(0ll,dp[i][1]);
        
        dp[i][2] = max(dp[i-1][2], dp[i-1][1]) + nums[i];
        dp[i][2]= max(0ll,dp[i][2]);
        
        result = max(result,dp[i][0]);
        result = max(result,dp[i][1]);
        result = max(result,dp[i][2]);        
    }
    
    return result;
}


int main()
{
    int n,x;
    cin >> n >>x;

    vector<ll>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];

    cout<<solution(n, x, nums)<<endl;

}

