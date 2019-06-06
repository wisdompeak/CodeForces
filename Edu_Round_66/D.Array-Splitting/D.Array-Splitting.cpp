#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    
    ll n,k;
    cin>>n>>k;
       
    vector<ll>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];        
    
    vector<ll>cumSum(n);
    cumSum[n-1] = nums[n-1];
    for (int i=n-2; i>=0; i--)
        cumSum[i] = cumSum[i+1]+nums[i];    
        
    sort(cumSum.begin()+1,cumSum.end());
    
    ll result = 1*cumSum[0];    
    for (int i=n-1; i>=n-k+1; i--)    
        result += cumSum[i];
    
    cout<<result<<endl;
}
