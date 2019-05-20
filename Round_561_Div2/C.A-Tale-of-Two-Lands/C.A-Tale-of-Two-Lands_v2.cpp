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
    {
        ll x;
        cin>>x;
        nums[i] = abs(x);
    }
    
    sort(nums.begin(),nums.end());
    
    ll result = 0;
    int j=1;
    for (int i=0; i<nums.size(); i++)
    {
        j = max(j,i+1);
        while (j<nums.size() && nums[j]<=nums[i]*2)
            j++;
        result+= j-(i+1);    
    }
    
    cout<<result<<endl;
}
