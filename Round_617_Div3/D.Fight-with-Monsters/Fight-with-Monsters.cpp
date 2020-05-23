#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
 
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
 
 
int solve(int n, int a, int b, int k, vector<int>&nums)
{
    for (int i=0; i<n; i++)
    {
        if (nums[i]%(a+b) == 0)
            nums[i] = a+b;
        else
            nums[i] = nums[i]%(a+b);
    }
    sort(nums.begin(), nums.end());
        
    int count = 0;
    for (int i=0; i<n; i++)
    {
        if (nums[i]<=a)
        {
            count++;
        }
        else
        {
            int times = ceil((nums[i]-a)*1.0/a);
            if (k>=times)
            {
                count++;
                k-=times;
            }
            else
                break;
        }
    }
    return count;
    
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    vector<int>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
    
    cout<<solve(n,a,b,k,nums)<<endl;
}
