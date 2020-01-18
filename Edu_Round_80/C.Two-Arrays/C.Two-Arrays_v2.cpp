#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=1e6+7;
ll inv[N];

        
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    int MOD = 1e9+7;
    
    inv[1]=1;
    for(int i=2;i<N;++i)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
    
    ll ret = 1;
    for (int i=n+2*m-1; i>=n; i--)
        ret = (ret*i)%MOD;
    
    for (int i=1; i<=2*m; i++)    
        ret = (ret*inv[i])%MOD;    
    
    cout<<ret<<endl;        
}
