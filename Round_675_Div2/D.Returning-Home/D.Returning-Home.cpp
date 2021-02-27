#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;

typedef long long LL;
typedef array<int,3> AI3;
typedef pair<int,int> PII;
int n,m;
int visited[100005];
vector<PII> adj[100005];

static bool cmp2(AI3 a, AI3 b)
{
    return a[1] < b[1];
}

int dist(AI3 a, AI3 b)
{
    return min(abs(a[0]-b[0]), abs(a[1]-b[1]));
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin>>n>>m;
    int sx,sy,fx,fy;
    cin>>sx>>sy>>fx>>fy;    
    sx--; sy--; fx--; fy--;
    
    vector<AI3>nodes;    
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        nodes.push_back({x-1, y-1, i});
    }    
    
    sort(nodes.begin(), nodes.end());
    for (int i=0; i<m-1; i++)
    {
        int d = dist(nodes[i], nodes[i+1]);
        adj[nodes[i][2]].push_back({nodes[i+1][2], d});
        adj[nodes[i+1][2]].push_back({nodes[i][2], d});
    }
    
    sort(nodes.begin(), nodes.end(), cmp2);
    for (int i=0; i<m-1; i++)
    {
        int d = dist(nodes[i], nodes[i+1]);
        adj[nodes[i][2]].push_back({nodes[i+1][2], d});
        adj[nodes[i+1][2]].push_back({nodes[i][2], d});
    }
    
    for (int i=0; i<m; i++)
    {
        int d = min(abs(nodes[i][0]-sx), abs(nodes[i][1]-sy));
        adj[0].push_back({nodes[i][2],d});
    }
    adj[0].push_back({m+1, abs(sx-fx)+abs(sy-fy)});       
    
    for (int i=0; i<m; i++)
    {
        int d = abs(nodes[i][0]-fx)+abs(nodes[i][1]-fy);
        adj[nodes[i][2]].push_back({m+1,d});
    }
    
    priority_queue<PII, vector<PII>, greater<>>pq;
    pq.push({0, 0});
        
    while (!pq.empty())
    {
        auto [d, cur] = pq.top();
        pq.pop();
        if (visited[cur]) continue;
        visited[cur]=1;
        
        if (cur==m+1)
        {
            cout<<d<<endl;
            break;
        }
        
        for (auto [nxt, edge]: adj[cur])
        {
            if (visited[nxt]) continue;
            pq.push({d+edge, nxt});            
        }
    }
}
