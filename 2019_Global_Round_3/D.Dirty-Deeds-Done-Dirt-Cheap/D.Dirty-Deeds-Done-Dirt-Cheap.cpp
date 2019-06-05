#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    
    vector<pair<int,int>>p1;
    vector<pair<int,int>>p2;
    
    for (int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        if (x<y)
            p1.push_back({y,i});
        else
            p2.push_back({y,i});
    }
        
    if (p1.size()>p2.size())
    {
        sort(p1.begin(),p1.end());        
        cout<<p1.size()<<endl;        
        for (int i=p1.size()-1; i>=0; i--)
            cout<<p1[i].second<<" ";
        cout<<endl;
    }
    else
    {
        sort(p2.begin(),p2.end());
        cout<<p2.size()<<endl;        
        for (auto x:p2)
            cout<<x.second<<" ";
        cout<<endl;
    }
    return 0;

}
