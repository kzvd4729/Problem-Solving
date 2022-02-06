/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/29/2019 15:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1196/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int q;cin>>q;
  while(q--)
  {
    int b,w;cin>>b>>w;
    vector<pair<int,int> >ans;
    if(b>=w)
    {
      if(w*3+1<b)
      {
        cout<<"NO"<<endl;continue;
      }
      int x=1e8,y=1e8;
      for(int i=1;i<=w;i++)
      {
        ans.push_back({x,y});y+=2;
      }
      x=1e8,y=1e8-1;
      while(b>0)
      {
        ans.push_back({x,y});y+=2;b--;
        if(y>1e8+w*2)break;
      }
      x=1e8-1,y=1e8;
      while(b>0)
      {
        ans.push_back({x,y});y+=2;b--;
        if(y>1e8+(w-1)*2)break;
      }
      x=1e8+1,y=1e8;
      while(b>0)
      {
        ans.push_back({x,y});y+=2;b--;
        if(y>1e8+(w-1)*2)break;
      }
    }
    else
    {
      if(b*3+1<w)
      {
        cout<<"NO"<<endl;continue;
      }
      int x=1e8+1,y=1e8;
      for(int i=1;i<=b;i++)
      {
        ans.push_back({x,y});y+=2;
      }
      x=1e8+1,y=1e8-1;
      while(w>0)
      {
        ans.push_back({x,y});y+=2;w--;
        if(y>1e8+b*2)break;
      }
      x=1e8-1+1,y=1e8;
      while(w>0)
      {
        ans.push_back({x,y});y+=2;w--;
        if(y>1e8+(b-1)*2)break;
      }
      x=1e8+1+1,y=1e8;
      while(w>0)
      {
        ans.push_back({x,y});y+=2;w--;
        if(y>1e8+(b-1)*2)break;
      }
    }
    cout<<"YES\n";
    for(auto x:ans)
      cout<<x.first<<" "<<x.second<<"\n";
  }
  return 0;
}