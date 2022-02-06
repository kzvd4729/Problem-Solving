/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 19:39                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/716/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int q,fr[10003],now;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  for(int i=1;i<=s.size();i++)
  {
    if(s[i-1]=='?')q++;
    else
    {
      fr[s[i-1]]++;
      if(fr[s[i-1]]==1)now++;
      else if(fr[s[i-1]]==2)now--;
    }
    if(i>26)
    {
      if(s[i-26-1]=='?')q--;
      else
      {
        fr[s[i-26-1]]--;
        if(fr[s[i-26-1]]==1)now++;
        else if(fr[s[i-26-1]]==0)now--;
      }
    }
    //cout<<now<<" "<<q<<endl;
    if(now+q==26)
    {
      for(int j=1;j<=i-26-1;j++)
        if(s[j-1]=='?')s[j-1]='A';
      for(int j=i-26;j<=i;j++)
      {
        if(s[j-1]=='?')
        {
          for(char k='A';k<='Z';k++)
          {
            if(fr[(int)k]==0)
            {
              s[j-1]=k;
              fr[(int)k]++;
              break;
            }
          }
        }
      }
      for(int j=i+1;j<=s.size();j++)
        if(s[j-1]=='?')s[j-1]='A';
      cout<<s<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}