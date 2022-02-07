/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-17 23:41:47                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10887
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1[1505],s2[1505],tmp;
int ans,tc,t,n,m;
map<string,int>mp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>s1[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>s2[i];
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            tmp=s1[i];
            for(int j=1;j<=m;j++)
            {
                tmp+=s2[j];
                if(mp[tmp]!=1)
                {
                    mp[tmp]=1;
                    ans++;
                }
            }
        }
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            s1[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            s2[i].clear();
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;

    }
    return 0;
}