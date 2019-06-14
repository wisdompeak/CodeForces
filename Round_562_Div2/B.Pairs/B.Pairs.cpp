#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>&a, vector<int>&b, int x, int y)
{
    for (int i=1; i<a.size(); i++)
    {
        if (a[i]==x || b[i]==x)
            continue;
        else if (y!=0 && (a[i]==y || b[i]==y))
            continue;
        else if (y==0)
            return check(a,b,x,a[i])||check(a,b,x,b[i]);
        else
            return false;            
    }
    return true;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    vector<int>b(m);
    
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
    
    if (check(a,b,a[0],0)||check(a,b,b[0],0))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}
