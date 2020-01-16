#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() 
{    
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    unordered_set<int>Set; // persons who do not receive gifts
    
    for (int i=1; i<=n; i++)
        Set.insert(i);
        
    vector<int>f(n+1,0);
    for (int i=1; i<=n; i++)
    {
        cin>>f[i];
        if (f[i]!=0) Set.erase(f[i]);
    }
    
    for (int i=1; i<=n; i++)
    {
        if (f[i]!=0) continue;
        for (auto x:Set)
        {
            if (x!=i)
            {
                Set.erase(x);
                f[i] = x;
                break;
            }
        }
        if (f[i]==0)
        {
            f[i] = i;
            swap(f[i], f[1]);
        }
    }
        
    for (int i=1; i<=n; i++)
        cout<<f[i]<<" ";
    cout<<endl;
}
