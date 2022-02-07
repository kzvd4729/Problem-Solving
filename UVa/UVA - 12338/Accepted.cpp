/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-18 16:55:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 1140                                            memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12338
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,q,l,r,tc;
string s[100005];
vector<pair<long,long> >H[100005];
void Hash(long id,string s)
{
    long h1=1,h2=1;
    for(int i=0;i<s.size();i++)
    {
        h1=(h1*19+(long)s[i])%100000007;
        h2=(h2*17+(long)s[i])%100000007;
        H[id].push_back(make_pair(h1,h2));
    }
}
long Search(long i,long j)
{
    long lo=0,mid,rt;
    long hi=min(s[i].size(),s[j].size());
    long r=hi-1;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(H[i][mid].first!=H[j][mid].first||H[i][mid].second!=H[j][mid].second)
        {
            hi=mid-1;
        }
        else lo=mid+1;
    }
    rt=0;
    for(long k=max(0LL,mid-2);k<=min(mid+2,r);k++)
    {
        if(H[i][k].first==H[j][k].first&&H[i][k].second==H[j][k].second)
        {
            rt=k+1;
        }
    }
    return rt;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            H[i].clear();
        }
        for(long i=1;i<=n;i++)
        {
            cin>>s[i];
            Hash(i,s[i]);
        }
        cin>>q;
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>l>>r;
            cout<<Search(l,r)<<endl;
        }

    }
    return 0;
}