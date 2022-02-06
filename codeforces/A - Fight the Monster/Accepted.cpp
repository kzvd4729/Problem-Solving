/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/03/2018 18:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/487/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int hpy,atky,defy,hpm,atkm,defm,h,a,d;
  cin>>hpy>>atky>>defy>>hpm>>atkm>>defm>>h>>a>>d;
   int df=max(0,defm+1-atky);
  int ex=df*a;atky=max(atky,defm+1);
  int ans=1e9;
  for(int i=0;i<=100;i++)
  {
    for(int j=0;j<=100;j++)
    {
      for(int k=0;k<=10000;k++)
      {
        int mlf=(hpm+atky+i-defm-1)/(atky+i-defm);
        int dc=atkm-(defy+j);int ylf;
        if(dc<=0)ylf=1e9;
        else ylf=(hpy+k+dc-1)/dc;
         if(ylf>mlf)ans=min(ans,i*a+j*d+k*h);
      }
    }
  }
  cout<<ans+ex<<endl;
  return 0;
}