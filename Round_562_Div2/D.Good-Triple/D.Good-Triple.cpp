#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin>>s;
    
    int n = s.size();    
    vector<int>right(n,INT_MAX);
    
    for (int i=0; i<n; i++)
    {
        int j=i+1;
        bool flag = 0;
        while (j*2-i<n && !flag)
        {
            if (s[i]==s[j] && s[i]==s[j*2-i])
            {
                flag = 1;
                break;
            }
            j++;
        }
                
        if (flag)
            right[i] = j*2-i;
        
    }
    
    int MIN = INT_MAX;
    ll result = 0;
    for (int i=n-1; i>=0; i--)
    {        
        MIN = min(MIN,right[i]);
        if (MIN!=INT_MAX)
            result += n-MIN;
    }
    
    cout<< result <<endl;
    return 0;
    
}
