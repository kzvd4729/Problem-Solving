/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2018 22:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1051/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int cnt[4];string s;
int P(char c)
{
  if(c>='A'&&c<='Z')return 1;
  if(c>='a'&&c<='z')return 2;
  else return 3;
}
bool ck(void)
{
  if(cnt[1]&&cnt[2]&&cnt[3])
  {
    cout<<s<<endl;
    return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t;cin>>t;
  while(t--)
  {
    memset(cnt,0,sizeof(cnt));
    cin>>s;
    for(auto x:s)
      cnt[P(x)]++;
    if(ck())continue;
    for(int i=0;s[i];i++)
    {
      char x=s[i];
      if(cnt[P(x)]>1)
      {
        cnt[P(x)]--;
        if(cnt[1]==0)
        {
          s[i]='A';cnt[1]++;
        }
        else if(cnt[2]==0)
        {
          s[i]='a';cnt[2]++;
        }
        else
        {
          s[i]='1';cnt[3]++;
        }
      }
      if(ck())break;
    }
  }
  return 0;
}