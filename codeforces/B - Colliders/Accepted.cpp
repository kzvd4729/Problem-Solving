/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2018 17:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 560 ms                                          memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/154/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int vis[N+2],pr[N+2];
vector<int>fc[N+2];
set<int>on;
void factorize(void)
{
 for(int i=2;i<=N;i++)
 {
  if(vis[i])continue;
  for(int j=i;j<=N;j+=i)
  {
   fc[j].push_back(i);vis[j]=1;
  }
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);factorize();
 int n,x;cin>>x>>n;char c;
 for(int i=1;i<=n;i++)
 {
  cin>>c>>x;
  if(c=='+')
  {
   if(on.find(x)==on.end())
   {
    int f=0;
    for(int j=0;j<fc[x].size();j++)
    {
     if(pr[fc[x][j]])
     {
      cout<<"Conflict with "<<pr[fc[x][j]]<<endl;
      f=1;break;
     }
    }
    if(f)continue;
    cout<<"Success"<<endl;on.insert(x);
    for(int j=0;j<fc[x].size();j++)
     pr[fc[x][j]]=x;
   }
   else cout<<"Already on"<<endl;
  }
  else
  {
   if(on.find(x)==on.end())
    cout<<"Already off"<<endl;
   else
   {
    cout<<"Success"<<endl;
    on.erase(x);
    for(int j=0;j<fc[x].size();j++)
     pr[fc[x][j]]=0;
   }
  }
 }
 return 0;
}