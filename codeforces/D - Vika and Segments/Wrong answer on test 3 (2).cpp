/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2020 13:31                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/610/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9+1;
vector<vector<int> >ver,hor;
void compress(vector<vector<int> >&v)
{
  if(v.size()==0)return ;
  sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b){
    if(a[2]!=b[2])return a[2]<b[2];
    return a[0]<b[0];
  });
  vector<vector<int> >u;
  int lt=v[0][0],rt=v[0][1];
  for(int i=1;i<v.size();i++)
  {
    if((v[i][2]!=v[i-1][2])||(v[i][0]>rt))
    {
      u.push_back({lt,rt,v[i-1][2]});
      lt=v[i][0],rt=v[i][1];
    }
    else rt=max(rt,v[i][1]);
  }
  u.push_back({lt,rt,v.back()[2]});v=u;
}
map<int,int>bit;
void upd(long x,int vl)
{
  for( ;x<=inf+inf;x+=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;a+=inf,b+=inf,c+=inf,d+=inf;
    if(a==c)ver.push_back({min(b,d),max(b,d),a});
    else hor.push_back({min(a,c),max(a,c),b});
  }
  compress(hor);compress(ver);
  long ans=0;
  for(auto x:hor)ans+=x[1]-x[0]+1;
  for(auto x:ver)ans+=x[1]-x[0]+1;
   vector<vector<int> >v;
  for(auto x:hor)
  {
    v.push_back({x[0],x[2],1});
    v.push_back({x[1]+1,x[2],-1});
  }
  sort(v.begin(),v.end());
  int pt=0;
  for(auto x:ver)
  {
    while(pt<v.size()&&v[pt][0]<=x[2])
    {
      upd(v[pt][1],v[pt][2]);pt++;
    }
    ans+=(get(x[0])-get(x[1]));
  }
  cout<<ans<<endl;
  return 0;
}