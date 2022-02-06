/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2020 21:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1427/problem/B
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
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;string s;cin>>s;
    set<pair<int,int> >st;vector<int>p;
    for(int i=0;i<n;i++)
      if(s[i]=='W')p.push_back(i);
    if((int)p.size()==0)
    {
      if(k==0)cout<<0<<'\n';
      else cout<<(k-1)*2+1<<'\n';
      continue;
    }
    for(int i=1;i<p.size();i++)
    {
      if(p[i]-p[i-1]-1)st.insert({p[i]-p[i-1]-1,p[i-1]+1});
    }
    //for(auto x:st)cout<<x.first<<" "<<x.second<<endl;
    while(st.size())
    {
      if(k==0)break;
      pair<int,int>p=*st.begin();st.erase(p);
      k--;
      s[p.second]='W';p.first--,p.second++;
      if(p.first)st.insert(p);
    }
    for(int i=1;i<s.size();i++)
      if(s[i]=='L'&&k&&s[i-1]=='W')k--,s[i]='W';
    for(int i=s.size()-2;i>=0;i--)
      if(s[i]=='L'&&k&&s[i+1]=='W')k--,s[i]='W';
    int ans=0;if(s[0]=='W')ans++;
    //cout<<s<<endl;
    for(int i=1;i<s.size();i++)
    {
      if(s[i]=='W')
      {
        if(s[i-1]=='W')ans+=2;
        else ans++;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}