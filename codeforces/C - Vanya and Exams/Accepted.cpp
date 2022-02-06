/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 11:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/492/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,r,avg,gp,rem;
struct data
{
    long a,b;
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
     cin>>n>>r>>avg;
    avg*=n;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i].a>>arr[i].b;
        gp+=arr[i].a;
    }
    rem=avg-gp;
    sort(arr+1,arr+n+1,cmp);
    long ans=0;
    for(long i=1;i<=n;i++)
    {
        if(rem<=0)break;
        if(r-arr[i].a<=rem)
        {
            ans+=arr[i].b*(r-arr[i].a);
            rem-=(r-arr[i].a);
            if(rem<=0)break;
        }
        else ans+=arr[i].b*rem,rem=0;
    }
    cout<<ans<<endl;
    return 0;
}