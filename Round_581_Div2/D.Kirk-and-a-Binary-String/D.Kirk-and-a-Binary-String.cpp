#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ll long long
 
int main() {
    string s;
    cin>>s;
    int n = s.size();
    string t = s;
    for (int i=0; i<n; i++)
        t[i] = '0';
    
    for (int i=0; i<n; i++)
    {
        if (s[i]=='0') continue;
        
        stack<int>Stack;
        Stack.push(i);
        
        while (i<n && !Stack.empty())
        {
            if (s[i]=='1')
            {
                Stack.push(i);                
            }
            else
            {
                t[Stack.top()] = s[Stack.top()];
                t[i] = s[i];
                Stack.pop();
            }
            i++;            
        }         
        i--;
    }
    cout<< t <<endl;
}
