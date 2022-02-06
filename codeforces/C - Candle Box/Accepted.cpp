/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729#         created: Sep/20/2017 18:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101174/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     long d,r,t;
    cin>>d>>r>>t;
     long ra=4;
    long ta=ra-d;
    long cnt=0,R=0,T=0;
    for(long i=0;  ;i++)
    {
        R+=i+4;
        if(ta>=3)
        {
            T+=cnt+3;
            cnt++;
        }
        if(R+T==r+t)
        {
            cout<<r-R<<endl;
            return 0;
        }
        ra++;
        ta++;
    }
     return 0;
}