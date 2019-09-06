#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    
    int T;
    cin>>T;
    for (int t=0; t<T; t++)
    {
        string s;
        cin>>s;
        
        int count = 0;
        int zeros = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='0')
            {
                zeros++;
                continue;
            }
            
            int j = i;
            int num = 0;
            while (j<s.size())
            {
                num = num*2+(s[j]-'0');
                if (num-(j-i+1)<=zeros)
                {
                    count++;                
                    j++;
                }
                else
                    break;
            }
            zeros = 0;
        }
        cout<<count<<endl;
    }
    
    return 0;
}
