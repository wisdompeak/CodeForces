#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll computeArea(ll A, ll B, ll C, ll D, ll E, ll F, ll G, ll H, ll& l, ll&b, ll&r, ll&u) 
{
        l = max(A, E);    // left
        r = min(C, G);    // right
        u = min(D, H);    // up
        b = max(B, F);    // bottom
        // no intersection
        if (l>r||b>u) return 0;        
        return (r-l)*(u-b);
}    
    
int main() {
    ll x1,y1,x2,y2;
    ll x3,y3,x4,y4;
    ll x5,y5,x6,y6;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;
    
    ll l,b,r,u;
    ll AO = computeArea(x1,y1,x2,y2,x3,y3,x4,y4,l,b,r,u);
    ll BO = computeArea(x1,y1,x2,y2,x5,y5,x6,y6,l,b,r,u);
        
    ll t1,t2,t3,t4;
    ll ABO = (BO==0)? 0 : computeArea(l,b,r,u,x3,y3,x4,y4,t1,t2,t3,t4);
    
    if (AO+BO-ABO < abs(x2-x1)*abs(y2-y1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}
