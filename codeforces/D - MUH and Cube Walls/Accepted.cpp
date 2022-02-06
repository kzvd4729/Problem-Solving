/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/25/2018 20:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 42900 KB                             
*  problem: https://codeforces.com/contest/471/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int sz,last,cnt[400010],n,w,arr[200005],xrr[200005];
struct automata
{
    int len,link;
    map<int,int>next;
}st[400010];
set<pair<int,int> >base;
void insrt(int c)
{
    int cur,p,q,cl;
    cur=++sz;
    st[cur].len=st[last].len+1;
    cnt[cur]=1;
    base.insert({-st[cur].len,cur});
    for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
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
            st[cl].next=st[q].next;
            st[cl].link=st[q].link;
            for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>w;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=w;i++)cin>>xrr[i];
    if(w==1)
    {
        cout<<n<<endl;
        return 0;
    }
    for(int i=1;i<n;i++)arr[i]=arr[i+1]-arr[i];
    for(int i=1;i<w;i++)xrr[i]=xrr[i+1]-xrr[i];
    n--;
    w--;
     st[0].link=-1;
    for(int i=1;i<=n;i++)insrt(arr[i]);
    for(set<pair<int,int> >::iterator it=base.begin();it!=base.end();it++)
    {
        ///cout<<it->first<<" "<<it->second<<" "<<st[it->second].link<<endl;
        if(st[it->second].link==-1)continue;
        cnt[st[it->second].link]+=cnt[it->second];
    }
//    for(int i=0;i<=20;i++)
//    {
//        cout<<cnt[i]<<" ";
//    }
//    cout<<endl;
    int f=0,now=0;
    for(int i=1;i<=w;i++)
    {
        if(st[now].next[xrr[i]])now=st[now].next[xrr[i]];
        else
        {
            f=1;
            break;
        }
    }
    if(f==1)cout<<0<<endl;
    else cout<<cnt[now]<<endl;
    return 0;
}