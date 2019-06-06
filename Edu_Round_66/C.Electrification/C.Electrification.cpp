#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin>>T;
    
    for (int t=0; t<T; t++)
    {
        ll n, k;
        cin>>n>>k;
        
        vector<ll>q(n);
        for (int i=0; i<n; i++)
            cin>>q[i];
        
        k++;
        
        if (k==1)
        {
            cout<<q[0]<<endl;
            continue;
        }
            
        ll len = INT_MAX;
        ll x;
        for (int i=k-1; i<n; i++)
        {
            if (q[i]-q[i-k+1]<len)
            {
                len = q[i]-q[i-k+1];
                x = (q[i]+q[i-k+1])/2;
            }
        }
        
        cout<<x<<endl;
    }
    
}
