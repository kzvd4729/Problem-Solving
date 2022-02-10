/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 9 ms                                            memory_used: 660 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int dfs(int st,int pr)
{
  if(st==s.size())return 1;
  int ans=0;
  if(s[st]=='d')
    for(int i=0;i<=9;i++)
    {
      if(pr==i)continue;
      ans+=dfs(st+1,i);
    }
  else
    for(char i='a';i<='z';i++)
    {
      if(pr==(int)i)continue;
      ans+=dfs(st+1,int(i));
    }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  cout<<dfs(0,-1)<<endl;
  return 0;
}