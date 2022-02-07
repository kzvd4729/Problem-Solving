/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 23:12:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 70                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11997
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=750;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;while(cin>>n)
  {
    vector<vector<int> >aa(n);int sum=0;
    for(int i=0;i<n;i++)
    {
      aa[i].resize(n);
      for(int j=0;j<n;j++)
        cin>>aa[i][j];
      sort(aa[i].begin(),aa[i].end());
      sum+=aa[i][0];
    }
    priority_queue<int>pq;pq.push(sum);
    for(int j=1;j<n;j++)pq.push(sum+aa[0][j]-aa[0][0]);


    vector<int>tmp;
    for(int i=1;i<n;i++)
    {
      tmp.clear();
      while(pq.size())
      {
        tmp.push_back(pq.top());pq.pop();
      }
      for(auto x:tmp)pq.push(x);
      reverse(tmp.begin(),tmp.end());

      for(int j=1;j<n;j++)
      {
        for(int k=0;k<n;k++)
        {
          if(tmp[k]+aa[i][j]-aa[i][0]<pq.top())
          {
            pq.push(tmp[k]+aa[i][j]-aa[i][0]);
            pq.pop();
          }
          else break;
        }
      }
    }
    tmp.clear();
    while(pq.size())
    {
      tmp.push_back(pq.top());pq.pop();
    }
    for(auto x:tmp)pq.push(x);
    reverse(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++)
    {
      if(i)cout<<" ";
      cout<<tmp[i];
    }
    cout<<endl;
  }
  return 0;
}