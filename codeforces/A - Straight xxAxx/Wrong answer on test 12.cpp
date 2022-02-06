/****************************************************************************************
*  @author: kzvd4729                                         created: May/21/2017 00:23                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/810/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
double n,k,arr[104],sum,cnt,avg;
long i,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    avg=sum/n;
    if(k-avg<=0.500)
    {
        cout<<0<<endl;
    }
    for(cnt=1;  ;cnt++)
    {
       avg=(sum+(k*cnt))/(n+cnt);
       if(k-avg<=0.50000)break;
    }
    cout<<cnt<<endl;
    return 0;
}