#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long

int helper(ll t, int count1, int count2, int total1, int total2, ll a, ll b)
{
    int count = 0;
    if (t < count1*a+count2*b)
        return count;
    
    t -= count1*a+count2*b;
    count += count1+count2;
    
    if (t < (total1-count1)*a)
    {
        count += t/a;
        return count;
    }
    else
    {
        count += total1-count1;
        t -= (total1-count1)*a;
    }
    
    if (t < (total2-count2)*b)
    {
        count += t/b;
        return count;
    }
    else
    {
        count += total2-count2;
        return count;
    }
}


int solve()
{
    ll n,T,a,b;
    cin>>n>>T>>a>>b;
    vector<int>hard(n,0);
    vector<int>time(n,0);
    ll total1 = 0, total2 = 0;
    
    for (int i=0; i<n; i++)
    {
        cin>>hard[i];
        if (!hard[i])
            total1+=1;
        else
            total2+=1;
    }
        
    for (int i=0; i<n; i++)
        cin>>time[i];
    
    vector<vector<int>>p;
    for (int i=0; i<n; i++)    
        p.push_back({time[i],hard[i]});    
    sort(p.begin(),p.end());    
    
    int count1 = 0;
    int count2 = 0;       
    int ret = 0;
    
    for (int i=0; i<n; i++)
    {        
        if (p[i][0]-1>T) break;
        
        if (i>0 && p[i-1][1]==0)
            count1 += 1;
        else if (i>0 && p[i-1][1]==1)
            count2 += 1;
        ll t = p[i][0]-1;
        
        int count = helper(t, count1, count2, total1, total2, a, b);        
        ret = max(ret, count);        
    }
    
    if (T>p.back()[0]-1)    
        ret = max(ret, helper(T,total1,total2,total1, total2, a, b));

    return ret;
}

int main() 
{
    int T;
    cin>>T;
    vector<int>rets(T);
    for (int t=0; t<T; t++)
    {
        rets[t] = solve();
    }
    for (auto x:rets)
        cout<<x<<endl;
}
