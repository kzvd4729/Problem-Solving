/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2017 12:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/152/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define inf 99999999999999;
int main()
{
    long long int n,m,k,s1,s2,x,y,cnt=0,d1,d2,m1,m2,m3,i;
    cin>>n>>m;
    cin>>s1>>s2;
    cin>>k;
    for(i=1; i<=k; i++)
    {
        cin>>x>>y;
        if(x==0)
        {
            d1=inf;
            m1=inf;
        }
        else if(x>0)
        {
            d1=n-s1;
            m1=d1/x;
        }
        else
        {
            d1=s1-1;
            m1=d1/abs(x);
        }
                if(y==0)
        {
            d2=inf;
            m2=inf;
        }
        else if(y>0)
        {
            d2=m-s2;
            m2=d2/y;
        }
        else
        {
            d2=s2-1;
            m2=d2/abs(y);
        }
                m3=min(m1,m2);
                cnt=cnt+m3;
                s1=s1+(x*m3);
        s2=s2+(y*m3);
     }
        cout<<cnt<<endl;
     return 0;
}