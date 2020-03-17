#include<bits/stdc++.h>
#define ll long long
using namespace std;
    
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<ll>m(n);
    for (int i=0; i<n; i++)
        cin>>m[i];
    vector<ll>next(n, -1);
    vector<ll>prev(n, -1);

    // Find Next Smaller / Prev Smaller
    stack<ll>Stack;    
    for (int i=0; i<n; i++)
    {
        if (Stack.empty()||m[i]>=m[Stack.top()])
            Stack.push(i);
        else
        {
            while (!Stack.empty() && m[i]<m[Stack.top()])
            {
                next[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
    }
    
    while (!Stack.empty()) Stack.pop();
    for (int i=n-1; i>=0; i--)
    {
        if (Stack.empty()||m[i]>=m[Stack.top()])
            Stack.push(i);
        else
        {
            while (!Stack.empty() && m[i]<m[Stack.top()])
            {
                prev[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
    }
    
    // Left[i]: the maximum gain from i (as a peek) through to the left
    // Right[i]: the maximum gain from i (as a peek) through to the right
    vector<ll>left(n);
    vector<ll>right(n);
    for (int i=0; i<n; i++)
    {
        int l = prev[i];
        if (l==-1)
            left[i] = (i+1)*m[i];
        else
            left[i] = left[l]+(i-l)*m[i];            
    }
    
    for (int i=n-1; i>=0; i--)
    {
        int r = next[i];
        if (r==-1)
            right[i] = (n-i)*m[i];
        else
            right[i] = right[r]+(r-i)*m[i];            
    }
    
    // Find the best peak!
    ll ret = INT_MIN, idx;
    for (int i=0; i<n; i++)
    {
        if (left[i]+right[i]-m[i]>ret)
        {
            ret = left[i]+right[i]-m[i];
            idx = i;
        }
    }
    
    // Iterate all elements given the best peak.
    vector<ll>ans(n);
    ans[idx] = m[idx];
    ll cur = m[idx];
    for (int i=idx+1; i<n; i++)
    {
        if (m[i]>cur)
            ans[i] = cur;
        else
        {
            ans[i] = m[i];
            cur = m[i];
        }
    }
    cur = m[idx];
    for (int i=idx-1; i>=0; i--)
    {
        if (m[i]>cur)
            ans[i] = cur;
        else
        {
            ans[i] = m[i];
            cur = m[i];
        }
    }
    
    for (int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    
}
