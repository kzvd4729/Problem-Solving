/****************************************************************************************
*  @author: kzvd4729                                         created: May/31/2018 00:47                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/987/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
string x[10],s[10],ss[10];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   s[0]="purple";
  s[1]="green";
  s[2]="blue";
  s[3]="orange";
  s[4]="red";
  s[5]="yellow";
   x[0]="Power";
  x[1]="Time";
  x[2]="Space";
  x[3]="Soul";
  x[4]="Reality";
  x[5]="Mind";
   cin>>n;
  for(int i=0;i<n;i++)
    cin>>ss[i];
  cout<<6-n<<endl;
  for(int i=0;i<6;i++)
  {
    int f=0;
    for(int j=0;j<6;j++)
    {
      if(ss[j]==s[i])
        f=1;
    }
    if(f==0)cout<<x[i]<<endl;
  }
  return 0;
}