#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
    
    map<int,unordered_set<int>>Map;
    unordered_map<int,int>counter;
    
    int result = 0;
    for (int i=0; i<n; i++)
    {
        int x = nums[i];
        int k = counter[x];
        if (k==0)
        {
            counter[x] = 1;
            Map[1].insert(x);
        }
        else
        {
            counter[x]++;
            Map[k].erase(x);
            if (Map[k].size()==0)
                Map.erase(k);
            Map[k+1].insert(x);
        }
        
        if (Map.size()==2 && Map.begin()->first+1==Map.rbegin()->first && Map.rbegin()->second.size()==1)
            result = max(result,i+1);  
        if (Map.size()==2 && Map.begin()->first==1 && Map.begin()->second.size()==1)
            result = max(result,i+1);  
        if (Map.size()==1 && Map.begin()->first==1)
            result = max(result,i+1);  
        if (Map.size()==1 && Map.begin()->second.size()==1)
            result = max(result,i+1);  
    }
    
    cout<<result<<endl;
    
    
}
