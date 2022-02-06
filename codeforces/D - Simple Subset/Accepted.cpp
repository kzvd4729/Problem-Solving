/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2019 16:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 17200 KB                             
*  problem: https://codeforces.com/contest/665/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int aa[N+2];
/************ Seive **************/
int Is_Prime[N+2];vector<int>Prime;
void Seive(int n)
{
  Prime.push_back(2);Is_Prime[1]=1;
  for(int i=4;i<=n;i+=2)Is_Prime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(Is_Prime[i])continue;Prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      Is_Prime[j]=1;
  }
}
///////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  Seive(N);int n;cin>>n;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];if(aa[i]==1)cnt++;
  }
  vector<int>ans;int mx=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(!Is_Prime[aa[i]+aa[j]])
      {
        int cn=cnt,now=2;
        if(aa[i]==1)cn--;
        if(aa[j]==1)cn--;
        if(now>mx)
        {
          ans.clear();mx=now;
          ans.push_back(aa[i]);
          ans.push_back(aa[j]);
        }
        if(!Is_Prime[aa[i]+1]&&!Is_Prime[aa[j]+1])
        {
          now+=cn;
          if(now>mx)
          {
            mx=now;ans.clear();
            ans.push_back(aa[i]);
            ans.push_back(aa[j]);
            while(cn--)ans.push_back(1);
          }
        }
      }
      //cout<<"* "<<ans.size()<<endl;
    }
  }
  if(ans.size()==0)ans.push_back(aa[1]);
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}