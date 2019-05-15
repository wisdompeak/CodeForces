#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int total;

bool isOK(int l, vector<int>&need, unordered_map<int,vector<int>>&daySale)
{
    vector<int>bought(need.size(),0);
    
    int money = l;
    int spent = 0;
    
    for (int i=l; i>=1; i--)
    {
        if (money>i) money--;
        
        for (auto item: daySale[i])
        {
            int spend = min(money, need[item]-bought[item]);
            money -= spend;
            bought[item] += spend;
            spent += spend;            
        }        
    }    
    
    return l-spent >= 2*(total-spent);
}

int main() {
    int n,m;    
    cin>>n>>m;
    
    vector<int>need(n+1);
    for (int i=1; i<=n; i++)
        cin>>need[i];
        
    unordered_map<int,vector<int>>daySale;
    for (int i=0; i<m; i++)    
    {
        int d,t;
        cin>>d>>t;
        daySale[d].push_back(t);
    }
    
    total = accumulate(need.begin(),need.end(),0);
    
    int left = 0;
    int right = total*2;

    while (left<right)
    {
        int mid = (right-left)/2+left;
        if (!isOK(mid,need,daySale))
            left = mid+1;
        else
            right = mid;
    }
    
    cout<<left<<endl;
}
