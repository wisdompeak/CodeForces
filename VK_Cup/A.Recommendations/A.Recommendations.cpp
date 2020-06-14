#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
 
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
ll solve(vector<pair<int,int>>p, int n)    
{
    sort(p.begin(), p.end());
    ll ret = 0;
    ll sum = 0;
    int idx = 0;
    multiset<ll>Set;
    int num = 0;
    
    while(!Set.empty() || idx < n)
    {
        if (idx == 0) num = p[0].first;
        
        while (idx < n && p[idx].first==num)
        {            
            Set.insert(p[idx].second);
            sum += p[idx].second;
            idx += 1;
        }
        if (!Set.empty())
        {
            int mx = *(Set.rbegin());
            Set.erase(Set.find(mx));
            sum -= mx;
            ret += sum;
        }
        num += 1;
    }
    
    return ret;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>c(n);
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>c[i];
    vector<pair<int,int>>p(n);
    for (int i=0; i<n; i++)
        p[i] = {a[i], c[i]};
    
    
    cout<<solve(p,n)<<endl;
}
