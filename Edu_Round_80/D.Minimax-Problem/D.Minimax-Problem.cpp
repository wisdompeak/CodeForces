#include<bits/stdc++.h>
#define ll long long
using namespace std;

int idx1 = -1, idx2 = -1;

bool isOK(vector<vector<int>>&p, int k)
{
    int n = p.size();
    int m = p[0].size();
    
    unordered_set<int>Set;
    unordered_map<int,int>Map;
    for (int i=0; i<n; i++)
    {
        int code = 0;
        for (int j=0; j<m; j++)
        {
            if (p[i][j]>=k)
                code += (1<<j);
        }
        Set.insert(code);
        Map[code] = i;
    }
    
    int target = (1<<m)-1;
    
    vector<int>codes(Set.begin(),Set.end());
    for (int i=0; i<codes.size(); i++)
        for (int j=i; j<codes.size(); j++)
        {
            if ((codes[i] | codes[j]) == target)
            {
                idx1 = Map[codes[i]];
                idx2 = Map[codes[j]];
                return true;
            }
        }
    return false;
}

    
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    auto p = vector<vector<int>>(n,vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>p[i][j];
        
    int low = 0;
    int high = INT_MAX;
    while (low<high)
    {
        int mid = low+(high-low)/2+1;                
        if (isOK(p, mid))
            low = mid;
        else
            high = mid-1;        
    }
    
    isOK(p, low);
    
    cout<<idx1+1<<" "<<idx2+1<<endl;

}
