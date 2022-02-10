/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-30 00:07:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 3                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-2070
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,r,c,xx,yy;
string s;
char mat[1000][1000];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>n)
  {
    if(!n)break;
    cin>>s;
    r=1,c=1;
    for(int i=1;i<=s.size();i++)
    {
      mat[r][c]=s[i-1];
      if(i%n==0)
      {
        r++;
        c=1;
      }
      else c++;
    }
    r--;
    c=n;
    string ans;
    for(int i=1;i<=c;i++)
    {
      xx=1,yy=i;
      while(true)
      {
        if(xx>r||xx<1||yy>c||yy<1)break;
        ans.push_back(mat[xx][yy]);
        xx++;
        yy--;
      }
    }
    for(int i=2;i<=r;i++)
    {
      xx=i,yy=c;
      while(true)
      {
        if(xx>r||xx<1||yy>c||yy<1)break;
        ans.push_back(mat[xx][yy]);
        xx++;
        yy--;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}