#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<pair<int,int>>>& next, vector<int>&visited, vector<int>& color)
{
    visited[start] = 1;
    
    for (auto x: next[start])
    {
        int nextNode = x.first;
        int id = x.second;
        
        if (visited[nextNode]==1)
        {
            color[id] = 2;
        }
        else if (visited[nextNode]==2)
        {
            color[id] = 1;
        }
        else
        {  
            color[id] = 1;
            dfs(nextNode, next, visited, color);
        }
    }
    
    visited[start] = 2;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>next(n+1);
    for (int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        next[a].push_back({b,i});
    }
    
    vector<int>visited(n+1);
    vector<int>color(m+1);
    
    for (int i=1; i<=n; i++)
    {
        if (visited[i]==0)
            dfs(i, next, visited, color);
    }
    
    int num = 1;
    for (int i=1; i<=m; i++)
        if (color[i]==2)
        {
            num = 2;
            break;
        }
        
    cout<<num<<endl;
    for (int i=1; i<=m; i++)
        cout<<color[i]<<" ";
    
    return 0;
}
