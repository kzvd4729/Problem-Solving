/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-16 00:29:00                      
*  solution_verdict: Runtime error (SIGSEGV)                 language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-DISUBSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[3000],cur,last,sz,t;
string s;
struct automata
{
    long len,link;
    map<long,long>next;
}st[3000];
void _clear(void)
{
    for(long i=0; i<3000; i++)
    {
        st[i].len=0;
        st[i].link=0;
        st[i].next.clear();
    }
    st[0].link=-1;
}
void insrt(long c)
{
    long cur,p,q,cl;
    cur=++sz;
    st[cur].len=st[last].len+1;
    for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)st[p].next[c]=cur;
    if(p==-1)st[cur].link=0;
    else
    {
        q=st[p].next[c];
        if(st[p].len+1==st[q].len)st[cur].link=q;
        else
        {
            cl=++sz;
            st[cl].len=st[p].len+1;
            st[cl].next=st[q].next;
            st[cl].link=st[q].link;
            for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=cl;
            st[q].link=st[cur].link=cl;
        }
    }
    last=cur;
}
long dfs(long node)
{
    if(dp[node])return dp[node];
    long cnt=1;
    for(auto x:st[node].next)cnt+=dfs(x.second);
    return dp[node]=cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        _clear();
        memset(dp,0,sizeof(dp));

        cin>>s;
        for(auto x:s)insrt(x);
        cout<<dfs(0)-1<<endl;
    }
    return 0;
}