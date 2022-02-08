/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2021 14:01:17                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.07 sec                                        memory_used: 34.6M                                
*  problem: https://www.codechef.com/APRIL21A/problems/MEXSTR
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int nxt[N+2][2],d[N+2],ls[N+2],pr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;set<int>st;
    for(auto x:s)st.insert(x-'0');
    if((int)st.size()==1)
    {
      cout<<((*st.begin())^1)<<'\n';
      continue;
    }
    reverse(s.begin(),s.end());
    while(s.back()=='0')s.pop_back();
    reverse(s.begin(),s.end());
    //cout<<s<<endl;
    int n=s.size();
    int zr=n,on=n;
    for(int i=n-1;i>=0;i--)
    {
      nxt[i][0]=zr,nxt[i][1]=on;
      if(s[i]=='0')zr=i;else on=i;
    }
    // for(int i=0;i<n;i++)
    // {
    //   cout<<i<<" "<<nxt[i][0]<<" "<<nxt[i][1]<<endl;
    // }
    for(int i=1;i<=n;i++)d[i]=inf;
    queue<int>q;q.push(0);
    while((int)q.size())
    {
      int u=q.front();q.pop();
      if(u==n)continue;
      if(d[u]+1<d[nxt[u][0]])
      {
        d[nxt[u][0]]=d[u]+1;
        ls[nxt[u][0]]=0;q.push(nxt[u][0]);
        pr[nxt[u][0]]=u;
      }
      if(d[u]+1<d[nxt[u][1]])
      {
        d[nxt[u][1]]=d[u]+1;
        ls[nxt[u][1]]=1;q.push(nxt[u][1]);
        pr[nxt[u][1]]=u;
      }
    }
    vector<int>ans;int nd=n;
    while(nd)
    {
      ans.push_back(ls[nd]);
      nd=pr[nd];
    }
    //cout<<d[n]<<endl;
    cout<<1;
    for(int i=(int)ans.size()-1;i>=0;i--)cout<<ans[i];
      cout<<'\n';
  }
  return 0;
}