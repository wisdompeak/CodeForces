#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 3e5+5;
 
int h[M];
int p[M];
 
ll helper(int h1, int h2, int h3, ll a, ll b, ll c, int h)
{
    ll MIN = 2e18;
    if (h1!=h)
        MIN = min(MIN,a);
    if (h2!=h)
        MIN = min(MIN,b);
    if (h3!=h)
        MIN = min(MIN,c);
    return MIN;    
}
 
int main() {
    
    int q;
    cin>>q;
    while (q--)
    {
        int n;
        scanf("%d",&n);
        
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",h+i,p+i);
        }
        
        ll a = 0;
        ll b = p[0];
        ll c = p[0]*2;
        
        for (int i=1; i<n; i++)
        {
            //cout<<i<<endl;
            
            ll a_new = helper(h[i-1],h[i-1]+1,h[i-1]+2,a,b,c,h[i])+0;
            ll b_new = helper(h[i-1],h[i-1]+1,h[i-1]+2,a,b,c,h[i]+1)+p[i]*1;
            ll c_new = helper(h[i-1],h[i-1]+1,h[i-1]+2,a,b,c,h[i]+2)+p[i]*2;
            a = a_new;
            b = b_new;
            c = c_new;
        }
        cout<<min(a,min(b,c))<<endl;
    }
    
    return 0;
}
