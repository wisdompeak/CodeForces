#include<bits/stdc++.h>
#include <iostream>
using namespace std;


void solution(int n, int z, vector<int>&nums)
{    
    sort(nums.begin(),nums.end());

    int i;
    int j=0;
    for (i=0; i<n; i++)
    {
        while (j<n && nums[j]-nums[i]<z)
            j++;
        if (j==n) break;
        j++;
    }
    cout<<min(n/2,i)<<endl;
}

int main() {
    int n, z;
    cin>>n>>z;

    vector<int>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
        
    solution(n,z,nums);
}
