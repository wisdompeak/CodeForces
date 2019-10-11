#include <bits/stdc++.h>
using namespace std;
int maxDis;

int askForDis(int a, int b)
{
    cout<<1<<" "<<b-a+1<<" ";
    cout<<1<<" ";
    for (int i=a; i<=b; i++)
        cout<<i<<" ";
    cout<<endl;
    cout.flush();
    int d  = 0;
    cin>>d;
    return d;
}

int findFarthest(int a, int b)
{
    if (a==b)
        return a;
    
    int mid = a+(b-a)/2;
    if (askForDis(a,mid)==maxDis)
        return findFarthest(a,mid);
    else
        return findFarthest(mid+1,b);    
}

int main() {
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        
        maxDis = askForDis(2,n);
        
        int farPoint = findFarthest(2,n);
        
        cout<<1<<" "<<n-1<<" ";
        cout<<1<<" ";
        for (int i=1; i<=n; i++)
            if (i!=farPoint) cout<<i<<" ";
        cout<<endl;
        cout.flush();
        int ret;
        cin>>ret;
        
        cout<<"-1 "<<ret<<endl;
        cout.flush();
    }
}
