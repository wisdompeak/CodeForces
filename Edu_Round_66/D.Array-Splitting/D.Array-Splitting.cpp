#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    
    ll n,k;
    cin>>n>>k;
       
    vector<ll>cumSum(n+1,0);
    for (int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        cumSum[i] = cumSum[i-1]+x;
    }
    
    ll result = cumSum[n]*k;
    
    sort(cumSum.begin()+1,cumSum.end()-1);
    
    for (int i=1; i<=k-1; i++)    
        result -= cumSum[i];
        
    cout<<result<<endl;
