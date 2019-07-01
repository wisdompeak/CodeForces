#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>>graph;
vector<int>children;
int n;
ll total;
ll result;

void dfs(int x, int father)
{
    children[x] = 1;
    for (auto u: graph[x])
    {
        if (u==father) continue;
        dfs(u,x);
        children[x]+=children[u];
    }
    total += children[x];
}

void dfs2(int x, int father, ll total)
{
    result = max(result, total);
    for (auto u: graph[x])
    {
        if (u==father) continue;
        dfs2(u,x,total+(n-children[u])-children[u]);
    }
}


int main() {    
    cin>>n;
    graph.resize(n+1);
    children.resize(n+1);
    
    int x,y;
    for (int i=0; i<n-1; i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    dfs(1,0);
    dfs2(1,0,total);
    cout<<result<<endl;
}
