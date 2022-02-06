/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2017 23:41                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/807/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int x,y,p,q,lo,hi,mid,ans,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>p>>q;
                if(p==1&&q==1)
        {
            if(x==y)
            {
                cout<<0<<endl;
            }
            else cout<<-1<<endl;
            return 0;
        }
        if(p==0)
        {
            if(x==0)
            {
                cout<<0<<endl;
            }
            else 
            {
                cout<<-1<<endl;
            }
            return 0;
        }
                lo=0;
        hi=100000000;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            int pp=mid*p;
            int qq=mid*q;
            int xp=pp-x;
            int yq=qq-y;
            if(pp>=x&&qq>=y&&yq>=xp&&((mid-1)*p<x||(mid-1)*q<y||((mid-1)*q)-y<((mid-1)*p)-x))
            {
                ans=yq;
                break;
            }
            if(pp<x||qq<y||yq<xp)
            {
                lo=mid+1;
            }
            else hi=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}