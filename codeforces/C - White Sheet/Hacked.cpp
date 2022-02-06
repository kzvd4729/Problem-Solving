/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/21/2019 13:35                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1216/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>aa[N+2],bb[N+2],cc[N+2];
int a[5],b[5],c[5];
void ck(pair<int,int>p)
{
  if(a[1]>=p.first&&a[3]<=p.second)return ;
  cout<<"YES"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=4;i++)cin>>a[i];
  for(int i=1;i<=4;i++)cin>>b[i];
  for(int i=1;i<=4;i++)cin>>c[i];
   for(int i=0;i<=N;i++)
    aa[i]={-1,-1},bb[i]={-1,-1},cc[i]={-1,-1};
   for(int i=b[2];i<=b[4];i++)
    bb[i]={b[1],b[3]};
  for(int i=c[2];i<=c[4];i++)
    cc[i]={c[1],c[3]};
   for(int i=a[2];i<=a[4];i++)
  {
    if(bb[i].first==-1&&cc[i].first==-1)
      cout<<"YES"<<endl,exit(0);
    if(bb[i].first==-1)ck(cc[i]);
    else if(cc[i].first==-1)ck(bb[i]);
    else
    {
      if(bb[i].first>=cc[i].first&&bb[i].second<=cc[i].second)ck(cc[i]);
      else if(cc[i].first>=bb[i].first&&cc[i].second<=bb[i].second)ck(bb[i]);
      else
      {
        if(cc[i].first<bb[i].first)swap(bb[i],cc[i]);
        if(bb[i].second>=cc[i].first)ck({bb[i].first,cc[i].second});
        else
        {
          ck(bb[i]);ck(cc[i]);
        }
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}