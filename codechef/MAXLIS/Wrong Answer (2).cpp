/****************************************************************************************
*  @author: kzvd4729                                         created: 10-10-2019 14:42:16                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 41.7M                                
*  problem: https://www.codechef.com/OCT19A/problems/MAXLIS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
const int N=1e6;
int bit[N+2];
vector<int>u[N+2];
void upd(int x,int vl,int n)
{
  for( ;x<=n;x+=x&-x)
    bit[x]=max(bit[x],vl);
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
    ret=max(ret,bit[x]);
  return ret;
}
int lis(vector<int>&v)
{
  for(int i=1;i<=v.size();i++)bit[i]=0;
  int ret=0;
  for(auto &x:v)
  {
    int now=get(x-1)+1;ret=max(ret,now);
    upd(x,now,v.size());
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int sg=n/k;
  for(int i=1;i<k;i++)
  {
    for(int j=(i-1)*sg;j<i*sg;j++)
      u[i].push_back(v[j]);
  }
  for(int j=(k-1)*sg;j<n;j++)
    u[k].push_back(v[j]);
  vector<int>a;
  for(int i=1;i<=k;i++)a.push_back(i);
  int loop=50,mx=-1;vector<int>c,ans;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while(loop--)
  {
    shuffle(a.begin(),a.end(),rng);c.clear();
    for(auto &x:a)
    {
      for(auto &z:u[x])
        c.push_back(z);
    }
    //P(c);
    int now=lis(c);//cout<<now<<endl;
    if(now>mx)mx=now,ans=c;
  }
  //cout<<ans.size()<<endl;exit(0);
  for(int i=0;i<n;i++)
  {
    if(i)cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  //cout<<mx<<endl;
  return 0;
}