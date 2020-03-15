#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<int,vector<int>>Map;
vector<int>color;
vector<int>dp;
vector<int>visited;
vector<int>ret;

int DFS(int cur)
{    
    dp[cur] = color[cur]==1?1:-1;
    for (int next: Map[cur])
    {
        if (visited[next]==1) continue;
        visited[next] = 1;
        dp[cur] += max(0, DFS(next));
    }
    return dp[cur];
}

void DFS2(int cur)
{
    for (int next: Map[cur])
    {
        if (visited[next]==1) continue;
        visited[next] = 1;
        int cur_tmp = dp[cur];
        int next_tmp = dp[next];
        dp[cur] = dp[cur] - max(0,dp[next]);
        dp[next] = dp[next] + max(0, dp[cur]);
        ret[next] = dp[next];
        
        DFS2(next);
        
        dp[cur] = cur_tmp;
        dp[next] = next_tmp;        
    }
}
    
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    color.resize(n+1);
    dp.resize(n+1);
    visited.resize(n+1);    
    ret.resize(n+1);    
    
    for (int i=1; i<=n; i++)    
        cin>>color[i];
        
    for (int i=1; i<=n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        Map[a].push_back(b);
        Map[b].push_back(a);
    }
    
    visited[1] = 1;
    ret[1] = DFS(1);
        
    for (int i=2; i<=n; i++)
        visited[i] = 0;
    DFS2(1);
    
    for (int i=1; i<=n; i++)
        cout<<ret[i]<<" ";
    cout<<endl;
    

}
