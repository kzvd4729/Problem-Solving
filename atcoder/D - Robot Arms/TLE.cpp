/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-29 18:34:29                      
*  solution_verdict: TLE                                     language: C++14 (GCC 5.4.1)                       
*  run_time: 2103 ms                                         memory_used: 65280 KB                             
*  problem: https://atcoder.jp/contests/arc103/tasks/arc103_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
pair<int,int>arr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;priority_queue<int>pq;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].first>>arr[i].second;
    pq.push(abs(arr[i].first)+abs(arr[i].second));
  }
  int mx=pq.top();
  while(pq.size()>1)
  {
    int one=pq.top();pq.pop();
    if((one-pq.top())%2)cout<<-1<<endl,exit(0);
  }
  cout<<mx<<endl;
  for(int i=1;i<=mx;i++)cout<<1<<" ";
  cout<<endl;
  for(int i=1;i<=n;i++)
  {
    int x=0,y=0;
    for(int j=1;j<=mx;j++)
    {
      if(x==arr[i].first&&y==arr[i].second)
      {
        cout<<"RL";
        j++;
      }
      else if(x==arr[i].first)
      {
        if(y<arr[i].second)
        {
          cout<<'U';y++;
        }
        else
        {
          cout<<'D';y--;
        }
      }
      else
      {
        if(x<arr[i].first)
        {
          cout<<'R';x++;
        }
        else
        {
          cout<<'L';x--;
        }
      }
    }
    cout<<endl;
  }
  return 0;
}