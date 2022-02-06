/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 20:20                        
*  solution_verdict: Memory limit exceeded on test 5         language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/1176/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2750131;
int vis[N+2],mx[N+2];
vector<int>prime;
void seive(void)
{
  vis[1]=1;
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    prime.push_back(i);
    for(int j=i+i;j<=N;j+=i)
      vis[j]=1,mx[j]=max(mx[j],i);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();int n;cin>>n;multiset<int>st;
  for(int i=1;i<=n+n;i++){int x;cin>>x;st.insert(x);}
  while(st.size())
  {
    int x=*st.rbegin();st.erase(st.find(x));
    if(!vis[x])
    {
      int id=lower_bound(prime.begin(),prime.end(),x)-prime.begin();
      id++;cout<<id<<" ";st.erase(st.find(id));
    }
    else
    {
      cout<<x<<" ";
      st.erase(st.find(mx[x]));
    }
  }
  cout<<endl;
  return 0;
}