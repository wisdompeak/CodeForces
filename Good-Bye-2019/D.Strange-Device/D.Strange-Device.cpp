    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
     
    vector<ll> solve()
    {
        int n;
        cin>>n;
        ll Sum = 0;
        ll Xor = 0;
        for (int i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            Sum += x;
            Xor ^= x;
        }
            
        return {Sum,Sum+Xor};    
    }
     
    int main() 
    {
        int n,k;
        cin>>n>>k;
        map<int,int>Map;
        for (int i=1; i<=k+1; i++)
        {
            cout<<"? ";
            for (int j=1; j<=k+1; j++)
            {
                if (j!=i)
                    cout<<j<<" ";
            }
            cout<<endl;
            cout.flush();
            int a,b;
            cin>>a>>b;
            Map[b]++;
        }
        int ret;
        for (auto x:Map)
            ret = x.second;
        cout<<"! "<<ret<<endl;
    }
