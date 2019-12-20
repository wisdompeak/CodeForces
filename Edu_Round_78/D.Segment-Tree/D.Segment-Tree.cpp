#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
 
vector<int>Father;
 
int FindFather(int i)
{
    if (Father[i]!=i)
        Father[i] = FindFather(Father[i]);
    return Father[i];
}
 
void Union(int i, int j)
{
    i = Father[i];
    j = Father[j];
    if (i<j)
        Father[j] = i;
    else
        Father[i] = j;
}
 
int main() {
    int n;
    cin>>n;
    vector<vector<int>>p;
    for (int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end());
 
    Father.resize(n);
    for (int i=0; i<n; i++)
        Father[i] = i;
 
    map<int,int>Map;
    for (int i=0; i<n; i++)
    {
        int flag = 0;
        for (auto iter = Map.upper_bound(p[i][0]); iter!=Map.end() && iter->first < p[i][1]; iter++)
        {
            int j = iter->second;
            if (FindFather(j)!=FindFather(i))            
            {
                Union(i,j);
            }                
            else
            {
                //cout<<"E:"<<i<<" "<<j<<endl;
                flag = 1;
                break;
            }
        }
        if (flag==1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        Map[p[i][1]] = i;
    }
 
    unordered_set<int>Set;
    for (int i=0; i<n; i++)
    {
        int root = FindFather(i);
        Set.insert(root);
        if (Set.size()>1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
 
    cout<<"YES"<<endl;
    return 0;    
}
