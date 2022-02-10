/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-21 21:11:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 47                                         memory_used (MB): 9.7                             
*  problem: https://vjudge.net/problem/POJ-1654
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cmath>
#define long long long
using namespace std;
const int N=1e4;
struct point
{
  int x,y;
  point(){}
  point(int _x=0,int _y=0){x=_x,y=_y;}
  point operator-(const point &p){return {x-p.x,y-p.y};}
  point operator+(const point &p){return {x+p.x,y+p.y};}
  long operator^(const point &p){return (x*1LL)*p.y-(y*1LL)*p.x;}
};
long polygoanArea(vector<point>&p)
{
  int n=p.size();long area=0;
  for(int i=1;i<n-1;i++)
    area+=(p[i]-p[0])^(p[i+1]-p[0]);
  return area>=0?area:-area;
}
vector<point>v;string s;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>s;point p(0,0);
    for(int i=0;i<s.size();i++)
    {
      v.push_back(p);
      if(s[i]=='5')break;
      if(s[i]=='8')p.y++;
      if(s[i]=='9')p.x++,p.y++;
      if(s[i]=='6')p.x++;
      if(s[i]=='3')p.x++,p.y--;
      if(s[i]=='2')p.y--;
      if(s[i]=='1')p.x--,p.y--;
      if(s[i]=='4')p.x--;
      if(s[i]=='7')p.x--,p.y++;
    }
    long area=polygoanArea(v);
    if(area%2==0)cout<<area/2<<"\n";
    else cout<<area/2<<".5\n";
    v.clear();
  }
  return 0;
}