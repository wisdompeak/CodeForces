#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n,k;    
    cin>>n>>k;
    
    int a = (n-k)/2;
    
    for (int i=0; i<n; i++)
    {
        if (i%(a+1)<a)
            cout<<"1";
        else 
            cout<<"0";
    }
    return 0;       
}
