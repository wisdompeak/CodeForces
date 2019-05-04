#include<bits/stdc++.h>
#include <iostream>
using namespace std;



int findRoot(vector<int>&root, int a)
{
    if (a!=root[a])
        root[a] = findRoot(root,root[a]);
    return root[a];   
}

void unite(vector<int>&root, vector<int>&size, int a, int b)
{
    a = root[a];
    b = root[b];
    if (a<=b)
    {
        size[a]+=size[b];
        root[b]=a;        
    }        
    else
    {
        size[b]+=size[a];
        root[a]=b;        
    }        
}


int main() {
    int n;
    cin>>n;

    auto Root = vector<vector<int>>(2,vector<int>(n+1,0));
    auto Size = vector<vector<int>>(2,vector<int>(n+1,1));
    
    for (int i=0; i<n-1; i++)
    {
        int a,b,e;
        cin>>a>>b>>e;
        for (int k=0; k<=1; k++)
        {
            if (Root[k][a]==0) Root[k][a] = a;
            if (Root[k][b]==0) Root[k][b] = b;
        }
        
        if (findRoot(Root[e],a)!=findRoot(Root[e],b))
            unite(Root[e], Size[e], a,b);        
    }
    
    long long result = 0;
    for (int i=1; i<=n; i++)    
        result += (long long)Size[1][findRoot(Root[1],i)]*(long long)Size[0][findRoot(Root[0],i)]-1ll;
    
    cout<<result<<endl;
}
