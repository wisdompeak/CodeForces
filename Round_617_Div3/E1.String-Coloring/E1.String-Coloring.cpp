#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
 
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
 
 
void solve(int n, string& s)
{
    string s1, s2;
    string ret;
    for (int i=0; i<n; i++)
    {
        if (s1=="" || s1.back()<=s[i])
        {
            s1.push_back(s[i]);
            ret.push_back('0');
        }            
        else if (s2=="" || s2.back()<=s[i])
        {
            s2.push_back(s[i]);
            ret.push_back('1');
        }            
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    cout<<ret<<endl;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    solve(n,s);
}
