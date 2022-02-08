/****************************************************************************************
*  @author: kzvd4729                                         created: 02-11-2018 17:48:04                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.19 sec                                        memory_used: 21.1M                                
*  problem: https://www.codechef.com/NOV18A/problems/HMAPPY1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  deque<int>dq;multiset<int>st;
  for(int i=1;i<=n;i++)
  {
    if(aa[i])
    {
      int j,cnt=0;
      for(j=i;j<=n;j++)
      {
        if(aa[j])cnt++;
        else break;
      }
      i=j-1;
      dq.push_back(cnt);st.insert(cnt);
    }
    else
    {
      dq.push_back(0);st.insert(0);
    }
  }
  string s;cin>>s;
  for(auto x:s)
  {
    if(x=='?')
    {
      auto it=st.rbegin();
      cout<<min(*it,k)<<endl;
    }
    else
    {
      if(!dq.back())
      {
        dq.pop_back();dq.push_back(0);
      }
      else
      {
        int xx=dq.back();dq.pop_back();
        st.erase(st.find(xx));
        if(xx-1)
        {
          dq.push_back(xx-1);
          st.insert(xx-1);
        }
        if(!dq.front())
        {
          dq.push_front(1);
          st.insert(1);
        }
        else
        {
          xx=dq.front();dq.pop_front();
          st.erase(st.find(xx));
          dq.push_front(xx+1);
          st.insert(xx+1);
        }
      }
    }
  }
  return 0;
}