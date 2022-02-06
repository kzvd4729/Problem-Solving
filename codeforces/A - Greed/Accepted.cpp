/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/17/2017 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/892/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,sum,cap;
struct data
{
    long a;
    long b;
}arr[100005];
bool cmp(data A,data B)
{
    return A.b<B.b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i].a;
        sum+=arr[i].a;
    }
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i].b;
    }
    sort(arr+1,arr+n+1,cmp);
    cap=arr[n].b+arr[n-1].b;
    if(sum<=cap)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
 