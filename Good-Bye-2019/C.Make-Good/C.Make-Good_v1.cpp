#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
vector<ll> solve()
{
    int n;
    cin>>n;
    ll Sum = 0;
    ll Xor = 0;
    for (int i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        Sum += x;
        Xor ^= x;
    }
        
    return {Xor,Sum+Xor};    
}
 
int main() 
{
    int T;
    cin>>T;
    vector<vector<ll>>rets;
    for (int t=0; t<T; t++)
    {
        rets.push_back(solve());
    }
    for (auto x:rets)
    {
        cout<<2<<endl;
        cout<<x[0]<<" "<<x[1]<<endl;            
    }
}
