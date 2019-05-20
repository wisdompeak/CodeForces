//#include <QCoreApplication>
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
    ll n,x;
    cin >> n >>x;

    vector<ll>lastAppear(x+2,0);
    vector<ll>firstAppear(x+2,n+1);
    vector<ll>lastAppearGroup(x+2,0);
    vector<bool>exist(x+2,0);
    
    vector<ll>nums(n+1);
    for (int i=1; i<=n; i++)
    {
        cin>>nums[i];
        exist[nums[i]]=true;
    }
    
    for (ll i=1; i<=n; i++)
    {
        lastAppear[nums[i]] = max(lastAppear[nums[i]], i);
        firstAppear[nums[i]] = min(firstAppear[nums[i]], i);
    }
    
    for (ll k=1; k<=x; k++)
    {
        // the last postion for all numbers of [1..k]
        lastAppearGroup[k] = max(lastAppearGroup[k-1],lastAppear[k]);
    }           
    
    ll a = x;  // the upper limit of left
   
    for (ll k=2; k<=x; k++)
    {
        if (firstAppear[k] < lastAppearGroup[k-1])
        {
            a = k;
            break;
        }
    }    
    // cout<<"a = "<<a<<endl;
    
    ll result = 0;
    ll b = x;
    ll curEarliest = n+1;
    while (a>=1)
    {
        // now consider left = a        
        while (b>a && (!exist[b] || lastAppear[b]<curEarliest && firstAppear[b]>lastAppearGroup[a-1]))
        {
            // it means we could save b
            if (exist[b]) curEarliest = firstAppear[b];
            b--;
        }                    
        //cout<<a<<"->"<<b<<endl;        
        result += x-b+1;  // we can make right within [b,x]               
        a--;
    }    
    cout<<result<<endl;        
}
