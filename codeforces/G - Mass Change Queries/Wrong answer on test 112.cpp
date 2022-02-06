/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/26/2019 16:53                        
*  solution_verdict: Wrong answer on test 112                language: GNU C++14                               
*  run_time: 608 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/911/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
 const unsigned long mx=(1ULL<<64)-1;
const int sz=3126;//64 multiplied
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
  unsigned long bt[sz];
  void clear(){for(int i=0;i<sz;i++)bt[i]=0;}
  bool ck(int i){return (bool)(bt[i/64]&(1ULL<<(i%64)));}
  void set1(int i){bt[i/64]|=(1ULL<<(i%64));}
  void set0(int i){bt[i/64]&=(mx^(1ULL<<(i%64)));}
  void set1(int lt,int rt)
  {
    if(lt/64==rt/64){bt[lt/64]|=on[lt%64][rt%64];return ;}
    bt[lt/64]|=on[lt%64][63];bt[rt/64]|=on[0][rt%64];
    for(int i=lt/64+1;i<rt/64;i++)bt[i]=mx;
  }
  void set0(int lt,int rt)
  {
    if(lt/64==rt/64){bt[lt/64]&=of[lt%64][rt%64];return ;}
    bt[lt/64]&=of[lt%64][63];bt[rt/64]&=of[0][rt%64];
    for(int i=lt/64+1;i<rt/64;i++)bt[i]=0ULL;
  }
  void dOr(bitSet &st,int lt,int rt)
  {
    if(lt/64==rt/64){bt[lt/64]|=(st.bt[lt/64]&on[lt%64][rt%64]);return ;}
    bt[lt/64]|=(st.bt[lt/64]&on[lt%64][63]);
    bt[rt/64]|=(st.bt[rt/64]&on[0][rt%64]);
    for(int i=lt/64+1;i<rt/64;i++)bt[i]|=st.bt[i];
  }
}bst[102];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();
   for(int i=1;i<=100;i++)bst[i].clear();
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    bst[x].set1(i);
  }
  int q;cin>>q;
  while(q--)
  {
    int lt,rt,vl,cg;cin>>lt>>rt>>vl>>cg;
    bst[cg].dOr(bst[vl],lt,rt);
    bst[vl].set0(lt,rt);
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=100;j++)
    {
      if(bst[j].ck(i))cout<<j<<" ";
    }
  }
  cout<<endl;
  return 0;
}