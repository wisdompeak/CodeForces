#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
    
    int left = 0, right = m;    
    auto test = nums;
    while (left<right)
    {
        int mid = left+(right-left)/2;
        int flag = 1;
        
        if (nums[0]+mid>=m)
            test[0] = 0;
        else
            test[0] = nums[0];
            
        for (int i=1; i<n; i++)
        {
            if (nums[i] < test[i-1])
            {
                if (nums[i]+mid < test[i-1])
                {
                    flag = 0;
                    break;
                }
                else
                {
                    test[i] = test[i-1];
                }                
            }
            else
            {
                if (nums[i]+mid>=m && (nums[i]+mid)%m >= test[i-1])
                    test[i] = test[i-1];
                else
                    test[i] = nums[i];
            }            
        }
        
        if (flag)
            right = mid;
        else
            left = mid+1;
    }
    
    cout<<left<<endl;
    return 0;
    
}
