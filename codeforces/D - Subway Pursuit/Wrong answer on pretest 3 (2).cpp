/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 00:19                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1040/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ml=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<long>v;
  for(long i=1;i<=10000;i++)
    v.push_back(1000000LL-1LL+i);
  random_shuffle(v.begin(),v.end());
  long n,k;cin>>n>>k;k=10;
  long lo=1,hi=n,cnt=0;
  while(true)
  {
    if(cnt>=4498)cout<<lo<<" "<<lo<<endl,exit(0);
    long md=(lo+hi)/2;
    cout<<lo<<" "<<md<<endl;
    fflush(stdout);cnt++;
    string s;cin>>s;
    if(s=="Bad")exit(0);
    if(s=="Yes")
    {
      lo=max(1LL,lo-k);
      hi=min(n,md+k);
    }
    else
    {
      lo=max(1LL,md-k);
      hi=min(n,hi+k);
    }
    long id=-1;ml--;
    if(hi-lo<=3*k)
    {
      long dff=max(hi-lo,1LL);
      long rn=((rand()%dff)*ml)%dff;
      rn=(rn+v[++id])%dff;
      cout<<min(lo+rn,n)<<" "<<min(lo+rn,n)<<endl;
      fflush(stdout);cnt++;
      string s;cin>>s;
      if(s=="Bad")exit(0);
      if(s=="Yes")exit(0);
      else
      {
        lo=max(1LL,lo-k);
        hi=min(n,hi+k);
      }
    }
  }
  return 0;
}