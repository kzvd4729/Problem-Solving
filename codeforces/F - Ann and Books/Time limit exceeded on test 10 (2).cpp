/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2020 15:10                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 242400 KB                            
*  problem: https://codeforces.com/contest/877/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long 
using namespace std;
const int N=1e5,mod=1e9+7;
int ty[N+2],aa[N+2],bl[N+2],k;
 /////////////////////////////////////////////////////
const int sz=1e7;//more size better
const long inv=1e18;
long key[2][sz+2];
int val[2][sz+2];//can be any data type
long buf[N+2],ind,buf2[N+2],ind2;
static inline int h(long x){return (((x^179)*7LL)%sz+sz)%sz;}
void init()
{
  for(int i=0;i<2;i++)
    for(int i=0;i<sz;i++)key[0][i]=inv,key[1][i]=inv;
}
void add(int id,long x,int ad)
{
  int k=h(x);
  while(key[id][k]!=inv&&key[id][k]!=x)k=(k+1)%sz;//first non-taken index
  key[id][k]=x,val[id][k]+=ad;
  if(id==0)buf[++ind]=k;
  else buf2[++ind2]=k;
}
void ass(int id,long x,int ad)
{
  int k=h(x);
  while(key[id][k]!=inv&&key[id][k]!=x)k=(k+1)%sz;//first non-taken index
  key[id][k]=x,val[id][k]=ad;
  if(id==0)buf[++ind]=k;
  else buf2[++ind2]=k;
}
int get(int id,long x)
{
  for(int k=h(x);key[id][k]!=inv;k=(k+1)%sz)
  {
    if(key[id][k]==x)
      return val[id][k];
  }
  return 0;
}
void clear()
{
  for(int i=1;i<=ind;i++)key[0][buf[i]]=inv,val[0][buf[i]]=0;
  ind=0;
}
void clear2()
{
  for(int i=1;i<=ind2;i++)key[1][buf2[i]]=inv,val[1][buf2[i]]=0;
  ind2=0;
}
/////////////////////////////////////////////////////
  long ans[N+2];
int brut(int l,int r,int f)
{
  int ret=0;long pr=0,sm=0;
  for(int i=l;i<=r;i++)pr+=aa[i];
  clear();ass(0,0,1);add(1,0,-f);
  ret=get(1,-k-pr);
  for(int i=l;i<=r;i++)
  {
    sm+=aa[i];ret+=get(0,sm+k);
    if(i<r&&f)ret+=get(1,sm-k-pr);
    add(0,sm,1);
  }
  //cout<<"*ret"<<ret<<endl;
  add(1,0,f);return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();int n;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>ty[i];
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];if(ty[i]==1)aa[i]*=-1;
  }
  //for(int i=1;i<=n;i++)cout<<aa[i]<<" ";cout<<endl;
  int magic=100;
  for(int i=1;i<=n;i++)bl[i]=i/magic+1;
  int q;cin>>q;vector<vector<int> >qr;
  for(int i=1;i<=q;i++)
  {
    int u,v;cin>>u>>v;
    if(bl[u]==bl[v])ans[i]=brut(u,v,0);
    else qr.push_back({u,v,i});
  }
  sort(qr.begin(),qr.end(),[&](vector<int>a,vector<int>b){
    if(bl[a[0]]!=bl[b[0]])return a[0]<b[0];
    return a[1]<b[1];
  });
  int pt=0;
  for(int b=1; ;b++)
  {
    if(pt==qr.size())break;
    int l=(b-1)*magic,r=b*magic-1;
    if(qr[pt][0]>r)continue;
    if(l==0)l=1;if(r>n)r=n;
        clear2();ass(1,0,1);long sm=0,now=0;
    for(int i=r+1;i<=n;i++)
    {
      if(pt==qr.size()||qr[pt][0]>r)break;
      sm+=aa[i];now+=get(1,sm+k);
      add(1,sm,1);
      while(pt<qr.size()&&i==qr[pt][1]&&qr[pt][0]<=r)
      {
        //cout<<"Now "<<now<<endl;
        ans[qr[pt][2]]=now+brut(qr[pt][0],r,1);
        pt++;
      }
    }
    if(r==n)break;
  }
  for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
  return 0;
}