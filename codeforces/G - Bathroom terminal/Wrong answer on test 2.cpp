/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2019 13:48                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 117400 KB                            
*  problem: https://codeforces.com/contest/852/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int tr[5*N+2][6],sz;
void add(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!tr[now][c])tr[now][c]=++sz;
    now=tr[now][c];
  }
  tr[now][5]++;
}
string s;
int get(int i,int now)
{
  if(i==s.size())return tr[now][5];
  if(s[i]=='?')
  {
    int sum=get(i+1,now);
    for(int j=0;j<5;j++)
      if(tr[now][j])sum+=get(i+1,tr[now][j]);
    return sum;
  }
  else
  {
    int c=s[i]-'a';//cout<<c<<endl;
    if(tr[now][c])return get(i+1,tr[now][c]);
    else return 0;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s;add(s);
  }
  for(int i=1;i<=m;i++)
  {
    cin>>s;cout<<get(0,0)<<endl;
  }
  return 0;
}