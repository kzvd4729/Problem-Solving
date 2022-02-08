/****************************************************************************************
*  @author: kzvd4729                                         created: 11-10-2018 19:08:35                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.15 sec                                        memory_used: 33.3M                                
*  problem: https://www.codechef.com/OCT18A/problems/CPCOMP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,R=1e6;
int fr[N+2],vis[N+2],loop;
vector<int>fc[N+2];
void seive(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      fc[j].push_back(i);
      vis[j]=1;
    }
  }
}
inline int _gcd(int u,int v)
{
  for(auto x:fc[u])
    if(v%x==0)return 2;
  return 1;
}
int main()
{
  //ifstream cin("out.txt");
  ios_base::sync_with_stdio(0);cin.tie(0);seive();
  int n;cin>>n;set<int>st;
  for(int i=1;i<=n;i++)
  {
    int hr=1;
    int x;cin>>x;for(auto z:fc[x])hr*=z;
    fr[hr]++;st.insert(hr);
  }
  int ans=0;
  while(st.size())
  {
    int bg=*st.begin();
    vector<int>er;er.push_back(bg);
    ans++;int cnt=0;
    while(er.size())
    {
      for(auto x:er)st.erase(x);
      vector<int>tmp;cnt++;
      for(auto z:st)
      {
        if(loop>R)break;
        for(auto x:er)
        {
          if(_gcd(x,z)==1)
          {
            tmp.push_back(z);break;
            loop++;
          }
        }
      }
      er.clear();er=tmp;
    }
    if(cnt<=1)
    {
      ans+=fr[bg]-1;
      for(auto x:st)
        ans+=fr[x];
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}