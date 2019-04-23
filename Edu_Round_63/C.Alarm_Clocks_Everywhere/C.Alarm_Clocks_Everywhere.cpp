// #include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
  ll c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}


void solution(int n, int m, vector<ll>events, vector<ll>periods)
{
    vector<ll>gap(n-1);
    for (int i=0; i<n-1; i++)
        gap[i] = events[i+1]-events[i];

    ll GCD = gap[0];
    for (int i=1; i<gap.size(); i++)
        GCD = gcd(GCD,gap[i]);

    for (int i=0; i<m; i++)
        if (GCD%periods[i]==0)
        {
            cout<<"YES"<<endl;
            cout<<events[0]<<" "<<i+1<<endl;
            return;
        }

    cout<<"NO"<<endl;
}


int main()
{
    int n,m;
    cin >> n >>m;

    vector<ll>events(n);
    for (int i=0; i<n; i++)
        cin>>events[i];

    vector<ll>periods(m);
    for (int i=0; i<m; i++)
        cin>>periods[i];

    solution(n, m, events, periods);

}

