/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/25/2017 20:37                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 732 ms                                          memory_used: 5200 KB                              
*  problem: https://codeforces.com/contest/777/problem/C
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 int main()
{
    int n,m,i,j,l,r,q;
    cin>>n>>m;
     vector<vector<int> >a(n,vector<int>(m));
     vector<int>b(n,0);
     for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)cin>>a[i][j];
    }
    for(j=0;j<m;j++)
    {
        l = 0;
        for(i=0;i<n;i++)
            if(i==n-1||a[i][j]>a[i+1][j])
                b[l]=max(b[l],i),l = i+1;
    }
     for(int i = 1; i < n; i++)
        b[i] = max(b[i], b[i-1]);
     cin >> q;
     while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(b[l] >= r) cout << "Yes\n";
        else cout << "No\n";
    }
     return 0;
}