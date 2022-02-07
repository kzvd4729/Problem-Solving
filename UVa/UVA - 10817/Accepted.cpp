/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-11 00:58:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 670                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10817
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e15;
long dp[1<<17],cost,here,xx;
int s,n,m,msk;
string str;
vector<long>nn[102];
void mask_bit(int j)
{
  j--;
  if(msk&(1<<j))
    msk=msk|(1<<(j+s));
  else msk=msk|(1<<j);
}
int make_mask(int tmp,int j)
{
  here=nn[j][0];
  for(int i=1;i<nn[j].size();i++)
  {
    int x=nn[j][i];
    x--;
    if(tmp&(1<<x))
    tmp=tmp|(1<<(x+s));
    else tmp=tmp|(1<<x);
  }
  return tmp;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(cin>>s)
  {
    if(!s)break;
    cin>>m>>n;
    cin.ignore();
    cost=0LL;
    msk=0;
    for(int i=1;i<=m;i++)
    {
      getline(cin,str);
      stringstream ss;
      ss<<str;
      int f=0;
      while(ss>>xx)
      {
        if(f==0)cost=cost+xx*1LL;
        else
          mask_bit(xx);
        f=1;
      }
    }
    for(int i=1;i<=n;i++)nn[i].clear();
    for(int i=1;i<=n;i++)
    {
      getline(cin,str);
      stringstream ss;
      ss<<str;
      while(ss>>xx)
        nn[i].push_back(xx);
    }
    for(int i=0;i<(1<<(s+s));i++)dp[i]=inf;
    dp[msk]=cost;
    for(int j=1;j<=n;j++)
    {
      for(int i=(1<<(s+s));i>=0;i--)
      {
        int tmp=make_mask(i,j);
        dp[tmp]=min(dp[tmp],dp[i]+here);
      }
    }
    //for(int i=0;i<16;i++)cout<<dp[i]<<endl;
    cout<<dp[(1<<(s+s))-1]<<endl;
  }
  return 0;
}