#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll computeArea2(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) 
{
        ll l = max(x1, x3);    // left
        ll r = min(x2, x4);    // right
        ll u = min(y2, y4);    // up
        ll b = max(y1, y3);    // bottom
        // no intersection
        if (l>r||b>u) return 0;        
        return (r-l)*(u-b);
}    

ll computeArea3(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4, ll x5, ll y5, ll x6, ll y6) 
{
        ll l = max(max(x1, x3), x5);    // left
        ll r = min(min(x2, x4), x6);    // right
        ll u = min(min(y2, y4), y6);    // up
        ll b = max(max(y1, y3), y5);    // bottom
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
    ll AO = computeArea2(x1,y1,x2,y2,x3,y3,x4,y4);
    ll BO = computeArea2(x1,y1,x2,y2,x5,y5,x6,y6);
    ll ABO = computeArea3(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6);       
    
    if (AO+BO-ABO < abs(x2-x1)*abs(y2-y1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}
