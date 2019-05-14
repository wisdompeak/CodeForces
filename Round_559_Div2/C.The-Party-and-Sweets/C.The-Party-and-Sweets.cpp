#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n,m;    
    cin>>n>>m;
    
    vector<ll>a(n);
    for (int i=0; i<n; i++)
        cin>>a[i];
    
    vector<ll>b(m);
    for (int i=0; i<m; i++)
        cin>>b[i];
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
   
    if (a.back()>b[0])
    {
        cout<<-1<<endl;
        return 0;
    }
    
    ll result = 0;
    int j = m-1;
    
    for (int i=n-1; i>=0; i--)
    {
    	result+=m*a[i];
    	while (j>=0 && a[i]<=b[j])
    	{
    		result+=b[j]-a[i];
    		j--;
    	}
        if (i==n-1 && j+1<m && a[i]<b[j+1])
        {
            j++;
            result-=b[j]-a[i];
        }
    }

    if (j>=0)
    	cout<<-1<<endl;
    else        
    	cout<<result<<endl;    
}
