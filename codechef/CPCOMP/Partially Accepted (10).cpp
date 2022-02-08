/****************************************************************************************
*  @author: kzvd4729                                         created: 10-10-2018 00:47:55                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.27 sec                                        memory_used: 29.8M                                
*  problem: https://www.codechef.com/OCT18A/problems/CPCOMP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int fr[N+2],vis[N+2];
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
  while(v!=0)
  {
    int r=u%v;
    u=v;v=r;
  }
  return u;
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
    int bg=*st.begin();vector<int>er;
    er.push_back(bg);
    ans++;int cnt=0;st.erase(bg);
    while(true)
    {
      vector<int>tmp;cnt++;
      for(auto x:er)
      {
        for(auto z:st)
        {
          if(_gcd(x,z)==1)
          {
            tmp.push_back(z);
          }
        }
        for(auto z:tmp)st.erase(z);
      }
      if(tmp.size()==0)break;
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