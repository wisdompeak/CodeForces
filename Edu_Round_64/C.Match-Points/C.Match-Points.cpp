#include<bits/stdc++.h>
#include <iostream>
using namespace std;


void solution(int n, int z, vector<int>&nums)
{    
    sort(nums.begin(),nums.end());

    int i;
    int j=n/2;
    for (i=0; i<n/2; i++)
    {
        while (j<n && nums[j]-nums[i]<z)
            j++;
        if (j==n) break;
        j++;
    }
    cout<<i<<endl;
}

int main() {
    int n, z;
    cin>>n>>z;

    vector<int>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
        
    solution(n,z,nums);
}
