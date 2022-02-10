/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 01:30:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 63                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/POJ-1654
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cmath>
#define long long long
using namespace std;
const int N=1e6;
struct point
{
  long x,y;
  point(){}
  point(long _x,long _y){x=_x,y=_y;}
  long operator^(point p){return x*p.y-y*p.x;}
};
vector<point>v;
long polygonarea2(void)
{
  long ret=0;
  for(int i=0;i<v.size()-1;i++)
    ret+=v[i]^v[i+1];
  if(ret<0)ret=-ret;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    point p(0,0),nw(0,0);long area=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='5')break;
      if(s[i]=='8')p.y++;
      if(s[i]=='9')p.x++,p.y++;
      if(s[i]=='6')p.x++;
      if(s[i]=='3')p.x++,p.y--;
      if(s[i]=='2')p.y--;
      if(s[i]=='1')p.x--,p.y--;
      if(s[i]=='4')p.x--;
      if(s[i]=='7')p.x--,p.y++;
      area+=nw^p;nw=p;
    }
    if(area<0)area=-area;
    if(area%2==0)cout<<area/2<<endl;
    else cout<<area/2<<".5"<<endl;
  }
  return 0;
}