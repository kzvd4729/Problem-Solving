/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-14 18:39:21                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void dfs(int i,char c,string s)
{
  if(i==0)
  {
    cout<<s<<"\n";return ;
  }
  string tmp=s;tmp.push_back(c);
  dfs(i-1,c,tmp);
  tmp.back()=char(c+1);
  dfs(i-1,c+1,tmp);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s="a";dfs(n-1,'a',s);
   return 0;
}