#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n;    
    cin>>n;
    vector<ll>a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<ll>b(n);
    for(int i=0; i<n; i++)
        cin>>b[i];
    vector<ll>c(n);
    
    vector<pair<ll,int>>q(n);
    
    for (ll i=0; i<n; i++)
    {
        ll left = i+1;
        ll right = n-i;
        ll temp = left*right*a[i];
        a[i] = temp;
        q[i] = {temp,i};
    }
    
    sort(q.begin(),q.end());
    
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    
    for (int k=0; k<n; k++)
    {
        int idx = q[k].second;
        c[idx] = b[k];
    }
    
    ll M = 998244353ll;
    ll result = 0;
    
    for (int i=0; i<n; i++)
    {
        ll temp = ((c[i]%M)*(a[i]%M))%M;
        result = (result + temp)%M;
    }
    
    cout<<result<<endl;
    
    return 0;
}
