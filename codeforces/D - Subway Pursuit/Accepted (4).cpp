/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 11:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1040/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<long>v;
  for(long i=1;i<=5000;i++)
    v.push_back(i);
  random_shuffle(v.begin(),v.end());
  random_shuffle(v.begin(),v.end());
  long n,k;cin>>n>>k;string s;
  long lo=1,hi=n;
  while(true)
  {
    long t=clock();
    long id=-1;
    long dff=hi-lo+1;
    long rn=(v[++id]*t)%dff;
    cout<<min(lo+rn,n)<<" "<<min(lo+rn,n)<<endl;
    fflush(stdout);
    cin>>s;
    if(s=="Yes")exit(0);
    else
    {
      lo=max(1LL,lo-k);
      hi=min(n,hi+k);
    }
    long md=(lo+hi)/2;
    cout<<lo<<" "<<md<<endl;
    fflush(stdout);
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