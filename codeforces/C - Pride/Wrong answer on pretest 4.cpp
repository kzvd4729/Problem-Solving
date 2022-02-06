/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2017 21:26                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/892/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[20002],gcd;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)cin>>arr[i];
    for(long i=1; i<=n; i++)
    {
        gcd=__gcd(gcd,arr[i]);
    }
    if(gcd!=1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(long i=1; i<n; i++)
    {
        gcd=__gcd(arr[i],arr[i+1]);
        if(gcd==1)
        {
            cout<<n<<endl;
            return 0;
        }
    }
    cout<<n+1<<endl;
    return 0;
}
 