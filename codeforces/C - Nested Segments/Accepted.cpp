/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/30/2018 21:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 16400 KB                             
*  problem: https://codeforces.com/contest/976/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
struct data
{
  int x,y,id;
}arr[300005];
bool cmp(data A,data B)
{
  if(A.x!=B.x)return A.x<B.x;
  else return A.y>B.y;
}
set<pair<int,int> >st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].x>>arr[i].y;
    arr[i].id=i;
    st.insert({arr[i].y,arr[i].id});
  }
  sort(arr+1,arr+n+1,cmp);
   for(int i=1;i<=n;i++)
  {
    if(st.size()==0)break;
    st.erase({arr[i].y,arr[i].id});
    if(st.size()==0)break;
    pair<int,int>p=*st.begin();
    if(p.first<=arr[i].y)
    {
      cout<<p.second<<" "<<arr[i].id<<endl;
      return 0;
    }
  }
  cout<<-1<<" "<<-1<<endl;
  return 0;
}