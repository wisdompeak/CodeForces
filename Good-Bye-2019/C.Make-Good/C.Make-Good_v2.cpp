#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int helper(int a, int &carry, int p)
{
    int b = (a+carry)%2;
    int c = p^b;
    if (a+c+carry>1)
        carry = 1;
    else
        carry = 0;
    return c;
}
 
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
    
    //cout<<Sum<<" "<<Xor<<endl;
    if (Sum==Xor*2) return {};
    
    vector<int>a;
    vector<int>b;
    while (Sum>0)
    {
        a.push_back(Sum%2);
        Sum/=2;            
    }
    while (Xor>0)
    {
        b.push_back(Xor%2);
        Xor/=2;            
    }
    
    a.push_back(0);
    a.push_back(0);
    while (a.size()>b.size())
        b.push_back(0);
    
    vector<ll>c;
    int carry = 0;
    int p = 0;
    for (int i=0; i<a.size(); i++)
    {
        int t = helper(a[i],carry,p);
        c.push_back(t);
        p = b[i]^c[i];        
    }
    ll ret = 0;
    for (int i=0; i<c.size(); i++)
        ret += c[i]*(1ll<<i);
    
    return {ret};    
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
        if (x.size()==0)
        {
            cout<<0<<endl;
            cout<<" "<<endl;
        }            
        else
        {
            cout<<1<<endl;
            cout<<x[0]<<endl;
        }
            
    }
}
