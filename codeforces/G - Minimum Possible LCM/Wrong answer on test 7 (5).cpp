/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2019 23:17                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 1325 ms                                         memory_used: 132500 KB                            
*  problem: https://codeforces.com/contest/1154/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e7;
vector<int>id[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;long ans=1e15;int a=-1,b=-1;
  for(int i=1;i<=n;i++)
  {
    long x;cin>>x;
    id[x].push_back(i);
    if(id[x].size()>1)
    {
      if(x<ans)
      {
        ans=x;a=id[x][0];b=id[x][1];
      }
    }
  }
  for(int i=1;i<=N;i++)
  {
    long na=-1,nb=-1,ia,ib;
    for(int j=i;j<=N;j+=i)
    {
      if(id[j].size()>0)
      {
        if(na==-1)
        {
          na=j;ia=id[j][0];
        }
        else
        {
          nb=j;ib=id[j][0];
          break;
        }
      }
    }
    if(nb==-1)continue;
    long lcm=(na*nb)/__gcd(na,nb);
    if(lcm<ans)ans=lcm,a=ia,b=ib;
  }
  //cout<<ans<<endl;
  cout<<a<<" "<<b<<endl;
  return 0;
}