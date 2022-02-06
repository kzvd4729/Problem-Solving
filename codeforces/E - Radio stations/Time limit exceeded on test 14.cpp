/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2018 00:57                        
*  solution_verdict: Time limit exceeded on test 14          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 213500 KB                            
*  problem: https://codeforces.com/contest/762/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,R=1e9,F=1e4;
map<int,int>mp,bit[F+2];
struct data
{
  int x,r,f;
}arr[N+2];
bool cmp(data A,data B)
{
  return A.r<B.r;
}
void upd(int fr,int x,int vl)
{
  for( ;x<=R;x+=x&-x)
    bit[fr][x]+=vl;
}
int qry(int fr,int x)
{
  int sum=0;
  for( ;x>0;x-=x&-x)
    sum+=bit[fr][x];
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,cnt=0;cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>arr[i].x>>arr[i].r>>arr[i].f;
  sort(arr+1,arr+n+1,cmp);
  int ans=0;set<int>st;
  for(int i=1;i<=n;i++)
  {
    st.insert(max(arr[i].x-arr[i].r,1));
    st.insert(min(arr[i].x+arr[i].r+1,R));
    st.insert(arr[i].x);
  }
  while(st.size())
  {
    mp[*st.begin()]=++cnt;
    st.erase(st.begin());
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=max(1,arr[i].f-k);j<=min(F,arr[i].f+k);j++)
      ans+=qry(j,mp[arr[i].x]);
    upd(arr[i].f,mp[max(arr[i].x-arr[i].r,1)],1);
    upd(arr[i].f,mp[min(arr[i].x+arr[i].r+1,R)],-1);
  }
  cout<<ans<<endl;
  return 0;
}