#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
 
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
vector<int>visited;
vector<long>rets;
vector<set<int>>children;
long M = 998244353;
 
ll solve(ll n, int m, vector<int>box)
{       
    ll sum = 0;
    vector<int>power(61,0);
    for (int i=0; i<m; i++)
    {
        int p = int(log2(box[i]));
        power[p]+=1;
        sum += box[i];
    }    
    if (sum<n) return -1;
    
    int ret = 0;
    
    int i = 0;
    while (i<60)
    {
        if (((1ll<<i)&n)==0)
        {
            power[i+1] += power[i]/2;            
        }
        else
        {
            if (power[i] > 0)
            {
                power[i] -= 1;
                power[i+1] += power[i]/2;                
            }
            else
            {
                int j = i;
                while (j<60 && power[j]==0)
                {                    
                    power[j] = 1;
                    ret++;
                    j++;
                }
                power[j]-=1;                
            }
        }
        i++;
    }
    
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int T;
    cin>>T;
    vector<ll>rets(T+1,0);
    
    for (int t=1; t<=T; t++)
    {
        ll n;
        int m;
        cin>>n>>m;
        vector<int>box(m);
        for (int i=0; i<m; i++)
            cin>>box[i];
        rets[t] = solve(n, m, box);        
    }
    
    for (int t=1; t<=T; t++)
        cout<<rets[t]<<endl;
}
