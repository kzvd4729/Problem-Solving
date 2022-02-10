/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-17 20:43:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 90                                         memory_used (MB): 66.6                            
*  problem: https://vjudge.net/problem/SPOJ-SUBST1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long last,sz,t,cnt[100004];
string s;
struct state
{
    long len,link,next[60];
}st[100004];
void init(void)
{
    last=sz=0;
    st[0].len=0;
    st[0].link=-1;
    memset(st[0].next,-1,sizeof(st[0].next));
    memset(cnt,0,sizeof(cnt));
}
void insrt(long c)
{
    long cur,p,q;
    cur=++sz;
    st[cur].len=st[last].len+1;
    memset(st[cur].next,-1,sizeof(st[cur].next));
    for(p=last;p!=-1&&st[p].next[c]==-1;p=st[p].link)
    {
        st[p].next[c]=cur;
    }
    if(p==-1)
    {
        st[cur].link=0;
    }
    else
    {
        q=st[p].next[c];
        if(st[p].len+1==st[q].len)
        {
            st[cur].link=q;
        }
        else
        {
            long clone=++sz;
            st[clone].len=st[p].len+1;
            st[clone].link=st[q].link;
            memcpy(st[clone].next,st[q].next,sizeof(st[clone].next));
            for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
            {
                st[p].next[c]=clone;
            }
            st[q].link=st[cur].link=clone;
        }
    }
    last=cur;
}
long dfs(long node)
{
    long c=1;
    if(cnt[node])return cnt[node];
    for(long i=0;i<60;i++)
    {
        if(st[node].next[i]!=-1)c+=dfs(st[node].next[i]);
    }
    return cnt[node]=c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        init();
        cin>>s;
        for(auto x:s)insrt(x-'A');
        cout<<dfs(0)-1<<endl;
    }
    return 0;
}