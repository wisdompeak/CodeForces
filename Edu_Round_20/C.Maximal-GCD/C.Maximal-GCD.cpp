#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
bool check(ll d, ll n, ll k)
{
    return k*(k+1) <= n*2ll / d ;
}
 
int main() {
    ll n,k;
    cin>>n>>k;
    
    if (k==1)
    {
        cout<<n<<endl;
        return 0;
    } 
    if ((1+k) > n * 2ll / k)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    set<ll>Set;
    
    for (ll d=sqrt(n); d>=1; d--)
    {
        if (n%d==0)
        {
            Set.insert(d);
            Set.insert(n/d);
        }
    }
    
    int D = 0;
    for (auto x:Set)
    {
        ll d = n/x;
        
        if (check(d,n,k))
        {
            D = d;
            break;
        }            
    }
    
    
    if (D==0)
        cout<<"-1"<<endl;
    else    
    {
        for (int i=1; i<=k-1; i++)
           cout<<i*D<<" ";
        cout<< n - k*(k-1)/2*D;
    }
       
    return 0;
}
