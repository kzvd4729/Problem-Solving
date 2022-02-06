/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/20/2018 23:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/474/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
string ss[5];
char ret(char ch,char x)
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<ss[i].size();j++)
    {
      if(ss[i][j]==x)
      {
        if(ch=='L')return ss[i][j+1];
        else return ss[i][j-1];
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  char ch;cin>>ch;string s;cin>>s;
  ss[0]="qwertyuiop";
  ss[1]="asdfghjkl;";
  ss[2]="zxcvbnm,./";
  for(auto x:s)
    cout<<ret(ch,x);
  cout<<endl;
  return 0;
}