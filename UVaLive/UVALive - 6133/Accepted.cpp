/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-13 16:06:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 2462                                       memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6133
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,id;
string s[100005];
struct dat
{
    long link[27];
    long f;
} trie[1000006];
void insrt(string x)
{
    long now=0;
    for(long i=0; i<x.size(); i++)
    {
        long z=x[i]-'a';
        if(trie[now].link[z]==-1)trie[now].link[z]=++id;
        now=trie[now].link[z];
    }
    trie[now].f=1;
}
long qury(string x)
{
    long now=0,cnt=0;
    for(long i=0; i<x.size(); i++)
    {
        long c=0;
        for(long j=0; j<27; j++)
        {
            if(trie[now].link[j]!=-1)c++;
        }
        if(c>1||trie[now].f==1)cnt++;
        now=trie[now].link[x[i]-'a'];
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        memset(trie,-1,sizeof(trie));

        trie[0].f=1;
        id=0;
        for(long i=1; i<=n; i++)
        {
            cin>>s[i];
            insrt(s[i]);
        }
        long sum=0;
        for(long i=1; i<=n; i++)
        {
            ///cout<<qury(s[i])<<endl;
            sum+=qury(s[i]);
        }
        double ans=(double)sum/(double)n;
        cout<<setprecision(2)<<fixed<<ans<<endl;
    }
    return 0;
}