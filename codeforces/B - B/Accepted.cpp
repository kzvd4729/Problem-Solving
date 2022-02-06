/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 45300 KB                             
*  problem: https://codeforces.com/gym/100009/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e7;
/************ Seive **************/
int IsPrime[N+2];vector<int>Prime;
void Seive(int n)
{
  Prime.push_back(2);IsPrime[1]=1;
  for(int i=4;i<=n;i+=2)IsPrime[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(IsPrime[i])continue;Prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      IsPrime[j]=1;
  }
}
///////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);Seive(N);
  long n;
  while(cin>>n)
  {
    if(n<0)break;
    for(auto x:Prime)
    {
      while(n%x==0)
      {
        cout<<"    "<<x<<"\n";n/=x;
      }
    }
    if(n>1)cout<<"    "<<n<<"\n";
    cout<<"\n";
  }
  return 0;
}