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
    int T;
    cin >> T;
    
    for (int i=0; i<T; i++)
    {
        ll a,b,m;
        cin>>a>>b>>m;
        
        if (a==b)
        {
            cout<<1<<" "<<a<<endl;
            continue;
        }
        
        int n = -1;
        for (int k=2; k<50; k++)
        {
            if (((a+1)<<(k-2))<=b && ((a+m)<<(k-2))>=b)
            {
                n = k;
                break;
            }
            if (((a+m)<<(k-2))>b)
                break;
        }
        
        if (n==-1)
        {
            cout<<-1<<endl;
            continue;
        }
        
        ll c = b-(a<<(n-2))-(1ll<<(n-2));
        
        vector<ll>r(n+1);
        
        cout<<n<<" ";        
        cout<<a<<" ";
        ll sum = a;
        for (int k=2; k<=n-1; k++)
        {
            r[k] = min(m-1,c/(1ll<<(n-k-1)));               
            c = c-r[k]*(1ll<<(n-k-1));
            ll x = sum+r[k]+1;
            sum += x;
            cout<<x<<" ";
        }
        cout<<b<<endl;
    }
    
}
