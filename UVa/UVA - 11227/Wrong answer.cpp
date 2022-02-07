/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-11 22:32:46                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11227
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double eps=0.00001;
long t,n,cnt,tc;
map<pair<double,double>,long>mp;
struct point
{
  double x,y;
};
vector<point>v;
struct equation
{
  double a,b,c;
};
equation make_equation(point p1, point p2)
{
    equation tmp;
    tmp.a = (p2.y - p1.y);
    tmp.b = (p1.x - p2.x);
    tmp.c = (p1.x * (p1.y - p2.y) + p1.y * (p2.x - p1.x));
    return tmp;
}
bool online(equation e,point p)
{
  if(fabs(p.x*e.a+p.y*e.b+e.c)<eps)return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        v.clear();
        mp.clear();
        point p;
        for(long i = 1; i <= n; i++)
        {
            cin >> p.x >> p.y;
            if(mp[ {p.x, p.y}])continue;
            mp[ {p.x, p.y}] = 1;
            v.push_back(p);
            cnt++;
        }
        if(cnt==1)
        {
          cout<<"Data set #"<<++tc<<" contains a single gnu."<<endl;
          continue;

        }
        long ans=0;
        for(long i=0;i<v.size();i++)
        {
          for(long j=i+1;j<v.size();j++)
          {
            equation e=make_equation(v[i],v[j]);
            long c=0;
            for(long k=0;k<v.size();k++)if(online(e,v[k]))c++;
            ans=max(c,ans);
          }
        }
        cout<<"Data set #"<<++tc<<" contains "<<cnt<<" gnus, out of which a maximum of "<<ans<<" are aligned."<<endl;
    }
    return 0;
}