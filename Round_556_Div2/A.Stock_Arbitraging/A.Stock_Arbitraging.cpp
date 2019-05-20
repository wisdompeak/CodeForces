#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,m,r;
    cin>>n>>m>>r;

    vector<int>buy(n);
    vector<int>sell(m);

    for (int i=0; i<n; i++)
        cin>>buy[i];

    for (int i=0; i<m; i++)
        cin>>sell[i];

    sort(buy.begin(),buy.end());
    sort(sell.begin(),sell.end());
    
    if (sell[m-1]<=buy[0])
        cout<<r<<endl;
    else
    {
        int k = r/buy[0];
        cout<<r-k*buy[0]+k*sell[m-1]<<endl;
    }    
}
