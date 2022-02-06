/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/12/2017 20:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/873/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,num,x,arr[102],ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>num>>x;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    for(long i=n; i>=1; i--)
    {
        if(num==0)ans+=arr[i];
        else
        {
            if(arr[i]>x&&num)
            {
                ans+=x;
                num--;
            }
            else ans+=arr[i];
        }
    }
    cout<<ans<<endl;
     return 0;
}