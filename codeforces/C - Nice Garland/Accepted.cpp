/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/23/2019 21:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1108/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,aa[10],bb[10],cc[10];
string s;
int cal(int pos,char c)
{
  int ret=0;
  for(int i=0;i<n;i++)
    if(s[i]==c&&(i%3)==pos)
      ret++;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;cin>>s;
  for(int i=0;i<3;i++)
  {
    aa[i]=cal(i,'B');
    bb[i]=cal(i,'R');
    cc[i]=cal(i,'G');
  }
  int ans=0,ii,jj,kk;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      for(int k=0;k<3;k++)
      {
        if(i==j||j==k||i==k)continue;
        int x=aa[i]+bb[j]+cc[k];
        if(x>ans)
        {
          ans=x;
          ii=i,jj=j,kk=k;
        }
      }
    }
  }
  cout<<n-ans<<endl;
  for(int i=ii;i<n;i+=3)
    s[i]='B';
  for(int i=jj;i<n;i+=3)
    s[i]='R';
  for(int i=kk;i<n;i+=3)
    s[i]='G';
  cout<<s<<endl;
  return 0;
}