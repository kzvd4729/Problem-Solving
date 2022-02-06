/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2017 10:14                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/844/problem/D
****************************************************************************************/
#include<iostream>
#include<cstdio>
#define long long long
using namespace std;
long v,id,n,s,x,vl,nx,ii,vis[400005];
int main()
{
    cin>>n>>s>>x;
    cout<<"? "<<s<<endl;
    fflush(stdout);
    cin>>v>>id;
    vl=v;
    nx=id;
    vl=-1;
    for(long i=1;i<=1000;i++)
    {
        ii=(((i*1000000009)%n)+n+n+7)%n;
        if(vis[ii]==1)continue;
        vis[ii]=1;
        cout<<"? "<<ii<<endl;
        fflush(stdout);
        cin>>v>>id;
        if(v<=x&&v>vl)
        {
            vl=v;
            nx=id;
        }
     }
    while(true)
    {
        if(nx==-1)break;
        if(vl>=x)break;
        cout<<"? "<<nx<<endl;
        fflush(stdout);
        cin>>vl>>nx;
    }
    if(vl>=x)cout<<"! "<<vl<<endl;
    else cout<<"! "<<-1<<endl;
    fflush(stdout);
    return 0;
}