/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2019 00:21                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1221/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int vis[5],f;
void alice()
{
  if(f)return ;
  cout<<"YES\n",f=1;
}
void bob()
{
  if(f)return ;
  cout<<"NO\n",f=1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    string s;cin>>s;int cnt=0;f=0;
    s="X"+s+"X";
    vector<int>v;
    for(auto x:s)
    {
      if(x=='.')cnt++;
      else {if(cnt>=b)v.push_back(cnt);cnt=0;}
    }
    sort(v.begin(),v.end());
    if(v.size()==0||v.back()<a){bob();continue;}
    if(v.front()<a)bob();
    cnt=0;
    for(auto x:v)if(x>=2*b)cnt++;
    if(cnt>=2)bob();
    //if(v.back()>=4*b+a-1)bob();
    int sz=v.size();
    if(v.back()<2*b){if(sz%2)alice();else bob();}
    else
    {
      int mx=v.back();memset(vis,0,sizeof(vis));
      for(int i=0;i<mx;i++)
      {
        if(i+a>mx||i>=2*b)break;
        if(mx-i-a>=2*b||i>=b&&i<a)continue;
        if(mx-i-a>=b&&mx-i-a<a)continue;
         int cnt=0;cnt+=(i>=a)+((mx-i-a)>=a);
        vis[cnt]=1;
      }
      int cnt=0;cnt+=vis[0]+vis[1]+vis[2];
      if(cnt>=2)alice();
      if(vis[1])sz++;if(vis[2])sz+=2;
      if(sz%2)alice();else bob();
    }
  }
  return 0;
}