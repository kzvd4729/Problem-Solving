/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2017 21:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/892/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[20002],gcd,cnt,len;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(arr[i]==1)cnt++;
    }
    if(cnt)
    {
        cout<<n-cnt<<endl;
        return 0;
    }
    for(long i=1; i<=n; i++)
    {
        gcd=__gcd(gcd,arr[i]);
    }
    if(gcd!=1)
    {
        cout<<-1<<endl;
        return 0;
    }
    len=9999999999;
    for(long i=1;i<=n;i++)
    {
        gcd=0;
        for(long j=i;j<=n;j++)
        {
            gcd=__gcd(gcd,arr[j]);
            if(gcd==1)
            {
                len=min(len,j-i+1);
            }
        }
    }
    cout<<n+len-2<<endl;
    return 0;
}
 