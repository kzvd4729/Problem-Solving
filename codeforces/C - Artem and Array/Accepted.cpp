/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/15/2018 22:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 156 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/442/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,ans;
stack<long>st;
vector<long>v;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>x;st.push(x);
    while(st.size()>=3)
    {
      long c=st.top();st.pop();
      long b=st.top();st.pop();
      long a=st.top();
       if(b<=a&&b<=c)
      {
        ans+=min(a,c);
        st.push(c);
      }
      else
      {
        st.push(b);st.push(c);
        break;
      }
    }
  }
  while(st.size())
  {
    v.push_back(st.top());
    st.pop();
  }
  reverse(v.begin(),v.end());
  long mx=-1,id=0;
  for(long i=0;i<v.size();i++)
  {
    if(v[i]>mx)
    {
      mx=v[i];
      id=i;
    }
  }
  long lt=id-1,rt=id+1;
  for(long i=rt+1;i<v.size();i++)
    ans+=v[i];
  for(long i=lt-1;i>=0;i--)
    ans+=v[i];
  if(lt>=0&&rt<v.size())
    ans+=min(v[lt],v[rt]);
   cout<<ans<<endl;
  return 0;
}