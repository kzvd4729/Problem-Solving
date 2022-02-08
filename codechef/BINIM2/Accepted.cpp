/****************************************************************************************
*  @author: kzvd4729                                         created: 21-10-2018 22:40:38                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK99A/problems/BINIM2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;string s;cin>>s;
    int dee=0,dum=0;
    while(n--)
    {
      string x;cin>>x;
      if(x[0]=='0'&&x.back()=='0')dee++;
      if(x[0]=='1'&&x.back()=='1')dum++;
    }
    if(s=="Dee")
    {
      if(dee<=dum)cout<<"Dee"<<endl;
      else cout<<"Dum"<<endl;
    }
    else
    {
      if(dum<=dee)cout<<"Dum"<<endl;
      else cout<<"Dee"<<endl;
    }
  }
  return 0;
}