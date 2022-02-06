/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/15/2018 22:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/430/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e4;
int n,arr[N+2],k;
stack<pair<int,int> >st;
int ck(void)
{
  int ret=0;while(st.size())st.pop();
  for(int i=0;i<=n;i++)
  {
    if(st.size()==0)
    {
      st.push({arr[i],1});
      continue;
    }
    pair<int,int>p=st.top();
    if(arr[i]==p.first)
    {
      p.second++;st.pop();
      st.push(p);
    }
    else
    {
      while(st.size())
      {
        if(st.top().second>=3)
        {
          ret+=st.top().second;
          st.pop();
        }
        else break;
      }
      if(st.size()==0)
      {
        st.push({arr[i],1});
        continue;
      }
      p=st.top();
      if(arr[i]==p.first)
      {
        p.second++;st.pop();
        st.push(p);
      }
      else st.push({arr[i],1});
    }
  }
  while(st.size())
  {
    if(st.top().second>=3)
    {
      ret+=st.top().second;
      st.pop();
    }
    else break;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k>>arr[0];
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    ans=max(ans,ck());
    swap(arr[i],arr[i-1]);
  }
  ans=max(ans,ck());
  if(ans)ans--;
  cout<<ans<<endl;
  return 0;
}