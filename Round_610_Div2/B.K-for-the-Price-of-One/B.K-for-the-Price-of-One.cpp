#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long

bool OK(vector<int>&a, int i, int p, int k)
{
    while (i>=k-1 && p>=a[i])
    {
        p-=a[i];
        i-=k;
    }
    return (i<0 && p>=0)||(i==0 && p>=a[0]);
}


int solve()
{
    int n,p,k;
    cin>>n>>p>>k;
    vector<int>a(n+1,0);
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    
    int sum0 = 0;
    int ret = 0;
    for (int i=0; i<=k-1; i++)
    {
        sum0 += a[i];
        if (sum0>p) break;
        int left = p - sum0;
        int j = i;
        while (j+k<=n && left>=a[j+k])
        {
            left-=a[j+k];
            j+=k;
        }
        ret = max(ret, j);
    }
    return ret;
}

int main() 
{
    int T;
    cin>>T;
    vector<int>rets(T);
    for (int t=0; t<T; t++)
    {
        rets[t] = solve();
    }
    for (auto x:rets)
        cout<<x<<endl;
}
