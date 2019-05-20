#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<ll>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];

    sort(nums.begin(),nums.end());

    ll result = 0;
    for (int i=0; i<nums.size(); i++)
    {
        if (nums[i]<0)
        {
            auto iter1 = upper_bound(nums.begin(),nums.end(),nums[i]*1.0/2);
            result+=max(0,int(iter1-nums.begin()-i-1));

            auto iter2 = lower_bound(nums.begin(),nums.end(),-nums[i]*1.0/2);
            auto iter3 = upper_bound(nums.begin(),nums.end(),-nums[i]*2);
            result+=max(0,int(iter3-iter2));
        }
        else
        {
            auto iter1 = upper_bound(nums.begin(),nums.end(),nums[i]*2);
            result+=max(0,int(iter1-nums.begin()-i-1));
        }
    }

    cout<<result<<endl;
}
