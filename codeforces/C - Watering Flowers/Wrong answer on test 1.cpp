/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/17/2017 18:52                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/617/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
long n,r1,c1,r2,c2,r,c,x,y,ans=9999999999999999,kk,k,mx,i,j,xx,yy;
vector<pair<long,long> >v;
long dist(long o1,long o2,long p1,long p2)
{
    return (o1-p1)*(o1-p1)+(o2-p2)*(o2-p2);
}
int main()
{
    cin>>n>>r1>>c1>>r2>>c2;
    for(i=1; i<=n; i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    for(i=0; i<n; i++)
    {
        x=v[i].first;
        y=v[i].second;
        r=dist(r1,c1,x,y);
        mx=0;
        for(j=0; j<n; j++)
        {
            xx=v[j].first;
            yy=v[j].second;
            kk=dist(r1,c1,xx,yy);
            k=dist(r2,c2,xx,yy);
            mx=max(mx,k);
             ///ans=min(ans,r+c);
        }
        ans=min(ans,r+mx);
    }
    cout<<ans<<endl;
    return 0;
}