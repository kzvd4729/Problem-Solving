/****************************************************************************************
*  @author: kzvd4729                                         created: May/08/2019 15:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 28000 KB                             
*  problem: https://codeforces.com/contest/256/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=881917;
int lft[N+2],rgt[N+2],grn[N+2];
vector<int>pos[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=N;i++)
  {
    int lt=pow((i*1.0),0.25);
    lt--;if(lt<0)lt=0;
    while(lt*lt*lt*lt<i)lt++;
    lft[i]=lt;
     int rt=pow((i*1.0),0.5);
    rt++;if(rt>=i)rt=i-1;
    while(rt*rt>i)rt--;
    rgt[i]=rt;
  }
  pos[0].push_back(0);pos[0].push_back(1);pos[0].push_back(2);
  pos[0].push_back(3);
  for(int i=4;i<=N;i++)
  {
    for(int n=0;  ;n++)
    {
      int id=lower_bound(pos[n].begin(),pos[n].end(),lft[i])-pos[n].begin();
      if(id>=pos[n].size())
      {
        grn[i]=n;break;
      }
      else if(pos[n][id]>rgt[i])
      {
        grn[i]=n;break;
      }
    }
    pos[grn[i]].push_back(i);
  }
  int nn,xxr=0;cin>>nn;
  while(nn--)
  {
    long i;cin>>i;
    long lt=pow((i*1.0),0.25);
    lt--;if(lt<0)lt=0;
    while(lt*lt*lt*lt<i)lt++;
     long rt=pow((i*1.0),0.5);
    rt++;if(rt>=i)rt=i-1;
    while(rt*rt>i)rt--;
     int now=0;
    for(int n=0;  ;n++)
    {
      int id=lower_bound(pos[n].begin(),pos[n].end(),lt)-pos[n].begin();
      if(id>=pos[n].size())
      {
        now=n;break;
      }
      else if(pos[n][id]>rt)
      {
        now=n;break;
      }
    }
    xxr^=now;
  }
  if(!xxr)cout<<"Rublo"<<endl;
  else cout<<"Furlo"<<endl;
  return 0;
}