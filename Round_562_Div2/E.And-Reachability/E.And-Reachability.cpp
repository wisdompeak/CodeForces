#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    
    vector<int>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];
    
    auto next = vector<vector<int>>(n+1,vector<int>(32,n));
    auto latest = vector<vector<int>>(n+1,vector<int>(32,n));
    
    vector<int>temp(32,n);
    for (int i=n-1; i>=0; i--)
    {
        for (int k=0; k<32; k++)
            latest[i][k] = temp[k];
        for (int k=0; k<32; k++)        
            if ((nums[i]>>k)&1 == 1)
                temp[k] = i;        
    }
    
    for (int i=n-1; i>=0; i--)
        for (int j=0; j<32; j++)
        {
            if ((nums[i]>>j)&1==1)          
            {
                next[i][j] = i;
                continue;
            }
            for (int k=0; k<32; k++)
            {
                if ((nums[i]>>k)&1==1)
                    next[i][j] = min(next[i][j], next[latest[i][k]][j]);
            }            
        }

    for (int i=0; i<q; i++)
    {
        int x,y;
        cin>>x>>y;
        
        int flag = 0;
        for (int k=0; k<32; k++)
        {
            if ((nums[y-1]>>k)&1==1 && next[x-1][k]<y-1)
            {
                cout<<"Shi"<<endl;
                flag = 1;
                break;
            }
        }
        if (flag==0) cout<<"Fou"<<endl;        
    }
    
    return 0;
}
