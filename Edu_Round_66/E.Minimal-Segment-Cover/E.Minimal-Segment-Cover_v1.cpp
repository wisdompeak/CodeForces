#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int M = 5e5;
    
    int next[M+1][21] = {0};
   
    for (int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        next[a][0] = max(next[a][0],b);
    }
        
    for (int i=1; i<=M; i++)
    {
        next[i][0] = max(next[i][0], next[i-1][0]);
        next[i][0] = max(next[i][0], i);
    }
    
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        
        int ans=0;
        while(l<r)
        {            
            if (l==next[l][0])
            {
                ans = -1;
                break;
            }                
            l=next[l][0];
            ans+=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
