#include<bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n,k;
    cin>>n>>k;
    
    vector<vector<int>>q(n+1);
    
    for (int i=1; i<=k; i++)
    {
        int x;
        cin>>x;
        q[x].push_back(i);
    }
       
    int result = 0;
    
    for (int i=1; i<=n; i++)
    {
        if (q[i].size()==0)
        {
            result+=1;
            if (i>1)
                result+=1;
            if (i<n)
                result+=1;
        }
            
        else
        {
            if (i>1)
            {
                int t = q[i][0];
                {
                    auto iter = lower_bound(q[i-1].begin(),q[i-1].end(),t);
                    if (iter==q[i-1].end())
                        result++;            
                }
            }
        
            if (i<n)
            {
                int t = q[i][0];
                {
                    auto iter = lower_bound(q[i+1].begin(),q[i+1].end(),t);
                    if (iter==q[i+1].end())
                        result++;            
                }
            }   
        }
               
    }    
    cout<<result<<endl;
    
}
