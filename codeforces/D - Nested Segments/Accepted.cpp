/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2018 15:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 764 ms                                          memory_used: 22800 KB                             
*  problem: https://codeforces.com/contest/652/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,cnt,ans[200005],bit[400005];
vector<int>vec;
map<int,int>mp;
struct data
{
  int l,r,id;
}seg[200005];
bool cmp(data A,data B)
{
  return A.l<B.l;
}
void upd(int idx)
{
  for( ;idx<=2*n;idx+=idx&-idx)bit[idx]++;
}
int query(int idx)
{
  int sum=0;
  for( ;idx>0;idx-=idx&-idx)sum+=bit[idx];
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>seg[i].l>>seg[i].r;
    seg[i].id=i;
    vec.push_back(seg[i].l);
    vec.push_back(seg[i].r);
  }
  sort(seg+1,seg+n+1,cmp);
  sort(vec.begin(),vec.end());
  for(auto x:vec)if(!mp[x])mp[x]=++cnt;
  for(int i=1;i<=n;i++)
  {
    seg[i].l=mp[seg[i].l];
    seg[i].r=mp[seg[i].r];
  }
  for(int i=n;i>=1;i--)
  {
    ans[seg[i].id]=query(seg[i].r);
    upd(seg[i].r);
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
  return 0;
}