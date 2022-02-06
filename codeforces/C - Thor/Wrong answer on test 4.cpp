/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2018 21:38                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 6900 KB                              
*  problem: https://codeforces.com/contest/705/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int n,q,ty,x;
vector<int>v[N+2];
vector<pair<int,int> >vv;
set<pair<int,int> >st1,st2;
set<pair<int,int> >::iterator it;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>q;
   for(int i=1;i<=q;i++)
  {
    cin>>ty>>x;
    if(ty==1)
    {
      st1.insert({i,x});
      st2.insert({x,i});
    }
    else if(ty==2)
    {
      it=st2.lower_bound({x,-1});
      vv.clear();
      while(it!=st2.end())
      {
        if(it->first!=x)break;
        vv.push_back(*it);
        it++;
      }
      for(auto xx:vv)
      {
        st2.erase(xx);
        st1.erase({xx.second,xx.first});
      }
    }
    else
    {
      it=st1.begin();
      vv.clear();
      while(it!=st1.end())
      {
        if(it->first>x)break;
        vv.push_back(*it);
        it++;
      }
      for(auto xx:vv)
      {
        st1.erase(xx);
        st2.erase({xx.second,xx.first});
      }
    }
    cout<<st1.size()<<endl;
  }
  return 0;
}