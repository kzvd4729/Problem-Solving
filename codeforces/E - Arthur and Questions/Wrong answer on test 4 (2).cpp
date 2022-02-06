/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2020 19:51                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/518/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9+1;
int stringToNum(string s)
{
  int f=1;
  if(s[0]=='-')s.erase(s.begin()),f=-1;
  long ret=0;
  for(auto x:s)ret=ret*10+x-'0';
  return ret*f;
}
int aa[N+2];
void print(int n)
{
  for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;exit(0);
}
void no()
{
  cout<<"Incorrect sequence\n",exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(long i=1;i<=n;i++)
  {
    string s;cin>>s;
    if(s=="?")aa[i]=inf;else aa[i]=stringToNum(s);
  }
  int sg=n-k+1;
  for(int in=1;in<=k;in++)
  {
    int f=-1;
    for(int i=in;i<=n;i+=k)if(aa[i]!=inf&&f==-1)f=i;
    if(f==-1)
    {
      int bg=-sg/2;
      for(int i=in;i<=n;i+=k)aa[i]=sg++;
      continue;
    }
    int cnt=0;
    for(int i=f-k;i>=in;i-=k)cnt++;
    //cout<<cnt<<endl;
     cnt=min(-cnt/2,aa[f]-cnt);
    for(int i=in;i<f;i+=k)
      aa[i]=cnt++;
     for(int i=f+k;i<=n;i+=k)
      if(aa[i]==inf)aa[i]=aa[i-k]+1;
    for(int i=in+k;i<=n;i+=k)
    {
      //cout<<aa[i-k]<<" "<<aa[i]<<endl;
      if(aa[i-k]>=aa[i])no();
    }
    //return 0;
  }
  print(n);
  return 0;
}