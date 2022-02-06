/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2017 11:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/879/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,s,d,now;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    while(n--)
    {
        cin>>s>>d;
        for(long i=0; ;i++)
        {
            long ss=s+d*i;
            if(ss>now)
            {
                now=ss;
                break;
            }
        }
    }
    cout<<now<<endl;
     return 0;
}
 