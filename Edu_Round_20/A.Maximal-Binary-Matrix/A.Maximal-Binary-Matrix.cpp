#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() {
    int n, k;
    cin>>n>>k;
    auto matrix = vector<vector<int>>(n,vector<int>(n,0));
    int i = 0, j = 0;
    int count = k;
    
    if (count>n*n)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    while (count>0)
    {        
        matrix[i][j] = 1;
        matrix[j][i] = 1;
        if (i==j)
            count-=1;
        else
            count-=2;
                
        if (count==1)
        {
            i = i+1;
            j = i;
        }
        else
        {
            j = j+1;
            if (j==n)
            {
                i += 1;
                j = i;
            }
        }
        
        if (i==n)
        {
            cout<<"-1"<<endl;
            return 0;
        }        
    }
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
        
}
