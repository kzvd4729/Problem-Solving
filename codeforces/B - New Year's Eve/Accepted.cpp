/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2018 19:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/912/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    if(k==1)cout<<n<<endl;
    else
    {
        for(long i=0;i<=100;i++)
        {
            long x=pow(2,i);
            if(x>n)
            {
                cout<<x-1<<endl;
                return 0;
            }
        }
    }
     return 0;
}