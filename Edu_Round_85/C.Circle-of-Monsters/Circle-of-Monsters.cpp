#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
 
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
 
 
ll solve(int N, vector<ll>&a, vector<ll>&b)
{
    vector<ll>c(N);
    ll total = 0;
    for (int i=0; i<N; i++)
    {
        c[i] = max(0ll, a[i] - b[(i-1+N)%N]);
        total += c[i];
    }
    
    ll ret = total-c[0]+a[0];
    for (int i=1; i<N; i++)
    {
        ret = min(ret, total - c[i] + a[i]);
    }
    
    return ret;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    vector<ll>results;
 
    for (int t=0; t<T; t++)
    {
        int N;
        cin>>N;
        vector<ll>a(N);
        vector<ll>b(N);
        for (int i=0; i<N; i++)
        {
            cin>>a[i];
            cin>>b[i];
        }
        results.push_back(solve(N,a,b));
    }
 
    for (int t=0; t<T; t++)
    {        
        cout<<results[t]<<endl;    
    }
}
