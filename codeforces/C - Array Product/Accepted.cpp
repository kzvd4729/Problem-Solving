/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2018 22:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 795 ms                                          memory_used: 9300 KB                              
*  problem: https://codeforces.com/contest/1042/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int arr[N+2],mx=-2e9,id,cnt,n,ans;
vector<int>zero;set<int>st;
void extra(void)
{
  if(!id)
  {
    id=zero.back();
    zero.pop_back();
  }
  while(zero.size())
  {
    if(ans==n-1)exit(0);
    cout<<1<<" "<<zero.back()<<" "<<id<<endl;
    ans++;
    st.erase(zero.back());zero.pop_back();
  }
  if(ans==n-1)exit(0);
  cout<<2<<" "<<id<<endl;
  ans++;
  st.erase(id);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;for(int i=1;i<=n;i++)st.insert(i);
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(arr[i]==0)zero.push_back(i);
    else if(arr[i]<0)
    {
      if(arr[i]>mx)mx=arr[i],id=i;
      cnt++;
    }
  }
  if(cnt%2==0)id=0;
  if(id||zero.size())extra();
  int pr=*st.begin();st.erase(pr);
  while(st.size())
  {
    if(ans==n-1)exit(0);
    cout<<1<<" "<<*st.begin()<<" "<<pr<<endl;
    ans++;
    st.erase(*st.begin());
  }
  return 0;
}