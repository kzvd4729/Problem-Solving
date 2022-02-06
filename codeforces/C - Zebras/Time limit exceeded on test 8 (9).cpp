/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 21:26                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++17                               
*  run_time: 1000 ms                                         memory_used: 10900 KB                             
*  problem: https://codeforces.com/contest/950/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int f,id,xx,now,sf,cnt;
string s;
set<int>zero,one;
set<int>::iterator it;
vector<int>v[N+2];
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='0')zero.insert(i+1);
      else one.insert(i+1);
    }
    ///double t1=clock();
    for(long i=1;i<=N;i++)
    {
      now=0;
      sf=0;
      if(!zero.size()&&!one.size())break;
      if(!zero.size()&&one.size())
      {
        printf("-1\n");
        return 0;
      }
      ++id;
      for(long j=1;j<=N;j++)
      {
        ///cnt++;
//        if(cnt>s.size())
//        {
//          cout<<N<<endl;
//          return 0;
//        }
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
      if(f||!v[id].size())
      {
        printf("-1\n");
        return 0;
      }
    }
    printf("%d\n",id);
    for(int i=1;i<=id;i++)
    {
      printf("%d ",v[i].size());
      for(auto x:v[i])printf("%d ",x);
      printf("\n");
    }
    ///cout<<clock()-t1<<endl;
    return 0;
}