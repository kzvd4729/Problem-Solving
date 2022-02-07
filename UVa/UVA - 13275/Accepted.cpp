/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-24 15:11:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-13275
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,d,m,y,yy;
bool isLeapYear(int year)
{
  if(year % 400 == 0) return true;
  else if(year % 100 == 0) return false;
  else if(year % 4 == 0) return true;
  else return false;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>d>>m>>y>>yy;
    int ans=0;
    if(d==29&&m==2)
    {
      for(int i=y+1;i<=yy;i++)
        if(isLeapYear(i))ans++;
      printf("Case %d: %d\n",++tc,ans);
    }
    else printf("Case %d: %d\n",++tc,yy-y);
  }
  return 0;
}