/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/01/2018 21:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/552/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e3;
long mx;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;s="1*"+s+"*1";
   for(long i=0;i<s.size();i++)
  {
    for(long j=i+1;j<s.size();j++)
    {
      if(s[i]=='*'&&s[j]=='*')
      {
        stack<long>st;st.push(s[i+1]-'0');
        for(long k=i+3;k<j;k+=2)
        {
          if(s[k-1]=='+')
            st.push(s[k]-'0');
          else
          {
            long tp=st.top();st.pop();
            tp*=(s[k]-'0');st.push(tp);
          }
        }
        long ans=0;while(st.size()){ans+=st.top();st.pop();}
        st.push(1);
        for(long k=2;k<s.size();k+=2)
        {
          if(k>i&&k<j)
          {
            long tp=st.top();st.pop();
            tp*=ans;st.push(tp);
            k=j-1;continue;
          }
          if(s[k-1]=='+')
            st.push(s[k]-'0');
          else
          {
            long tp=st.top();st.pop();
            tp*=(s[k]-'0');st.push(tp);
          }
        }
        long out=0;while(st.size()){out+=st.top();st.pop();}
        mx=max(mx,out);
      }
    }
  }
  cout<<mx<<endl;
  return 0;
}