/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-10-20 19:50:26                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1255
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int sz,last,cnt[2000010],n,w,tc,t;
char s1[1000006],s2[1000006];
struct automata
{
    int len,link,next[26];
} st[2000010];
set<pair<int,int> >base;
void insrt(int c)
{
    int cur,p,q,cl;
    cur=++sz;
    st[cur].len=st[last].len+1;
    cnt[cur]=1;
    base.insert({-st[cur].len,cur});
    for(p=last; p!=-1&&!st[p].next[c]; p=st[p].link)
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
            cl=++sz;
            st[cl].len=st[p].len+1;
            base.insert({-st[cl].len,cl});
            memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
            st[cl].link=st[q].link;
            for( ; p!=-1&&st[p].next[c]==q; p=st[p].link)
            {
                st[p].next[c]=cl;
            }
            st[q].link=st[cur].link=cl;
        }
    }
    last=cur;
}
int main()
{
 
    scanf("%ld",&t);
    while(t--)
    {
 
        scanf("%s%s",s1,s2);
        memset(st,0,sizeof(st));
        memset(cnt,0,sizeof(cnt));
        st[0].link=-1;
        last=0;
        sz=0;
        base.clear();
        for(int i=0; i<strlen(s1); i++)insrt(s1[i]-'a');
 
        for(set<pair<int,int> >::iterator it=base.begin(); it!=base.end(); it++)
        {
            if(st[it->second].link==-1)
                continue;
            cnt[st[it->second].link]+=cnt[it->second];
        }
        int f=0,now=0;
        for(int i=0; i<strlen(s2); i++)
        {
            if(st[now].next[s2[i]-'a'])
                now=st[now].next[s2[i]-'a'];
            else
            {
                f=1;
                break;
            }
        }
        if(f==1)printf("Case %ld: %ld\n",++tc,0);
        else printf("Case %ld: %ld\n",++tc,cnt[now]);
    }
    return 0;
}