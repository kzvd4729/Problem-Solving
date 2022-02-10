/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-03 01:23:27                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
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
  int x,y;
  point(){}
  point(int _x,int _y){x=_x,y=_y;}
  int operator^(point p){return x*p.y-y*p.x;}
};
int polygonarea2(vector<point>&v)
{
  int ret=0;
  for(int i=0;i<v.size()-1;i++)
    ret+=v[i]^v[i+1];
  return abs(ret);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;vector<point>v;
    point p(0,0);v.push_back(p);
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
      v.push_back(p);
    }
    int area=polygonarea2(v);
    if(area%2==0)cout<<area/2<<endl;
    else cout<<area/2<<".5"<<endl;
  }
  return 0;
}