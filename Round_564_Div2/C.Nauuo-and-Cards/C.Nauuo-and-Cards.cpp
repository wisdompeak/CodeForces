#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    
    vector<int>p(n+1);
    vector<int>b(n+1);
    
    for (int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        p[x] = 0;
    }
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>b[i];
        p[b[i]] = i;
    }
    
    // check if we can make it without pushing 0
    if (p[1]!=0)  // 1 is in the pile
    {
        int flag = 1;
        int i = 1;
        while (p[1]+i-1<=n)
        {            
            if (b[p[1]+i-1]!=i)
            {
                flag = 0;
                break;
            }
            i++;
        }
        i--;
        
        if (flag)   
        {
            for (int j=i+1; j<=n; j++)
            {
                if (p[j]>=j-i)
                {
                    flag = 0;
                    break;
                }
            }
        }
                
        if (flag)
        {
            cout<<n-i<<endl;
            return 0;
        }
    }
    
    int result = -1;
    for (int i=1; i<=n; i++)    
        result = max(result, p[i]-i+1+n);
    cout<<result<<endl;
    
    return 0;
}
