/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 19:40                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 10900 KB                             
*  problem: https://codeforces.com/contest/950/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long f,id,xx,now,sf;
string s;
set<long>zero,one;
set<long>::iterator it;
vector<long>v[N+2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>s;
    for(long i=0;i<s.size();i++)
    {
      if(s[i]=='0')zero.insert(i+1);
      else one.insert(i+1);
    }
    while(true)
    {
      now=0;
      sf=0;
      if(!zero.size()&&!one.size())break;
      if(!zero.size()&&one.size())
      {
        cout<<-1<<endl;
        return 0;
      }
      ++id;
      while(true)
      {
        if(sf==0)
        {
          it=upper_bound(zero.begin(),zero.end(),now);
          if(it==zero.end())
          {
            f=1;
            break;
          }
          xx=*it;
          v[id].push_back(xx);
          zero.erase(xx);
          now=xx;
          sf=1;
        }
        else
        {
          it=upper_bound(one.begin(),one.end(),now);
          if(it==one.end())break;
          xx=*it;
          v[id].push_back(xx);
          one.erase(xx);
          now=xx;
          sf=0;
        }
      }
      if(f)
      {
        cout<<-1<<endl;
        return 0;
      }
    }
    cout<<id<<endl;
    for(long i=1;i<=id;i++)
    {
      cout<<v[i].size()<<" ";
      for(auto x:v[i])cout<<x<<" ";
      cout<<endl;
    }
    return 0;
}