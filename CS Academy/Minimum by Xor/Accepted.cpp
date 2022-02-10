/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 90 ms                                           memory_used: 1008 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,bin[20];
vector<int>v;
void make_binary(int x)
{
  v.clear();
  while(x)
  {
    v.push_back(x%2);
    x/=2;
  }
  reverse(v.begin(),v.end());
  memset(bin,0,sizeof(bin));
  int p=0;
  for(int i=n-v.size()+1;i<=n;i++)bin[i]=v[p++];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cout<<(1<<n)-1<<endl;
  for(int i=1;i<(1<<n);i++)
  {
    make_binary(i);
    int on=0;
    for(int j=1;j<=n;j++)if(bin[j])on++;
    cout<<on<<" ";
    for(int j=1;j<=n;j++)if(bin[j])cout<<j<<" ";
    cout<<endl;
  }
  return 0;
}