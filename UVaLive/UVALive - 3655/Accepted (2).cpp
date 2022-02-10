/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-24 21:02:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 9                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-3655
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/*************** Convex Hull *******************/
struct point
{
  int x,y;
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  int operator^(const point &p)const{return x*p.y-y*p.x;}
};
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>0)
      stck[top-1]=stck[top],top--;
    else break;
  }
}
//returns cpunter-clock-wise;
//first=last;
vector<point>monotoneChain(vector<point>&v)
{
  sort(v.begin(),v.end());
  vector<point>hull;int n=v.size();
  for(int i=n-1;i>=0;i--)
    stck[++top]=v[i],balance();
  while(top>0)
    hull.push_back(stck[top--]);
  for(int i=0;i<n;i++)
    stck[++top]=v[i],balance();
  top--;
  while(top>0)
    hull.push_back(stck[top--]);
  hull.pop_back();
  return hull;
}
/////////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n)
  {
    if(!n)break;vector<point>v(n);
    for(int i=0;i<n;i++)
      cin>>v[i].x>>v[i].y;
    sort(v.begin(),v.end());
    //v.erase(unique(v.begin(),v.end()),v.end());
    int cnt=0;
    while(true)
    {
      vector<point>p=monotoneChain(v);
      if(p.size()>=3)cnt++;
      sort(p.begin(),p.end());
      vector<point>u;
      for(auto x:v)
      {
        if(!binary_search(p.begin(),p.end(),x))
          u.push_back(x);
      }
      if(u.size()==0)break;
      v=u;
    }
    if(cnt&1)cout<<"Take this onion to the lab!\n";
    else cout<<"Do not take this onion to the lab!\n";
  }
  return 0;
}