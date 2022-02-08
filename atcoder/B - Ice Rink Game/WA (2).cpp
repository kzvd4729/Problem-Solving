/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-14 18:35:37                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 13 ms                                           memory_used: 1024 KB                              
*  problem: https://atcoder.jp/contests/agc020/tasks/agc020_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],lft,rgt,f,mul,in;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    lft=2,rgt=2;
    in=arr[1];
    for(long i=n;i>=1;i--)
    {
        mul=(lft-1)/arr[i];
        long tmp=arr[i]*(mul+1);
        if(tmp<lft||tmp>rgt)f=1;
        lft=tmp;
        rgt=tmp+arr[i]-1;
        arr[i]=tmp;
    }
    if(f)cout<<-1<<endl;
    else cout<<arr[1]<<" "<<arr[1]+in-1<<endl;
    return 0;
}
 