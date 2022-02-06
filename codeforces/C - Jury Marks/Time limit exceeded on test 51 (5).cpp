/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2017 22:50                        
*  solution_verdict: Time limit exceeded on test 51          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 78400 KB                             
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
map<int,int>mp,mp2,mp3;
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
    }
    for(i=1;i<=n;i++)
    {
        cin>>nn[i];
        mp[nn[i]]=1;
    }
    x=nn[1];
    for(i=1;i<=k;i++)
    {
        in=x-kk[i];
        cnt=n;
        if(mp3[in]==1)continue;
        for(j=1;j<=k;j++)
        {
            int xx=in+kk[j];
            if(mp[xx]==1)
            {
                if(mp2[xx]==0)
                {
                    cnt--;
                    mp2[xx]=1;
                }
            }
        }
        mp2.clear();
        if(cnt<=0)
        {
            ans++;
            mp3[in]=1;
        }
    }
    cout<<ans<<endl;
     return 0;
}