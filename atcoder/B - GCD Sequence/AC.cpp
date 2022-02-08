/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-31 22:06:00                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 3 ms                                            memory_used: 512 KB                               
*  problem: https://atcoder.jp/contests/agc022/tasks/agc022_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
vector<int>tw,th,sx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  if(n==3)
  {
    cout<<2<<" "<<5<<" "<<63<<endl;
    return 0;
  }
  cout<<2<<" "<<4<<" "<<3<<" "<<9<<" ";
  n-=4;
  for(int i=5;i<=30000;i++)if(i%2==0&&i%6!=0)tw.push_back(i);
  for(int i=10;i<=30000;i++)if(i%3==0&&i%6!=0)th.push_back(i);
  for(int i=5;i<=30000;i++)if(i%6==0)sx.push_back(i);
   reverse(tw.begin(),tw.end());
  reverse(th.begin(),th.end());
  reverse(sx.begin(),sx.end());
   if(n&1)
  {
    cout<<sx.back()<<" ";
    sx.pop_back();
    n--;
  }
   while(n)
  {
    if(tw.size())
    {
      cout<<tw.back()<<" ";
      tw.pop_back();
    }
    else if(th.size())
    {
      cout<<th.back()<<" ";
      th.pop_back();
    }
    else
    {
      cout<<sx.back()<<" ";
      sx.pop_back();
    }
    n--;
  }
  cout<<endl;
  return 0;
}