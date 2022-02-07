/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-28 21:20:05                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10573
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double pi=acos(-1.0);
double ret(string s,int i,int j)
{
  double rt=0;
  for(int k=i;k<=j;k++)
    rt=rt*10+(s[k]-'0');
  return rt;
}
double area(double r)
{
  return pi*r*r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  cin.ignore();
  while(t--)
  {
    string s;getline(cin,s);int f=0;
    //cout<<s<<endl;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]==' ')
      {
        double r1=ret(s,0,i-1);
        double r2=ret(s,i+1,s.size()-1);
        //cout<<r1<<" --- "<<r2<<endl;
        double d=r1+r1+r2+r2;
        double r=d/2.0;

        double ans=area(r)-area(r1)-area(r2);

        cout<<setprecision(4)<<fixed<<ans<<endl;
        f=1;break;
      }
    }
    if(!f)cout<<"Impossible"<<endl;
  }
  return 0;
}