/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-31 21:32:50                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc022/tasks/agc022_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int vis[1000];
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  for(auto x:s)vis[x-'a']=1;
   if(s.size()<=25)
  {
    cout<<s;
    for(int i=0;i<=25;i++)
    {
      if(vis[i]==0)
      {
        cout<<(char)(i+'a')<<endl;
        return 0;
      }
    }
  }
  for(int i=s.size()-1;i>=0;i--)
  {
    for(int j=s[i]-'a'+1;j<=25;j++)
    {
      if(vis[j]==0)
      {
        s[i]=j+'a';
        cout<<s<<endl;
        return 0;
      }
    }
    vis[s[i]-'a']=0;
    s.pop_back();
  }
  cout<<-1<<endl;
  return 0;
}