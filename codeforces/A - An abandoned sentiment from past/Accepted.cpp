/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2017 09:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/814/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],brr[100005],n,k,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(!arr[i])cnt++;
    }
    for(long i=1;i<=k;i++)
    {
        cin>>brr[i];
    }
    if(cnt!=1)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    for(long i=1;i<=n;i++)
    {
        if(!arr[i])
        {
            arr[i]=brr[1];
        }
    }
    long f=0;
    for(long i=2;i<=n;i++)
    {
        if(arr[i]<=arr[i-1])f=1;
    }
    if(f==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
      return 0;
}
 