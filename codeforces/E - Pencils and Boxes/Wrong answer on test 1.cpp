/****************************************************************************************
*  @author: kzvd4729                                         created: May/22/2018 13:40                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/985/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,k,d,arr[N+2],dp[N+2],seg[4*N];
void upd(int node,int lo,int hi,int id)
{
  if(lo==hi)
  {
    seg[node]=1;
    return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id);
  else upd(node*2+1,md+1,hi,id);
  seg[node]=seg[node*2]+seg[node*2+1];
}
int query(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return query(node*2,lo,md,lt,rt)+query(node*2+1,md+1,hi,lt,rt);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k>>d;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
 //  for(int i=1;i<=n;i++)
//    cout<<arr[i]<<" ";
//  cout<<endl;
  int i;
  for(i=1;i<=n;i++)
  {
    if(arr[i]-arr[1]>d)break;
    if(i>=k)
    {
      dp[i]=1;
      upd(1,1,n,i);
    }
  }
//   for(int i=1;i<=n;i++)
//    cout<<dp[i]<<" ";
//  cout<<endl;
//  cout<<i<<endl;
  for( ;i<=n;i++)
  {
    int lt=lower_bound(arr+1,arr+i,arr[i]-d)-arr;
    int rt=i-k+1;
    lt--;
    rt--;
    //cout<<dp[rt]<<" "<<dp[lt-1]<<endl;
    if(lt>rt)continue;
    int x=query(1,1,n,lt,rt);
    if(x)dp[i]=1;
  }
  for(int i=1;i<=n;i++)
    cout<<dp[i]<<" ";
  cout<<endl;
  if(dp[n])cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}