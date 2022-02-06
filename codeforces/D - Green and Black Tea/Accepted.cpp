/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 01:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/746/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,a,b;
string ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k>>a>>b;
  int cnt=0;
  char last='A';
  for(int i=1;i<=n;i++)
  {
    if(a>=b)
    {
      if(last=='G')
      {
        if(cnt<k)
        {
          ans.push_back('G');
          last='G';
          a--;
          cnt++;
        }
        else
        {
          ans.push_back('B');
          last='B';
          b--;
          cnt=1;
        }
      }
      else
      {
        ans.push_back('G');
        last='G';
        a--;
        cnt=1;
      }
    }
    else
    {
      if(last=='B')
      {
        if(cnt<k)
        {
          ans.push_back('B');
          last='B';
          b--;
          cnt++;
        }
        else
        {
          ans.push_back('G');
          last='G';
          a--;
          cnt=1;
        }
      }
      else
      {
        ans.push_back('B');
        last='B';
        b--;
        cnt=1;
      }
    }
  }
  if(a!=0||b!=0)cout<<"NO"<<endl;
  else cout<<ans<<endl;
  return 0;
}