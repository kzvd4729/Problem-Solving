/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 17 ms                                           memory_used: 692 KB                               
*  problem: 
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
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    int fr=abs(e-a)+abs(f-b);
    int mn=min(abs(e-c),abs(f-d));
    int sc=abs(e-c)+abs(f-d)-mn;
    //cout<<fr<<" ** "<<sc<<endl;
    if(fr==sc)cout<<"Same time\n";
    else if(fr<sc)cout<<"First\n";
    else cout<<"Second\n";
  }
  return 0;
}