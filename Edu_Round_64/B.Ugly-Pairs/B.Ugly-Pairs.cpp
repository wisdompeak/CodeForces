#include<bits/stdc++.h>
#include <iostream>
using namespace std;


string check(vector<int>&freq, int start)
{
    int flag = 1;
    string result;

    for (int i=start; i<26; i+=2)
    {
        if (freq[i]==0) continue;
        for (int k=0; k<freq[i]; k++)
            result.push_back('a'+i);
    }

    for (int i=1-start; i<26; i+=2)
    {
        if (freq[i]==0) continue;
        if (result.size()>0 && abs(('a'+i)-result.back())==1)
        {
            flag = 0;
            break;
        }
        for (int k=0; k<freq[i]; k++)
            result.push_back('a'+i);
    }

    if (flag)
        return result;
    else
        return "No answer";
}

void solution(string& str)
{
    vector<int>freq(26,0);
    for (auto ch:str)
        freq[ch-'a']+=1;

    string ret1 = check(freq,0);
    if (ret1!="No answer")
    {
        cout<<ret1<<endl;
        return;
    }

    string ret2 = check(freq,1);
    cout<<ret2<<endl;
}

int main() {
    int n;
    vector<string>str;
    
    cin>>n;    
    str.resize(n);
    for (int i=0; i<n; i++)
        cin>>str[i];
    
    for (int i=0; i<n; i++)
        solution(str[i]);
}
