/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2018 17:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 561 ms                                          memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/908/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long n;
long double r,ans[1003],mx,p[1003],lo,hi,mid,eps=0.00000000001;
struct point
{
    long double x,y;
};
long double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>r;
    for(long i=1;i<=n;i++)
    {
        cin>>p[i];
        mx=r;
        for(long j=1;j<i;j++)
        {
            if(abs(p[i]-p[j])>2*r)continue;
            lo=0;
            hi=200000000;
            while((hi-lo)>eps)
            {
                mid=(lo+hi)/2.0;
                double d=dis({p[j],ans[j]},{p[i],mid});
                if(d<=2*r||mid<=ans[j])lo=mid;
                else hi=mid;
                ///if(i==6)cout<<lo<<" "<<hi<<" "<<d<<endl;
            }
            mx=max(mx,mid);
        }
        ans[i]=mx;
    }
    for(long i=1;i<=n;i++)cout<<setprecision(10)<<fixed<<ans[i]<<endl;
    return 0;
}