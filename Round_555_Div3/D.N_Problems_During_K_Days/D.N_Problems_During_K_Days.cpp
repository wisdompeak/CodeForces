// #include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include <bits/stdc++.h>

using namespace std;


void solution(int n, int k)
{
    long long base = (long long)(1+k)*(long long)k/2;

    if (base>n)
    {
        cout<<"NO"<<endl;
        return;
    }

    int additional = (n-base)/k;
    int extra = n-base-additional*k;

    vector<int>result(k);
    for (int i=0; i<k; i++)
        result[i] = i+1+additional;

    int i = k-1;
    while (i>0 && extra>0)
    {
        int temp = min(result[i-1]*2-result[i], extra);
        extra -= temp;
        result[i] += temp;
        i--;
    }

    if (extra>0)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for (auto x:result)
        cout<<x<<" ";
    cout<<endl;

}



int main()
{
    int n;
    cin >> n;
    int k;
    cin>>k;

    solution(n,k);
}
