// #include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;

    if (k<25)
    {
        cout<<-1<<endl;
        return 0;
    }

    int m=0,n=0;
    for (int i=5; i<=sqrt(k); i++)
    {
        if (k%i!=0) continue;
        m = i;
        n = k/i;
    }

    if (m==0)
    {
        cout<<-1<<endl;
        return 0;
    }


    auto matrix = vector<vector<char>>(m,vector<char>(n));
    vector<char>vowel={'a','e','i','o','u'};

    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
        {
            int x = abs(i+j);
            matrix[i][j] = vowel[x%5];
        }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<matrix[i][j];
        }
    }
}
