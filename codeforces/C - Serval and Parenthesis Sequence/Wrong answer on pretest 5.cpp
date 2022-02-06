/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 20:44                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1153/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int qm[N+2];
void no(void)
{
  cout<<":("<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;if(n%2)no();
   if(n==2)
  {
    if(s[0]==')')no();
    if(s[1]=='(')no();
    cout<<"()"<<endl,exit(0);
  }
   if(s[n-1]=='(')no();s[n-1]=')';
  if(s[n-2]=='(')no();s[n-2]=')';
   for(int i=n-1;i>=0;i--)
  {
    qm[i]=qm[i+1];
    if(s[i]=='?')qm[i]++;
  }
  /*for(int i=0;i<n;i++)
    cout<<qm[i]<<" ";
  cout<<endl;*/
  int bl=0;
  for(int i=0;i<n-2;i++)
  {
    if(s[i]=='?')
    {
      int nd=bl-2;
      if(qm[i]<=nd)
      {
        bl--;s[i]=')';
      }
      else bl++,s[i]='(';
    }
    else if(s[i]=='(')bl++;
    else bl--;
    if(bl<=0)no();
  }
  if(bl!=2)no();
  cout<<s<<endl;
  return 0;
}