/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-18 14:58:11                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10887
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1[1505],s2[1505],tmp;
int tc,t,n,m,ans;
map<string,int>mp;
int main()
{
    ///ofstream cout("out.txt");
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
            for(int j=1;j<=m;j++)
            {
                tmp.clear();
                tmp=s1[i]+s2[j];
                if(mp[tmp]==0)
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