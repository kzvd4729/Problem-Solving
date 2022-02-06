/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 02:20                        
*  solution_verdict: Time limit exceeded on test 133         language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 300 KB                               
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
    v.push_back(1000000LL+2+i);
  random_shuffle(v.begin(),v.end());
  long n,k;cin>>n>>k;
  long lo=1,hi=n;
  while(true)
  {
    //if(cnt>=4499)cout<<lo<<" "<<lo<<endl,exit(0);
    long id=-1;ml--;
    if(hi-lo<=4*k+5)
    {
      long dff=hi-lo+1;
      long rn=((rand()%dff)*ml)%dff;
      rn=(rn+v[++id])%dff;
      //if(cnt%45==0)rn=0;
      cout<<min(lo+rn,n)<<" "<<min(lo+rn,n)<<endl;
      fflush(stdout);
      string s;cin>>s;
      if(s=="Yes")exit(0);
      else
      {
        lo=max(1LL,lo-k);
        hi=min(n,hi+k);
      }
    }
    long md=(lo+hi)/2;
    cout<<lo<<" "<<md<<endl;
    fflush(stdout);
    string s;
    cin>>s;
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
  }
  return 0;
}