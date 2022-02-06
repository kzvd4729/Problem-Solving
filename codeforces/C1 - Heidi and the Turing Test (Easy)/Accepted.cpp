/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 13:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1184/problem/C1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=50;
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int nn=4*n+1;
  for(int i=1;i<=nn;i++)
    cin>>pp[i].first>>pp[i].second;
   for(int x1=0;x1<=50;x1++)
  {
    for(int x2=x1;x2<=50;x2++)
    {
      for(int y1=0;y1<=50;y1++)
      {
        for(int y2=y1;y2<=50;y2++)
        {
          int cnt=0,id;
          for(int i=1;i<=nn;i++)
          {
            if((pp[i].first==x1||pp[i].first==x2)&&(pp[i].second>=y1&&pp[i].second<=y2))continue;
            if((pp[i].second==y1||pp[i].second==y2)&&(pp[i].first>=x1&&pp[i].first<=x2))continue;
            cnt++;id=i;
          }
          //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
          if(cnt==1)cout<<pp[id].first<<" "<<pp[id].second<<endl,exit(0);
        }
      }
    }
  }
  return 0;
}