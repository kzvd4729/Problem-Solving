/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-28 18:05:37                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/arc090/tasks/arc090_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,mat[4][102];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
     for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mat[i][j];
            mat[i][j]+=max(mat[i][j-1],mat[i-1][j]);
        }
    }
//    for(int i=1;i<=2;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            cout<<mat[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<mat[2][n]<<endl;
    return 0;
}