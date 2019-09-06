#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    int T;
    cin>>T;
    for (int t=0; t<T; t++)
    {
        int n, x;
        cin>>n>>x;
        
        ll maxD = 0;
        ll maxHit = 0;
        for (int i=0; i<n; i++)
        {
            ll d,h;
            cin>>d>>h;
            maxD = max(maxD, d-h);
            maxHit = max(maxHit, d);
        }
        
        if (x<=maxHit)
            cout<<1<<endl;
        else if (maxD==0)
            cout<<"-1"<<endl;
        else
        {
            ll diff = x-maxHit;
            
            if (diff%maxD==0)
                cout<<1ll+diff/maxD<<endl;
            else
                cout<<1ll+diff/maxD+1<<endl;
        }
            
    }
    
    return 0;
}
