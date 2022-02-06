/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/15/2017 21:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1637 ms                                         memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/785/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,a,b,x,y,mxa,mnb,mxx,mxy,d1,d2,i,mny;
    while(cin>>n)
    {
        mxa=0;
        mnb=999999999999;
        for(i=1;i<=n;i++)
        {
            cin>>a>>b;
            if(a>mxa)mxa=a;
            if(b<mnb)mnb=b;
         }
        cin>>m;
        mxx=0;
        mny=999999999999;
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(x>mxx)mxx=x;
            if(y<mny)mny=y;
         }
         d1=mxx-mnb;
        if(d1<0)d1=0;
         d2=mxa-mny;
        if(d2<0)d2=0;
         cout<<max(d1,d2)<<endl;
      }
     return 0;
}