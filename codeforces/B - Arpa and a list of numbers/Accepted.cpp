/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2018 10:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1029 ms                                         memory_used: 61300 KB                             
*  problem: https://codeforces.com/contest/850/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
const int R=1e6;
int n,x,y,arr[N+2],fr[R+2];
int vis[R+2];
vector<int>fc[R+2];
void factorize(void)
{
 for(int i=2;i<=R;i++)
 {
  if(vis[i])continue;
  for(int j=i;j<=R;j+=i)
  {
   fc[j].push_back(i);vis[j]=1;
  }
 }
}
long whore(int pr)
{
 long ret=0;
 for(int i=1;i<=n;i++)
 {
  int m=arr[i]%pr;
  int rq=(pr-m)%pr;
  long add=min(x*1LL,rq*1LL*y);
  ret+=add;
 }
 return ret;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);factorize();
 cin>>n>>x>>y;
 for(int i=1;i<=n;i++)
 {
  cin>>arr[i];
  for(int j=0;j<fc[arr[i]].size();j++)
   fr[fc[arr[i]][j]]++;
 }
 priority_queue<pair<int,int> >pq;
 for(int i=2;i<=R;i++)pq.push(make_pair(fr[i],i));
 long ans=1e18;
 for(int i=1;i<=60;i++)
 {
  ans=min(ans,whore(pq.top().second));
  pq.pop();
 }
 ans=min(ans,whore(2));
 ans=min(ans,whore(3));
 ans=min(ans,whore(5));
 ans=min(ans,whore(7));
 cout<<ans<<endl;
 return 0;
}