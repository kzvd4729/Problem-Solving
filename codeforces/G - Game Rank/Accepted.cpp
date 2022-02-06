/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 17:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4000 KB                              
*  problem: https://codeforces.com/gym/101550/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
void lg(void)
{
  cout<<"Legend"<<endl,exit(0);
}
int need[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
   for(int i=1;i<=10;i++)need[i]=5;
  for(int i=11;i<=15;i++)need[i]=4;
  for(int i=16;i<=20;i++)need[i]=3;
  for(int i=21;i<=25;i++)need[i]=2;
   int rnk=25,star=0,cn=0;
  for(auto x:s)
  {
    if(x=='W')
    {
      star++,cn++;
      if(rnk>=6&&cn>=3)star++;
      if(star>need[rnk]){star-=need[rnk];rnk--;}
      if(!rnk)lg();
    }
    else
    {
      if(rnk<=20)
      {
        star--;
        if(star<0){rnk++;star=need[rnk]-1;}
         if(rnk>20)rnk=20,star=0;
      }
      cn=0;
    }
    //cout<<rnk<<" "<<star<<endl;
  }
  cout<<rnk<<endl;
  return 0;
}