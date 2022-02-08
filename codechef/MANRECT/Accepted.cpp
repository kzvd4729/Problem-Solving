/****************************************************************************************
*  @author: kzvd4729                                         created: 03-02-2019 10:44:28                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.01 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/FEB19B/problems/MANRECT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int k=1000000000;
    cout<<"Q 0 0"<<endl;fflush(stdout);
    long a;cin>>a;
    cout<<"Q "<<k<<" 0"<<endl;fflush(stdout);
    long b;cin>>b;
    cout<<"Q 0 "<<k<<endl;fflush(stdout);
    long c;cin>>c;
    cout<<"Q "<<k<<" "<<k<<endl;fflush(stdout);
    long d;cin>>d;
    b-=k;c-=k;d-=k;d-=k;
    long e=a-b;
    //if(e<0)assert(0);
    cout<<"Q "<<e/2<<" "<<0<<endl;fflush(stdout);
    int y1;cin>>y1;
    int x1=a-y1;
    int x2=y1-b;
    int y2=x1-c;
    cout<<"A "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    fflush(stdout);
    int x;cin>>x;
      }
  return 0;
}