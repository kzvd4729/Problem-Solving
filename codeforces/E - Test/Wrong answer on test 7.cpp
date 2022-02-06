/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2018 15:36                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 1300 KB                              
*  problem: https://codeforces.com/contest/25/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int kmp[3*N+2];
string s1,s2,s3;
int match(string a,string b)
{
  string c=b+"#"+a;
  memset(kmp,0,sizeof(kmp));
  for(int i=1;i<c.size();i++)
  {
    int now=kmp[i-1];
    while(true)
    {
      if(c[now]==c[i])
      {
        kmp[i]=now+1;
        break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
  }
  return min((int)b.size(),kmp[c.size()-1]);
}
int cal(string s1,string s2,string s3)
{
  int m=match(s1,s2);
  string tmp=s1;
  for(int i=m;i<s2.size();i++)
    tmp.push_back(s2[i]);
  match(tmp,s3);
  return tmp.size()+s3.size()-match(tmp,s3);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s1>>s2>>s3;
   int ans=1e8;
   ans=min(ans,cal(s1,s2,s3));
  ans=min(ans,cal(s1,s3,s2));
  ans=min(ans,cal(s2,s1,s3));
  ans=min(ans,cal(s2,s3,s1));
  ans=min(ans,cal(s3,s1,s2));
  ans=min(ans,cal(s3,s2,s1));
   cout<<ans<<endl;
   return 0;
}