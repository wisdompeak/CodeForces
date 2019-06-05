#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;


int main()
{
    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    
    vector<ll>a(n);
    vector<ll>b(m);
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]+=ta;
    }
        
    for (int i=0; i<m; i++)
        cin>>b[i];
    
    if (n<=k || m<=k)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int j = 0;
    ll result = 0;
    for (int i=0; i<=k; i++)
    {        
        while (j<m && b[j]<a[i]) j++;
        if (j+k-i>=m)
        {
            cout<<-1<<endl;
            return 0;
        }
        else
        {
            result = max(result,b[j+k-i]+tb);
        }
    }
    
    cout<<result<<endl;
    return 0;

}
