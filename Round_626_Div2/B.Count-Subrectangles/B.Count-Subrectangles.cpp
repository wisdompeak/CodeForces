#include<bits/stdc++.h>
#define ll long long
using namespace std;
    
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n);
    vector<int>b(m);
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<m; i++)
        cin>>b[i];
    
    vector<ll>A;
    for (int i=0; i<n; i++)
    {
        if (a[i]==0) continue;
        int j=i;
        while (j<n && a[j]==1)
            j++;
        A.push_back(j-i);
        i = j-1;
    }
    
    vector<ll>B;
    for (int i=0; i<m; i++)
    {
        if (b[i]==0) continue;        
        int j=i;
        while (j<m && b[j]==1)
            j++;
        B.push_back(j-i);
        i = j-1;
    }
    
    ll ret = 0;

    for (int x=1; x*x<=k; x++)
    {
        if (k%x!=0) continue;
        
        ll count1 = 0, count2 = 0;
        for (auto a: A)
            count1+=max(0ll, a-x+1);
        for (auto b: B)
            count2+=max(0ll, b-k/x+1);
        ret += count1*count2;
        
        if (x*x==k) continue;
        
        count1 = 0, count2 = 0;
        for (auto a: A)
            count1+=max(0ll, a-k/x+1);
        for (auto b: B)
            count2+=max(0ll, b-x+1);        
        ret += count1*count2;   
    }
    
    cout<<ret<<endl;
    
}
