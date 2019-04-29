// #include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include <bits/stdc++.h>

using namespace std;


int solution(int n, int m, int r, vector<int>&buy, vector<int>&sell)
{
    int Sell = *max_element(sell.begin(),sell.end());
    vector<int>Buy;
    for (int x:buy)
        if (x<Sell) Buy.push_back(x);

    vector<int>dp(r+1,0);
    for (int vol=1; vol<=r; vol++)
    {
        auto dp_temp = dp;
        for (int i=0; i<Buy.size(); i++)
        {
            if (vol-Buy[i]<0) continue;
            dp[vol] = max(dp[vol], dp_temp[vol-Buy[i]]+Sell-Buy[i]);
        }
    }

    int result = 0;
    for (int v=1; v<=r; v++)
        result = max(result, dp[v]+r);
    return result;

}


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

    cout<<solution(n,m,r,buy,sell)<<endl;

}

