#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    queue<int>q;
    
    vector<ll>rets;
    map<ll,ll>Map;
    ll ans = 0;
    
    for (int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        q.push(x);
        Map[x] = 0;
    }
    
    while (rets.size()<m)
    {
        int x = q.front();
        q.pop();
        if (Map.find(x-1)==Map.end())
        {
            Map[x-1] = Map[x]+1;
            ans += Map[x-1];
            rets.push_back(x-1);
            q.push(x-1);
        }
        if (rets.size()==m)
            break;
        if (Map.find(x+1)==Map.end())
        {
            Map[x+1] = Map[x]+1;
            ans += Map[x+1];
            rets.push_back(x+1);
            q.push(x+1);
        }        
    }
    
    cout<<ans<<endl;
    
    for (auto x: rets)
        cout<<x<<" ";
    cout<<endl;
}
