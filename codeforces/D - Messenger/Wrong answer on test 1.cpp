/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 13:55                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 17300 KB                             
*  problem: https://codeforces.com/contest/631/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5+1;
const long b=117757711;
int n,m,l,sz,last;
char ch;
struct automata
{
  int link,len,id;
  map<long,int>next;
}st[N+N];
void insrt(long c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=idx;
   int p,q,cl;
  for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
    st[p].next[c]=now;
  if(p==-1)
    st[now].link=0;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  st[0].link=-1;
  for(int i=1;i<=n;i++)
  {
    cin>>l;
    cin.ignore();
    cin>>ch;
    long x=b*l+int(ch);
    insrt(x,i);
  }
  return 0;
}