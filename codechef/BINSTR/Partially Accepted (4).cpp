/****************************************************************************************
*  @author: kzvd4729                                         created: 10-11-2018 02:21:32                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.19 sec                                        memory_used: 229.5M                               
*  problem: https://www.codechef.com/NOV18A/problems/BINSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int nw,ans[N+2],cnt[N+2];
string ss[N+2];
vector<int>vv[N+2];
struct query
{
  int lt,rt,id;
  string sr;
}qr[N+N+N+2];
struct trie
{
  int next[2],ls;
}tr[N+2];
string parse(string tmp,int sz)
{
  reverse(tmp.begin(),tmp.end());
  while(tmp.size()<sz)tmp.push_back('0');
  reverse(tmp.begin(),tmp.end());
  return tmp;
}
bool cmp(query A,query B)
{
  return A.lt<B.lt;
}
void insrt(string s,int id)
{
  int now=0;
  for(auto x:s)
  {
    int z=x-'0';
    if(!tr[now].next[z])tr[now].next[z]=++nw;
    now=tr[now].next[z];
    tr[now].ls=id;
  }
}
int qry(string s,int rt)
{
  int now=0;
  for(auto x:s)
  {
    int z=x-'0';
    if(tr[now].next[!z]&&tr[tr[now].next[!z]].ls<=rt)now=tr[now].next[!z];
    else now=tr[now].next[z];
  }
  return tr[now].ls;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q,sz=0;cin>>n>>q;
  set<int>ds;
  for(int i=1;i<=n;i++)
  {
    cin>>ss[i];sz=max(sz,(int)ss[i].size());
    ds.insert((int)ss[i].size());
    cnt[(int)ss[i].size()]++;
    vv[(int)ss[i].size()].push_back(i);
  }
  while((int)ds.size()>20)
  {
    set<int>::iterator it,ti;long mn=1e14,on,tw;
    for(ti=ds.begin();ti!=ds.end();ti++)
    {
      it=ti;ti++;
      if(ti==ds.end())break;
      long here=((*ti-*it)*1LL)*cnt[*it];
      if(here<mn)
      {
        mn=here;on=*it,tw=*ti;
      }
    }
    for(auto x:vv[on])
    {
      ss[x]=parse(ss[x],tw);
    }
    cnt[tw]+=cnt[on];
    while(vv[on].size())
    {
      vv[tw].push_back(vv[on].back());
      vv[on].pop_back();
    }
    ds.erase(on);
  }
  for(int i=1;i<=q;i++)
  {
    cin>>qr[i].lt>>qr[i].rt>>qr[i].sr;
    qr[i].id=i;
  }
  sort(qr+1,qr+q+1,cmp);
  int pt=n;
  for(int i=q;i>=1;i--)
  {
    while(pt>=1&&pt>=qr[i].lt)
    {
      insrt(ss[pt],pt);
      pt--;
    }
    ans[qr[i].id]=qry(qr[i].sr,qr[i].rt);
  }
  for(int i=1;i<=q;i++)
    cout<<ans[i]<<endl;
  return 0;
}