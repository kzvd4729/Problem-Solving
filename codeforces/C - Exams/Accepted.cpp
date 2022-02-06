/****************************************************************************************
*  @author: kzvd4729                                         created: May/17/2018 19:36                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/479/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,day,i;
struct data
{
    long long int a;
    long long int b;
}arr[5005];
bool cmp(data A,data B)
{
    if(A.a!=B.a)return A.a<B.a;
    else return A.b<B.b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].a>>arr[i].b;
    }
    sort(arr+1,arr+n+1,cmp);
    day=0;
    for(i=1;i<=n;i++)
    {
        if(arr[i].b>=day)day=arr[i].b;
        else day=arr[i].a;
    }
    cout<<day<<endl;
        return 0;
}