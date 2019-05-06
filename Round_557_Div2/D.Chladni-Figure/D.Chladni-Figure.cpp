#include<bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;

int n,m;

bool same(vector<int>&a, vector<int>&b)
{
    if (a.size()!=b.size()) return false;
    for (int i=0; i<a.size(); i++)
    {
       if (a[i]!=b[i])
           return false;
    }
    return true;
}

vector<int> getNext(vector<vector<int>>& p) {
    int n = p.size(), k = -1, j = 0;
    vector<int> next(n, -1);
    while (j < n - 1) {
        if (k == -1 || same(p[j],p[k])) {
            ++k; ++j;
            next[j] = (!same(p[j],p[k])) ? k : next[k];
        } else {
            k = next[k];
        }
    }
    return next;
}


int kmp(vector<vector<int>>& s, vector<vector<int>>& p) {
    int m = s.size(), n = p.size(), i = 0, j = 0;
    vector<int> next = getNext(p);
    while (i < m && j < n) {
        if (j == - 1 || same(s[i],p[j])) {
            ++i; ++j;
        } else {
            j = next[j];
        }
    }
    return (j == n) ? i - j : -1;
}


int main() {    
    cin>>n>>m;
    
    vector<vector<int>>p(n);
    for (int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        p[a-1].push_back((b-1-(a-1)+2*n)%n);
        p[b-1].push_back((a-1-(b-1)+2*n)%n);
    }
    
    for (int i=0; i<p.size(); i++)
        sort(p[i].begin(),p[i].end());       
    
    auto s = p;
    s.erase(s.begin());
    for (auto x:p)
        s.push_back(x);
    s.pop_back();
      
    int result = kmp(s,p);
    //cout<<result<<endl;
    if (result!=-1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
}
