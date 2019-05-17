#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    
    vector<int>q({4 , 8, 15, 16, 23, 42});
    unordered_map<int,unordered_set<int>>Map;
    for (int i=0; i<q.size(); i++)
        for (int j=i+1; j<q.size(); j++)
            Map[q[i]*q[j]]={q[i],q[j]};
    
    int x,y;
    cout<<"? "<<1<<" "<<2<<endl;
    fflush(stdout);
    cin>>x;
    
    
    cout<<"? "<<2<<" "<<3<<endl;
    fflush(stdout);
    cin>>y;
    
    unordered_set<int>Set1 = Map[x];
    unordered_set<int>Set2 = Map[y];
    vector<int>result;
    
    int a = *Set1.begin();
    {
        if (Set2.find(a)==Set2.end())
        {
            result.push_back(a);
            result.push_back(x/a);
            result.push_back(y/(x/a));
        }
        else
        {
            result.push_back(x/a);
            result.push_back(a);
            result.push_back(y/a);
        }            
    }
    
    cout<<"? "<<4<<" "<<5<<endl;
    fflush(stdout);
    cin>>x;
    
    cout<<"? "<<5<<" "<<6<<endl;
    fflush(stdout);
    cin>>y;
    
    Set1 = Map[x];
    Set2 = Map[y];
    
    a = *Set1.begin();
    {
        if (Set2.find(a)==Set2.end())
        {
            result.push_back(a);
            result.push_back(x/a);
            result.push_back(y/(x/a));
        }
        else
        {
            result.push_back(x/a);
            result.push_back(a);
            result.push_back(y/a);
        }            
    }
        
    cout<<"! ";
    for (int i=0; i<6; i++)
        cout<<result[i]<<" ";
    cout<<endl;
            
    
    return 0;
}
