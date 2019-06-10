#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin>>n;
    vector<ll>degree(n+1,0);
    for (int i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        degree[a]++;
        degree[b]++;
    }
    
    ll result=n;
    ll M = 998244353;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=degree[i]; j++)
            result = result*j%M;
    }
    cout<<result<<endl;
    return 0;
}
