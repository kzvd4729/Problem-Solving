/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/03/2020 22:17                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 11900 KB                             
*  problem: https://codeforces.com/contest/521/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int a[N+2],b[N+2];
set<pair<int,int> >st;set<int>fr;
map<pair<int,int>,int>mp;
int up(int x,int y)
{
  int cnt=0;
  cnt+=(st.find({x-1,y+1})!=st.end());
  cnt+=(st.find({x,y+1})!=st.end());
  cnt+=(st.find({x+1,y+1})!=st.end());
  return cnt;
}
int dw(int x,int y)
{
  int cnt=0;
  cnt+=(st.find({x-1,y-1})!=st.end());
  cnt+=(st.find({x,y-1})!=st.end());
  cnt+=(st.find({x+1,y-1})!=st.end());
  return cnt;
}
void ck(int x,int y)
{
  if(st.find({x,y})==st.end())return ;
  int id=mp[{x,y}];
  if(up(x,y)==0)
  {
    fr.insert(id);//cout<<id<<endl;
  }
}
int tk[N+2];
const int mod=1e9+9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=0;i<n;i++)
  {
    int x,y;cin>>x>>y;a[i]=x,b[i]=y;
    mp[{x,y}]=i;st.insert({x,y});
  }
  for(int i=0;i<n;i++)
  {
    if(up(a[i],b[i])==0)fr.insert(i);
  }
  int lo=0,hi=n-1,tr=1;vector<int>ans;
  for(int i=1;i<=n;i++)
  {
    if(tr)
    {
      int dl=-1;
      while(true)
      {
        if(hi<lo)break;
        if(tk[hi]){hi--;continue;}
        if(*fr.rbegin()>=hi){dl=*fr.rbegin();break;}
         int c1=2,c2=2,c3=2;
        if(st.find({a[hi]-1,b[hi]+1})!=st.end())c1=dw(a[hi]-1,b[hi]+1);
        if(st.find({a[hi],b[hi]+1})!=st.end())c2=dw(a[hi],b[hi]+1);
        if(st.find({a[hi]+1,b[hi]+1})!=st.end())c3=dw(a[hi]+1,b[hi]+1);
         if(c1>=2&&c2>=2&&c3>=2){dl=hi;break;}
        else hi--;
      }
      //cout<<"*"<<fr.size()<<endl;
      if(dl==-1)dl=*fr.rbegin();
      //cout<<"*"<<dl<<endl;
      ans.push_back(dl);st.erase({a[dl],b[dl]});
      tk[dl]=1;if(fr.find(dl)!=fr.end())fr.erase(dl);
        ck(a[dl]-1,b[dl]-1);ck(a[dl],b[dl]-1);ck(a[dl]+1,b[dl]-1);
     }
    else
    {
      int dl=-1;
      while(true)
      {
        if(hi<lo)break;
        if(tk[lo]){lo++;continue;}
        if(*fr.begin()<=lo){dl=*fr.begin();break;}
         int c1=2,c2=2,c3=2;
        if(st.find({a[lo]-1,b[lo]+1})!=st.end())c1=dw(a[lo]-1,b[lo]+1);
        if(st.find({a[lo],b[lo]+1})!=st.end())c2=dw(a[lo],b[lo]+1);
        if(st.find({a[lo]+1,b[lo]+1})!=st.end())c3=dw(a[lo]+1,b[lo]+1);
         if(c1>=2&&c2>=2&&c3>=2){dl=lo;break;}
        else lo++;
      }
      if(dl==-1)dl=*fr.begin();
       //cout<<"*"<<fr.size()<<endl;
      //cout<<"*"<<dl<<endl;
      ans.push_back(dl);st.erase({a[dl],b[dl]});
      tk[dl]=1;if(fr.find(dl)!=fr.end())fr.erase(dl);
        ck(a[dl]-1,b[dl]-1);ck(a[dl],b[dl]-1);ck(a[dl]+1,b[dl]-1);
     }
    tr^=1;
  }
  int ad=0,p=1;
  for(int i=n-1;i>=0;i--)
  {
    ad=(ad+1LL*ans[i]*p)%mod;
    p=(1LL*p*n)%mod;
  }
  cout<<ad<<endl;
  return 0;
}