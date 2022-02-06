/****************************************************************************************
*  @author: kzvd4729                                         created: May/31/2018 00:46                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 592 ms                                          memory_used: 15200 KB                             
*  problem: https://codeforces.com/contest/987/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int arr[N+2],a[N+2],pos[N+2];
int n,cnt;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   for(int i=1;i<=n;i++)
    a[i]=i,pos[i]=i;
   for(int i=1;i<=n;i++)
  {
    int x=arr[i];
    if(a[i]==x)continue;
    cnt++;
    int tmp=a[i];
    swap(a[i],a[pos[x]]);
    pos[tmp]=pos[x];
    pos[x]=i;
  }
  if((n%2)&&(cnt%2))cout<<"Petr"<<endl;
  else if((n%2)&&!(cnt%2))cout<<"Um_nik"<<endl;
  if(!(n%2)&&!(cnt%2))cout<<"Petr"<<endl;
  else if(!(n%2)&&(cnt%2))cout<<"Um_nik"<<endl;
  return 0;
}