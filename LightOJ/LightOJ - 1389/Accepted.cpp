/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-31 17:15:29                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1389
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,n,cnt,vis[102];
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>n;
    cin>>s;
    s="#"+s;
    memset(vis,0,sizeof(vis));
    cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(s[i]=='.'&&vis[i-1]==0&&vis[i]==0)
      {
        cnt++;
        vis[i+1]=1;
      }
    }
    cout<<"Case "<<++tc<<": "<<cnt<<endl;
  }
  return 0;
}