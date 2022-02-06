/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2018 15:21                        
*  solution_verdict: Wrong answer on pretest 8               language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1072/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
char mat[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=n;j++)
      mat[i][j]=s[j-1];
  }
  queue<pair<int,int> >q1,q2;q1.push({1,1});
  int loop=2*n-1;
  while(loop--)
  {
    q2=q1;char mn='z';
    while(q1.size())
    {
      pair<int,int>p=q1.front();q1.pop();
      mn=min(mn,mat[p.first][p.second]);
    }
    if(mn=='a')
    {
      while(q2.size())
      {
        pair<int,int>p=q2.front();q2.pop();
        if(mat[p.first][p.second]==mn)
        {
          q1.push(p);
        }
      }
      cout<<'a';
    }
    else if(k)
    {
      k--;cout<<'a';
      q1=q2;
    }
    else
    {
      while(q2.size())
      {
        pair<int,int>p=q2.front();q2.pop();
        if(mat[p.first][p.second]==mn)
        {
          q1.push(p);
        }
      }
      cout<<mn;
    }
    set<pair<int,int> >st;
    while(q1.size())
    {
      pair<int,int>p=q1.front();q1.pop();
      if(p.first+1<=n)
        st.insert({p.first+1,p.second});
      if(p.second+1<=n)
        st.insert({p.first,p.second+1});
    }
    while(st.size())
    {
      pair<int,int>p=*st.begin();
      q1.push(p);st.erase(p);
    }
  }
  cout<<endl;
  return 0;
}