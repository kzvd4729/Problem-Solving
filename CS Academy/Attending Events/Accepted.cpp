/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 21 ms                                           memory_used: 744 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int tr=1,ans=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(x==tr)
    {
      ans++;tr++;if(tr>3)tr=1;
    }
  }
  cout<<ans<<endl;
    return 0;
}