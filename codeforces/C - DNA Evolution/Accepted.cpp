/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2020 19:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 225700 KB                            
*  problem: https://codeforces.com/contest/827/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
int bit[4][12][12][N+2];
int ret(char c)
{
  if(c=='A')return 0;if(c=='T')return 1;
  if(c=='G')return 2;if(c=='C')return 3;
}
void upd(int c,int nm,int md,int id,int ad)
{
  id++;
  for( ;id<=N;id+=id&-id)
    bit[c][nm][md][id]+=ad;
}
int get(int c,int nm,int md,int id)
{
  id++;int ret=0;
  for( ;id>0;id-=id&-id)
    ret+=bit[c][nm][md][id];
  return ret;
}
void upd(int c,int id,int ad)
{
  for(int j=1;j<=10;j++)
    upd(c,j,id%j,id,ad);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;
  for(int i=0;i<s.size();i++)upd(ret(s[i]),i,1);
  int q;cin>>q;
  while(q--)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int id;char c;cin>>id>>c;id--;
      upd(ret(s[id]),id,-1);s[id]=c;
      upd(ret(s[id]),id,1);
    }
    else
    {
      int lt,rt;cin>>lt>>rt;lt--,rt--;
      string s;cin>>s;int sz=s.size();
       int sm=0;
      for(int i=0;i<s.size();i++)
        sm+=max(0,get(ret(s[i]),sz,(lt+i)%sz,rt)-get(ret(s[i]),sz,(lt+i)%sz,lt-1));
      cout<<sm<<"\n";
    }
  }
  return 0;
}