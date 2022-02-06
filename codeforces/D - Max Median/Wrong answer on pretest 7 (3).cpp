/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/18/2021 22:08                        
*  solution_verdict: Wrong answer on pretest 7               language: GNU C++17 (64)                          
*  run_time: 108 ms                                          memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/1486/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5,inf=1e9,mod=1e9+7;
multiset<int>l,r;
 void balance()
{
  if((int)l.size()==0||(int)r.size()==0)return ;
   while(true)
  {
    int a=*r.begin(),b=*l.rbegin();
    if(a>=b)break;
    r.erase(r.find(a));l.erase(l.find(b));
    r.insert(b);l.insert(a);
  }
}
void makeSimilar()
{
  int a=l.size(),b=r.size();
  while((int)l.size()>(int)r.size()+1)
  {
    int x=*l.rbegin();
    r.insert(x);l.erase(l.find(x));
    a--,b++;
  }
  while((int)r.size()>(int)l.size()+1)
  {
    int x=*r.begin();
    l.insert(x);r.erase(r.find(x));
    a++,b--;
  }
}
int get()
{
  int a=l.size(),b=r.size();
  //cout<<a<<" "<<b<<endl;
  //cout<<*l.rbegin()<<" "<<*r.begin()<<endl;
  if(a>=b)return *l.rbegin();
  else return *r.begin(); 
}
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;int mx=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    l.insert(a[i]);
    if(i>k)
    {
      int dl=a[i-k];
      if(l.find(dl)!=l.end())
        l.erase(l.find(dl));
      else r.erase(r.find(dl));
    }
    makeSimilar();
    balance();
     if(i>=k)mx=max(mx,get());
  }
  cout<<mx<<endl;
  return 0;
}