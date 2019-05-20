#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main() {
    int m,n;
    cin>>m>>n;
    vector<bitset<10000>>A(m);
    
    for (int i=0; i<m; i++)
    {
        int s;
        cin>>s;
        for (int j=0; j<s; j++)
        {
            int k;
            cin>>k;
            A[i][k] = 1;
        }
    }
    
    int flag = 1;
    for (int i=0; i<m; i++)
    {        
        for (int j=i+1; j<m; j++)
        {
            if (!(A[i]&A[j]).any())
            {
                flag = 0;
                break;
            }
        }
        if (flag==0) break;
    }
    
    if (flag==1)
        cout<<"possible"<<endl;
    else
        cout<<"impossible"<<endl;    
}
