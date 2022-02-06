/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2019 15:28                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++14                               
*  run_time: 2500 ms                                         memory_used: 6200 KB                              
*  problem: https://codeforces.com/contest/117/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
bitset<N+2>ot[N+2],in[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;i++)
  {
    string s;cin>>s;
    for(int j=0;j<n;j++)
      if(s[j]=='1')ot[i][j]=1,in[j][i]=1;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(ot[i][j]&&(in[i]&ot[j]).count())
      {
        cout<<i+1<<" "<<j+1<<" ";
        in[i]&=ot[j];
        cout<<in[i]._Find_first()+1<<endl;
        exit(0);
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}