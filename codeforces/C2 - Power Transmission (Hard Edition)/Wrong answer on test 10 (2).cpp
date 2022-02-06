/****************************************************************************************
*  @author: kzvd4729                                         created: May/10/2019 01:48                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 295 ms                                          memory_used: 26900 KB                             
*  problem: https://codeforces.com/contest/1163/problem/C2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  int x,y;
}pp[N+2];
struct Equation
{
  int a,b,c;
};
Equation Make_Equation(point p1,point p2)
{
  Equation eq;//ax+by=c;
  eq.a=p1.y-p2.y;eq.b=p2.x-p1.x;
  eq.c=p1.y*p2.x-p2.y*p1.x;
  int gc=__gcd(__gcd(abs(eq.a),abs(eq.b)),abs(eq.c));
  if(gc)eq.a/=gc;eq.b/=gc;eq.c/=gc;
  if(eq.a<0)eq.a*=-1,eq.b*=-1,eq.c*=-1;
  return eq;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>pp[i].x>>pp[i].y;
  set<pair<int,pair<int,int> > >st;
  long ans=0;map<pair<int,int>,int>mp;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      Equation eq=Make_Equation(pp[i],pp[j]);
      pair<int,pair<int,int> >p={eq.a,{eq.b,eq.c}};
      if(st.find(p)!=st.end())continue;
      ans+=(st.size()-mp[{eq.a,eq.b}])*1LL;
      st.insert(p);mp[{eq.a,eq.b}]++;
    }
  }
  cout<<ans<<endl;
  return 0;
}