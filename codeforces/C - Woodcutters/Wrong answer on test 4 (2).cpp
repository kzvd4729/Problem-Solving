/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/11/2018 10:56                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/545/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,last,ans;
struct data
{
    long x,h;
}arr[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i].x>>arr[i].h;
    arr[n+1].x=999999999999999;
    last=-99999999999999;
    for(long i=1;i<=n;i++)
    {
        if((arr[i].x-arr[i].h)>last)
        {
            ans++;
            last=arr[i].x;
        }
        else if((arr[i].x+arr[i].h)<arr[i+1].x)
        {
            ans++;
            last=arr[i].x+arr[i].h;
        }
    }
    cout<<ans<<endl;
    return 0;
}