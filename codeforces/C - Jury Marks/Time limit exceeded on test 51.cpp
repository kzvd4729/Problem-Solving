/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2017 22:37                        
*  solution_verdict: Time limit exceeded on test 51          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 68600 KB                             
*  problem: https://codeforces.com/contest/831/problem/C
****************************************************************************************/
/*
4 1
-5 5 0 20
10
*/
#include<bits/stdc++.h>
using namespace std;
int k,n,sum,kk[2002],nn[2002],in,x,cnt,ans,i,j;
map<int,int>mp;
int main()
{
    cin>>k>>n;
    for(i=1;i<=k;i++)
    {
        cin>>x;
        sum+=x;
        kk[i]=sum;
    }
    for(i=1;i<=n;i++)
    {
        cin>>nn[i];
        mp[nn[i]]=1;
    }
    x=nn[1];
    set<int>s;
    for(i=1;i<=k;i++)
    {
        in=x-kk[i];
        cnt=n;
        set<int>s2;
        for(j=1;j<=k;j++)
        {
            int xx=in+kk[j];
            if(mp[xx]==1)s2.insert(xx);
        }
        if(s2.size()==n)s.insert(in);
    }
    cout<<s.size()<<endl;
     return 0;
}