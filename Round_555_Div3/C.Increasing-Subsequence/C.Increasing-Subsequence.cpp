// #include <QCoreApplication>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include <bits/stdc++.h>

using namespace std;

string solution_hard(int n, vector<int>nums)
{
    int i=0;
    int j=n-1;
    int now = INT_MIN;

    string s;

    while (i<=j)
    {   
        if (nums[i]<=now && nums[j]<=now)
            break;
        else if (nums[i]<=now)
        {
            while (i<=j && nums[j]>now)
            {
                now = nums[j];
                s+="R";
                j--;
            }
            break;
        }
        else if (nums[j]<=now)
        {
            while (i<=j && nums[i]>now)
            {
                now = nums[i];
                s+="L";
                i++;
            }
            break;
        }        

        if (nums[i]<nums[j])
        {
            now = nums[i];
            i++;
            s+="L";
        }
        else if (nums[i]>nums[j])
        {
            now = nums[j];
            j--;
            s+="R";
        }
        else
        {
            int i0=i, j0=j;

            while (i<=j0 && (i==0 || nums[i]>nums[i-1]))
                i++;
            while (j>=i0 && (j==n-1 || nums[j]>nums[j+1]))
                j--;

            if (i-i0>j0-j)
            {
                for (int k=0; k<i-i0; k++)
                    s+="L";
            }
            else
            {
                for (int k=0; k<j0-j; k++)
                    s+="R";
            }

            break;
        }

    }

    return s;
}



int main()
{
    int n;
    cin >> n;

    vector<int>nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];

    string s = solution_hard(n,nums);
    cout<<s.size()<<endl;
    cout<<s<<endl;


}

