/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 19:32                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 2402 ms                                         memory_used: 83100 KB                             
*  problem: https://codeforces.com/contest/1190/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6,R=1e9;
map<int,int>bit;
void upd(int x,int vl)
{
  for( ;x<=R;x+=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int get(int l,int r)
{
  return get(r)-get(l-1);
}
void makeOn(int x)
{
  if(get(x,x))return;upd(x,1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<pair<int,int> >v(n);
  for(int i=0;i<n;i++)cin>>v[i].second>>v[i].first;
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   reverse(v.begin(),v.end());
   long ans=0;
  for(int i=0;i<v.size(); )
  {
    int j;vector<int>bf;
    for(j=i;j<v.size();j++)
    {
      if(v[i].first!=v[j].first)break;
      bf.push_back(v[j].second);
      makeOn(v[j].second);//cout<<i<<" "<<v[j].second<<endl;
    }
    i=j;
    bf.push_back(0);
    reverse(bf.begin(),bf.end());
    for(j=1;j<bf.size();j++)
    {
      //cout<<get(bf[j-1]+1,bf[j])<<" "<<get(bf[j],R)<<endl;
      //cout<<bf[j]<<" ";
      ans+=1LL*get(bf[j-1]+1,bf[j])*get(bf[j],R);
    }
    cout<<endl<<endl;
  }
  cout<<ans<<endl;
  return 0;
}