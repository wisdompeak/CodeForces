#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

void helper(vector<vector<int>>&results,int i,int j, int n)
{
    if (j<i) return helper(results,j,i,n);
    
    if (j-i>=n/2)
    {
        results.push_back({i,j});        
    }    
    else if (i<=n/2 && j>n/2)
    {
        results.push_back({1,j});
        results.push_back({i,n});
        results.push_back({1,n});
        results.push_back({1,j});
        results.push_back({i,n});
    }
    else if (j<=n/2)
    {
        results.push_back({j,n});
        results.push_back({i,n});
        results.push_back({j,n});
    }
    else if (i>n/2)
    {
        results.push_back({1,i});
        results.push_back({1,j});
        results.push_back({1,i});
    }
}


int main()
{
    int n;
    cin>>n;
    
    vector<int>p(n+1);
    unordered_map<int,int>Map;
    int count = 0;
    for (int i=1; i<=n; i++)
    {
        cin>>p[i];
        Map[p[i]] = i;
        if (p[i]==i) count++;
    }
    
    vector<vector<int>>results;
    
    int i=0;
    while (count<n)
    {
        while (p[i]==i) 
        {
            i++;
            if (i>n) i=1;
        }
        
        int j = Map[i];
        
        helper(results,i,j,n);
        swap(p[i],p[j]);
        Map[i] = i;
        Map[p[j]] = j;
        count++;
        if (p[j]==j) count++;        
    }
    cout<<results.size()<<endl;
    for (auto x:results)
        cout<<x[0]<<" "<<x[1]<<endl;
    
    return 0;

}
