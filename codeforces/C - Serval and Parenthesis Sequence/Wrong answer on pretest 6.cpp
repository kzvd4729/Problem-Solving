/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 21:52                        
*  solution_verdict: Wrong answer on pretest 6               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1153/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void no(void)
{
  cout<<":("<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;if(n%2==1)no();
   if(s[0]==')')no();if(s[n-1]=='(')no();
  s[0]='(';s[n-1]=')';
   int rbl=0;
  for(int i=1;i<n-1;i++)
  {
    if(s[i]=='?')continue;
    if(s[i]=='(')rbl++;
    else rbl--;
  }
  int bl=0;
  for(int i=1;i<n-1;i++)
  {
    if(s[i]=='(')bl++;
    else if(s[i]==')')bl--;
    else
    {
      if(bl==0)
      {
        s[i]='(';bl++;rbl++;continue;
      }
      if(rbl<=0)
      {
        s[i]='(';bl++;rbl++;
      }
      else
      {
        s[i]=')';bl--;rbl--;
      }
    }
  }
  if(bl!=0||rbl!=0)no();
  cout<<s<<endl;
  return 0;
}