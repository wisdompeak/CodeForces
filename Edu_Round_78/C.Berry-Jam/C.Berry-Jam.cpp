#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
ll solve()
{
    int n;
    cin>>n;
    vector<int>p(n);
    vector<int>q(n);
    for (int i=0; i<n; i++)
        cin>>p[i];
    for (int i=0; i<n; i++)
        cin>>q[i];
    
    int diff = 0;
    unordered_map<int,int>Map;
    Map[0]=0;
    for (int i=0; i<n; i++)
    {
        if (p[i]==1)
            diff++;
        else
            diff--;
        Map[diff] = i+1;
    }
    
    int ret = n + n-Map[0];
    diff = 0;    
    for (int i = n-1; i>=0; i--)
    {
        if (q[i]==1)
            diff++;
        else 
            diff--;
        
        if (Map.find(-diff)!=Map.end())
            ret = min(ret, i+n-Map[-diff]);        
    }
    return ret;
}
 
 
int main() {
    int T;
    cin>>T;
    vector<int>rets;
    for (int t=0; t<T; t++)
    {
        rets.push_back(solve());
    }
    for (auto x: rets)
    {
        cout<<x<<endl;
    }        
}
