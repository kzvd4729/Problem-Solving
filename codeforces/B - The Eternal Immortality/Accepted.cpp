/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2017 20:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/869/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,z,tmp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b;
    z=1;
    if(b-a>=5)
    {
        cout<<0<<endl;
        return 0;
    }
    for(long i=a+1;i<=b;i++)
    {
        tmp=(i+10)%10;
        z=z*tmp;
        z=(z+10)%10;
    }
    cout<<z<<endl;
    return 0;
}
 