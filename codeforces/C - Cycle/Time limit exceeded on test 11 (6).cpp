/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2019 16:37                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 6400 KB                              
*  problem: https://codeforces.com/contest/117/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
 const unsigned long mx=(1ULL<<64)-1;
const int sz=80;//64 multiplied
unsigned long on[64][64],of[64][64];
void init()
{
  for(int i=0;i<64;i++)
  {
    for(int j=i;j<64;j++)
    {
      if(j==i)on[i][j]=(1ULL<<j);
      else on[i][j]=on[i][j-1]|(1ULL<<j);
      of[i][j]=mx^on[i][j];
    }
  }
}
struct bitSet
{
  unsigned long bt[sz];int f;
  void clear(){for(int i=0;i<sz;i++)bt[i]=0;f=0;}
  bool ck(int i){return (bool)(bt[i/64]&(1ULL<<(i%64)));}
  void set1(int i){bt[i/64]|=(1ULL<<(i%64)),f=1;}
  bool dAnd(bitSet &st)
  {
    if(!f||!st.f)return false;
    for(int i=0;i<sz;i++)
      if(__builtin_popcountll(bt[i]&st.bt[i]))return true;
    return false;
  }
}ot[N+2],in[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;init();
  for(int i=0;i<n;i++)in[i].clear();
  for(int i=0;i<n;i++)ot[i].clear();
  for(int i=0;i<n;i++)
  {
    string s;cin>>s;
    for(int j=0;j<n;j++)
      if(s[j]=='1')ot[i].set1(j),in[j].set1(i);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(ot[i].ck(j)&&in[i].dAnd(ot[j]))
      {
        cout<<i+1<<" "<<j+1<<" ";
        for(int k=0;k<n;k++)
          if(in[i].ck(k)&ot[j].ck(k))
            cout<<k+1<<endl,exit(0);
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}