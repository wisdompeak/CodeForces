#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main() {
    int n;
    vector<int>nums;
    
    cin>>n;    
    nums.resize(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
    
    // n = 7;
    // nums = {4, 3, 5, 1, 2, 2, 1};

    sort(nums.begin(),nums.end());
    
    int start = 0;
    int len = 0;
    
    for (int i=0; i<n; i++)
    {
        int i0 = i;
        while (i<n && nums[i]==nums[i0])
            i++;
        
        int j = i;
        int j0 = j;
        while(j<n)
        {
            if (nums[j]-nums[j-1]>1) break;
            j0 = j;
            while (j<n && nums[j]==nums[j0])
                j++;
            if (j-j0<=1)
                break;
        }
        
        if (j-i0>len)
        {
            len = j-i0;
            start = i0;
        }
        
        if (j-j0==1)
            i = j0-1;
        else
            i = j-1;
    }
    
    vector<int>a;
    vector<int>b;
    for (int i=start; i<start+len; i++)
    {
        int i0 = i;
        while (i<start+len && nums[i]==nums[i0])
            i++;
        int count = i-i0;
        a.push_back(nums[i0]);
        for (int k=0; k<count-1; k++)
            b.push_back(nums[i0]);
        i--;
    }
    
    reverse(b.begin(),b.end());
    cout<<len<<endl;
    for (auto x:a)
        cout<<x<<" ";
    for (auto x:b)
        cout<<x<<" ";
}
