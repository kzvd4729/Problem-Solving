/****************************************************************************************
*  @author: kzvd4729                                         created: 10-11-2018 01:43:00                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.18 sec                                        memory_used: 111.9M                               
*  problem: https://www.codechef.com/NOV18A/problems/BINSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int nw,ans[N+2];
string ss[N+2];
struct query
{
  int lt,rt,id;
  string sr;
}qr[N+2];
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
  for(int i=1;i<=n;i++)
  {
    cin>>ss[i];sz=max(sz,(int)ss[i].size());
  }
  for(int i=1;i<=q;i++)
  {
    cin>>qr[i].lt>>qr[i].rt>>qr[i].sr;
    qr[i].id=i;
    sz=max(sz,(int)qr[i].sr.size());
  }
  for(int i=1;i<=n;i++)
    ss[i]=parse(ss[i],sz);
  for(int i=1;i<=q;i++)
    qr[i].sr=parse(qr[i].sr,sz);
  // for(int i=1;i<=n;i++)
  //   cout<<ss[i]<<endl;
  // for(int i=1;i<=q;i++)
  //   cout<<qr[i].sr<<endl;
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