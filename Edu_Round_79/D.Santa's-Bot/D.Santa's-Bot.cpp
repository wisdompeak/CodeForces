#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+7,mod=998244353;
ll inv[N];

int main() 
{
    int i;
    for(inv[1]=1,i=2;i<N;++i)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    
    int n;
    cin>>n;
    unordered_map<int,int>gift;
    unordered_map<int,vector<int>>person;
    
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        for (int j=0; j<k; j++)
        {
            int g;
            cin>>g;
            gift[g]+=1;
            person[i].push_back(g);
        }            
    }
    
    ll ret = 0;
    for (int i=1; i<=n; i++)
    {
        ll ans = 0;
        for (auto g: person[i])
        {
            ans += (gift[g]* inv[n]) %mod;
            ans %= mod;
            // ans += gift[g]*1.0/n;
        }
        ret += (ans * inv[person[i].size()]) %mod;
        ret %= mod;
        // ret+=ans/person[i].size();
    }

    ret = ret* inv[n]%mod;
    // ret /= n;
    
    cout<<ret<<endl;    
}
