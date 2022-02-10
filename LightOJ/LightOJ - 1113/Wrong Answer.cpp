/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-07 00:31:11                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1113
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int            ll;
typedef unsigned long long int   ull;
#define min3(a,b,c)              min(a,min(b,c))
#define F                        first
#define S                        second
#define PB                       push_back
#define MP                       make_pair
#define PI                       2*acos(0.0)
#define REP(i,a,b)               for(int i = a; i<=b; i++)
int main()
{
  stack<string>backward,forwar;
  int t,c=1;
  cin>>t;
  for(int i=1; i<=t; i++){
          cout<<"Case "<<i<<":"<<endl;
      backward=stack<string>();
      forwar=stack<string>();
      backward.push("http://w...content-available-to-author-only...j.com/");
      while(1){
          string s;
          cin>>s;
          if(s=="QUIT"){
              break;
          }
          else if(s=="VISIT"){
              string t;
              cin>>t;
              forwar=stack<string>();
              backward.push(t);
              cout<<backward.top()<<endl;
          }
          else if(s=="BACK"){
              if(backward.size()<=1){
                  cout<<"Ignored"<<endl;
              }
              else{
                  forwar.push(backward.top());
                  backward.pop();
                  cout<<backward.top()<<endl;
              }
          }
          else if(s=="FORWARD"){
              if(forwar.empty()){
                  cout<<"Ignored"<<endl;
              }
              else {
                  backward.push(forwar.top());
                  forwar.pop();
                  cout<<backward.top()<<endl;
              }
          }
      }
  }
  return 0;
}