/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2019 16:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/992/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int l,r,x,y;set<pair<int,int> >st;
vector<int>a,b;
int pw(int a,int b)
{
 int ret=1;
 while(b--)ret*=a;
 return ret;
}
void dfs(int i,int n,int m)
{
 if(i>=a.size())
 {
  if(n>=l&&n<=r&&m>=l&&m<=r&&__gcd(n,m)==x)
   st.insert({n,m});
  return ;
 }
 int tn=n*pw(a[i],b[i]);
 for(int j=0;j<=b[i];j++)
 {
  int tm=m*pw(a[i],j);
  dfs(i+1,tn,tm);
 }
 int tm=m*pw(a[i],b[i]);
 for(int j=0;j<=b[i];j++)
 {
  int tn=n*pw(a[i],j);
  dfs(i+1,tn,tm);
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>l>>r>>x>>y;int sq=sqrt(y+1);
 for(int i=2;i<=sq;i++)
 {
  int cnt=0;
  while(y%i==0)
   y/=i,cnt++;
  if(cnt)
   a.push_back(i),b.push_back(cnt);
 }
 if(y!=1)a.push_back(y),b.push_back(1);
 dfs(0,1,1);cout<<st.size()<<endl;
 return 0;
}