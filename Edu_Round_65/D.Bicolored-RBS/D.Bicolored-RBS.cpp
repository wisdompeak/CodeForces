#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n;    
    cin>>n;
    string s;
    cin>>s;
    s = ")"+s;
    
    int flag = 0;
    
    string result;
    for (int i=1; i<s.size(); i++)
    {
        if (s[i]==s[i-1])            
            flag = 1-flag;            
        result+=to_string(flag);
    }
    
    cout<<result<<endl;
    
    return 0;
}
