/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 15100 KB                             
*  problem: https://codeforces.com/gym/100009/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
/**************** Hash ******************/
const long mod1=1000001011,mod2=1000009999;
const int b1=193,b2=307;
long pw1[N+2],pw2[N+2];
void Call(int n)
{
  pw1[0]=1;pw2[0]=1;
  for(int i=1;i<=n;i++)
  {
    pw1[i]=(pw1[i-1]*b1)%mod1;
    pw2[i]=(pw2[i-1]*b2)%mod2;
  }
}
struct Hash
{
  string s;vector<pair<long,long> >v;
  pair<long,long>make_hash(void)
  {
    long hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(hs1*b1+x)%mod1;
      hs2=(hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<long,long>segment(int lt,int rt)
  {
    long x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=(x-(v[lt-1].first*pw1[rt-lt+1])%mod1+mod1)%mod1;
    y=(y-(v[lt-1].second*pw2[rt-lt+1])%mod2+mod2)%mod2;
    return {x,y};
  }
}Hs[N+2];
/////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;int id=0;set<pair<int,int> >st;
  pair<int,int>pp[N+2];Call(N);
  while(cin>>s)
  {
    //if(s=="-1")break;
    Hs[++id].s=s;
  }
  for(int i=1;i<=id;i++)
    st.insert(Hs[i].make_hash());
  vector<string>ans;
  for(int i=1;i<=id;i++)
  {
    int n=Hs[i].s.size()-1;
    for(int j=0;j<n;j++)
    {
      pair<long,long>p1=Hs[i].segment(0,j);
      pair<long,long>p2=Hs[i].segment(j+1,n);
      if(st.find(p1)!=st.end())
      {
        if(st.find(p2)!=st.end())
        {
          ans.push_back(Hs[i].s);
          break;
        }
      }
    }
  }
  sort(ans.begin(),ans.end());
  for(auto x:ans)
    cout<<x<<endl;
  return 0;
}