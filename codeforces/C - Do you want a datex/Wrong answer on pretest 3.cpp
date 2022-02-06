/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2017 02:04                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/810/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
long n,arr[300005],i,tmp[300005],sum,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    /*for(i=1;i<=n;i++)
    {
        tmp[i]=tmp[i-1]+arr[i];
    }*/
    sum=0;
    cnt=1;
    for(i=n-1;i>=1;i--)
    {
        sum=sum+sum*(cnt-1)+(cnt*abs(arr[i]-arr[i+1]));
        cnt=(cnt*2)+1;
    }
    cout<<sum<<endl;
     return 0;
}