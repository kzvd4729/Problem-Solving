/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-02 18:30:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 650                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12467
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int sz,last,t;
string fs,rs,ans;
struct automata
{
    int len,link,next[26];
}st[2000010];
void insrt(int c)
{
    int cur,p,q,cl;
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
            memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
            st[cl].link=st[q].link;
            for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=cl;
            st[q].link=st[cur].link=cl;
        }
    }
    last=cur;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        st[0].link=-1;
        last=0,sz=0;
        cin>>rs;
        fs=rs;
        reverse(rs.begin(),rs.end());
        for(int i=0;i<rs.size();i++)insrt(rs[i]-'a');
        int now=0,i=0;
        ans.clear();
        while(true)
        {
            if(st[now].next[fs[i]-'a'])
            {
                ans.push_back(fs[i]);
                now=st[now].next[fs[i]-'a'];
                i++;
            }
            else break;
            if(i==rs.size())break;
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<rs.size()*2;i++)
        {
            st[i].len=0;
            st[i].link=0;
            memset(st[i].next,0,sizeof(st[i].next));
        }
        cout<<ans<<endl;
    }
    return 0;
}