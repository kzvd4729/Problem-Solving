/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-01 18:33:25                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 71 ms                                           memory_used: 51740 KB                             
*  problem: https://atcoder.jp/contests/abc157/tasks/abc157_e
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5,inf=1e9;
int bit[26][N+2];
void upd(int i,int x,int vl)
{
  for( ;x<=N;x+=x&-x)bit[i][x]+=vl;
}
int get(int i,int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[i][x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  for(int i=1;i<=n;i++)
  {
    int c=s[i-1]-'a';upd(c,i,1);
  }
  //cout<<"here"<<endl;
  int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int id;cin>>id;char ch;cin>>ch;
       upd(s[id-1]-'a',id,-1);s[id-1]=ch;
      upd(s[id-1]-'a',id,1);
    }
    else
    {
      int l,r;cin>>l>>r;
      int cnt=0;
      for(int i=0;i<26;i++)
        cnt+=(bool)(get(i,r)-get(i,l-1));
      cout<<cnt<<"\n";
    }
  }
  return 0;
}