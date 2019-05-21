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
    map<pair<int,int>,set<int>> mp;
    
    int n;    
	cin>>n;
    vector<int>x(n+1);
    vector<int>y(n+1);
	for(int i=1;i<=n;++i) 
        cin>>x[i]>>y[i];
    
	for(int i=1;i<=n;++i) 
        for(int j=i+1;j<=n;++j)
        {
		    int dy = y[i] - y[j], dx = x[i] - x[j];
		    int mx = dx/__gcd(dy,dx), my = dy/__gcd(dy,dx);
		    mp[{my,mx}].insert(x[i]*my-y[i]*mx);
	    }

    ll ans=0, sum=0;
	for(auto line:mp)
		ans += line.second.size()*sum,
		sum += line.second.size();
    
	cout<<ans;
}
