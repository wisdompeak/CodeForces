#include<bits/stdc++.h>
#define ll long long
using namespace std;

 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>p(n);
    for (int i=0; i<n; i++)
        cin>>p[i];
    sort(p.begin(),p.end());
    
    
    int min_last = -1, max_last = -1;
    int min_houses = 0, max_houses = 0;
    for (auto pos : p)
    {
        if (min_last < pos-1)
        {
            min_last = pos+1;
            min_houses++;
        }
        
        if (max_last < pos-1)
        {
            max_last = pos-1;
            max_houses++;
        }
        else if (max_last < pos+1)
        {
            max_last = max_last+1;
            max_houses++;
        }            
    }
    
    cout<<min_houses<<" "<<max_houses<<endl;
    
}
