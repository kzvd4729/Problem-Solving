/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2020 12:34                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 264 ms                                          memory_used: 123500 KB                            
*  problem: https://codeforces.com/contest/777/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,R=1e9;
string s[N+2];map<int,long>bit;
 const int sz=1e7;//more size better
int key[sz+2];long val[sz+2];//can be any data type
static inline int h(int x){return((x^179)*7LL)%sz;}
void init()
{
  memset(key,-1,sizeof key);//-1 is invalid
}
void add(int x,long y)
{
  int k=h(x);
  while(key[k]!=-1&&key[k]!=x)k=(k+1)%sz;//first non-taken index
  key[k]=x,val[k]=max(val[k],y);
}
long gtt(int x)
{
  for(int k=h(x);key[k]!=-1;k=(k+1)%sz)
    if(key[k]==x)return val[k];
  return -1;
}
 void upd(int x,long vl)
{
  for( ;x<=R;x+=x&-x)add(x,vl);
}
long get(int x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)ret=max(ret,gtt(x));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<vector<int> >v(n);init();
  for(int i=0;i<n;i++)
  {
    v[i].resize(3);cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
    if(a[1]==b[1])return a[0]>b[0];
    return a[1]>b[1];
  });
  long ans=0;
  for(int i=0;i<n;i++)
  {
    long now=get(v[i][1]-1)+v[i][2];
    ans=max(ans,now);upd(v[i][0],now);
  }
  cout<<ans<<endl;
  return 0;
}