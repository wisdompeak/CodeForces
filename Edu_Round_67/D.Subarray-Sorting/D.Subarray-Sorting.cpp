// #include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


void solve()
{
    int n;
    cin>>n;

    vector<int>bitArr(n+1, 0);

    vector<pair<int,int>>a(n+1);
    vector<pair<int,int>>b(n+1);

    for (int i=1; i<=n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }

    for (int i=1; i<=n; i++){
        cin>>b[i].first;
        b[i].second = i;
    }

    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());

    for (int i=1; i<=n; i++){
        if (a[i].first!=b[i].first){
            cout<<"NO"<<endl;
            return;
        }
    }

    for (int i=1; i<=n; i++){
        int pa = a[i].second;
        int pb = b[i].second;

        int r = 0;
        for (int j=pa; j; j-=j&(-j)){
            r = max(r, bitArr[j]);
        }

        if (r>pb){
            cout<<"NO"<<endl;
            return;
        }

        for (int j=pa; j<=n; j+=j&(-j)){
            bitArr[j] = max(bitArr[j], pb);
        }

    }

    cout<<"YES"<<endl;
    return;
}


int main()
{
    int T;
    cin>>T;

    for (int i=0; i<T; i++)
        solve();

    return 0;
}

