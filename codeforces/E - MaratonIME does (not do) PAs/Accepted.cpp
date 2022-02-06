/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 20:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 2700 KB                              
*  problem: https://codeforces.com/gym/101375/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,s,i,ans;
struct data
{
    int t;
    int e;
}d[100005];
bool cmp(data A,data B)
{
    return A.t<B.t;
}
int main()
{
    cin>>n>>s;
    for(i=1;i<=n;i++)
    {
        cin>>d[i].t>>d[i].e;
    }
    sort(d+1,d+n+1,cmp);
     for(i=1;i<=n;i++)
    {
        s=s+d[i].t;
        ans+=s-d[i].e;
    }
    cout<<ans<<endl;
    return 0;
}