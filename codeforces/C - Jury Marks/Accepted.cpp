/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2017 23:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/831/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int k,n,sum,kk[2002],nn[2002],in,x,cnt,ans,i,j;
map<int,int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>n;
    for(i=1;i<=k;i++)
    {
        cin>>x;
        sum+=x;
        kk[i]=sum;
        mp[kk[i]]=1;
    }
    for(i=1;i<=n;i++)cin>>nn[i];
    x=nn[1];
    set<int>s;
    for(i=1;i<=k;i++)
    {
        in=x-kk[i];
        cnt=n;
        int f=0;
        for(j=1;j<=n;j++)
        {
            int xx=nn[j]-in;
            if(mp[xx]!=1)
            {
                f=1;
                break;
            }
        }
        if(f==0)s.insert(in);
    }
    cout<<s.size()<<endl;
    return 0;
}