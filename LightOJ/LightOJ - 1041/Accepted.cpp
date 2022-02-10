/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-11 01:13:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 4                                          memory_used (MB): 1.8                             
*  problem: https://vjudge.net/problem/LightOJ-1041
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
map<string,long>mp;
vector<string>v;
map<string,string>xs;
long t,tc,m;
struct data
{
    string s1;
    string s2;
    long c;
}st[52];
bool cmp(data A,data B)
{
    return A.c<B.c;
}
string root(string x)
{
    while(true)
    {
        if(x==xs[x])return x;
        xs[x]=xs[xs[x]];
        x=xs[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--)
    {
        mp.clear();
        v.clear();
        xs.clear();

        cin>>m;
        for(long i=1;i<=m;i++)
        {
            cin>>st[i].s1;
            cin>>st[i].s2;
            cin>>st[i].c;
            if(mp[st[i].s1]==0)v.push_back(st[i].s1);
            mp[st[i].s1]=1;
            if(mp[st[i].s2]==0)v.push_back(st[i].s2);
            mp[st[i].s2]=1;

        }
        for(long i=0;i<v.size();i++)xs[v[i]]=v[i];
        sort(st+1,st+m+1,cmp);
        long ans=0;
        for(long i=1;i<=m;i++)
        {
            string ss=st[i].s1;
            string sss=st[i].s2;
            long cost=st[i].c;
            string rss=root(ss);
            string rsss=root(sss);
            if(rss!=rsss)
            {
                xs[rss]=xs[rsss];
                ans+=cost;
            }

        }
        for(long i=0;i<v.size();i++)
        {
            string ss=root(v[i]);
            xs[v[i]]=ss;
        }
        string ss=xs[v[0]];
        long f=0;
        for(long i=1;i<v.size();i++)
        {
            if(xs[v[i]]!=ss)
            {
                f=1;
            }
        }
        if(f==1)cout<<"Case "<<++tc<<": Impossible"<<endl;
        else cout<<"Case "<<++tc<<": "<<ans<<endl;

    }
    return 0;
}