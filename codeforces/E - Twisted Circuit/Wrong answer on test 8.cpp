/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2017 22:22                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/784/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    int cnt=1;
    while (cin>>a>>b>>c>>d)
    {
        int x,y,s,t,m,n;
        if (a==b) x=0;
        else x=1;
        if (c==d) y=0;
        else y=1;
         if (b==1&&c==1) s=1;
        else s=0;
         if (a==d) t=0;
        else t=1;
         if (x==1&&y==1) m=1;
        else m=0;
         if (s==t) n=0;
        else n=1;
         if (m==n) cout << "0";
        else cout << "1";
        cout << endl;
     }
     return 0;
}