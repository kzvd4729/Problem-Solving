/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/12/2017 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/839/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[103],i;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)cin>>arr[i];
    int left=0;
    int have=0;
    int f=0;
    for(i=1;i<=n;i++)
    {
        if(arr[i]+left>8)
        {
            have+=8;
            left=left+arr[i]-8;
        }
        else
        {
            have+=arr[i]+left;
            left=0;
        }
        if(have>=k)
        {
            f=1;
            break;
        }
    }
    if(f==1)cout<<i<<endl;
    else cout<<-1<<endl;
     return 0;
}