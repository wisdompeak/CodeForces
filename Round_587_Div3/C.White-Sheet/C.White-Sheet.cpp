#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 3e5+5;
 
struct Rect
{
    ll x;
    ll y;
    ll w;
    ll h;
};
 
 
bool IsCross(const Rect &r1,const Rect &r2)
{
    if(r1.x + r1.w < r2.x || r2.x + r2.w < r1.x || r1.y + r1.h < r2.y || r2.y + r2.h < r1. y)
        return false;
    else
        return true;
}
 
Rect CrossRect(const Rect &r1,const Rect &r2)
{
    Rect r;
    ll max_x = max(r1.x,r2.x);
    ll max_y = max(r1.y,r2.y);
    ll min_x = min(r1.x+r1.w,r2.x+r2.w);
    ll min_y = min(r1.y+r1.h,r2.y+r2.h);
    r.x = max_x;
    r.y = max_y;
    r.w = min_x - max_x;
    r.h = min_y - max_y;
    return r;
}
 
 
Rect IntersectRect(const Rect &rectA,const Rect &rectB,const Rect &rectC)
{
    Rect ans;
    //先判断没有相交的情况
    if(! ( IsCross(rectA,rectB) && IsCross(rectA,rectC) && IsCross(rectB,rectC) ) )
    {
        ans.x = -1;
        ans.y = -1;
        ans.w = -1;
        ans.h = -1;
        return ans;
    }
    else
    //有相交的情况
    {
        ans = CrossRect(rectA,rectB);
        return CrossRect(ans,rectC);
    } 
}
 
 
ll computeArea(ll A, ll B, ll C, ll D, ll E, ll F, ll G, ll H) 
{
        long long l = max(A, E);    // left
        long long r = min(C, G);    // right
        long long u = min(D, H);    // up
        long long b = max(B, F);    // bottom
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
    
    ll AO = computeArea(x1,y1,x2,y2,x3,y3,x4,y4);
    ll BO = computeArea(x1,y1,x2,y2,x5,y5,x6,y6);
    ll ABO;
    
    Rect A = {x1,y1,x2-x1,y2-y1};
    Rect B = {x3,y3,x4-x3,y4-y3};
    Rect C = {x5,y5,x6-x5,y6-y5};
    Rect res = IntersectRect(A,B,C);
    if (res.w==-1)
        ABO = 0;
    else
        ABO = res.w*res.h;
    
    if (AO+BO-ABO < abs(x2-x1)*abs(y2-y1))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
    
    
}
