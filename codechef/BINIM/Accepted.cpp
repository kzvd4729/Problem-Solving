/****************************************************************************************
*  @author: kzvd4729                                         created: 22-04-2018 21:52:44                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/COOK93A/problems/BINIM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,n;
string nm,s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>nm;
    int zr=0,on=0;
    while(n--)
    {
      cin>>s;
      int zero=0;
      int one=0;
      for(int i=0;s[i];i++)
      {
        if(s[i]=='0')zero++;
        else one++;
      }
      if(s[0]=='0')zr+=zero;
      else on+=one;
    }
    if(nm=="Dee")
    {
      if(zr>on)cout<<"Dee"<<endl;
      else cout<<"Dum"<<endl;
    }
    else
    {
      if(on>zr)cout<<"Dum"<<endl;
      else cout<<"Dee"<<endl;
    }
  }
  return 0;
}