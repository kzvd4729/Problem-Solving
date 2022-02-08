/****************************************************************************************
*  @author: kzvd4729                                         created: 29-06-2019 20:55:39                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.19 sec                                        memory_used: 15.5M                                
*  problem: https://www.codechef.com/LTIME73A/problems/GIIKLUB
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20;
long n,xx,mt[N+2][N+2];
vector<long>fr,rv;
void fdfs(int i,int j,long sm)
{
  if(sm>xx)return ;
  if(i==n&&j==n)
  {
    fr.push_back(sm);
    return ;
  }
  if(i!=n)fdfs(i+1,j,sm+mt[i+1][j]);
  if(j!=n)fdfs(i,j+1,sm+mt[i][j+1]);
}
void rdfs(int i,int j,long sm)
{
  if(sm>xx)return ;
  if(i==1&&j==1)
  {
    rv.push_back(sm);
    return ;
  }
  if(i!=1)rdfs(i-1,j,sm+mt[i-1][j]);
  if(j!=1)rdfs(i,j-1,sm+mt[i][j-1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>xx;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>mt[i][j];
    long ans=0;
    for(int i=1;i<=n;i++)
    {
      fr.clear();rv.clear();
      fdfs(i,n-i+1,mt[i][n-i+1]);
      rdfs(i,n-i+1,0);
      /*cout<<endl<<endl;
      for(auto x:fr)
        cout<<x<<" ";
      cout<<endl;
      for(auto x:rv)
        cout<<x<<" ";
      cout<<endl;
      cout<<endl<<endl;*/
      sort(fr.begin(),fr.end());
      sort(rv.begin(),rv.end());
      reverse(fr.begin(),fr.end());
      rv.push_back(xx+1);int id=0;
      for(auto x:fr)
      {
        while(x+rv[id]<=xx)id++;
        ans+=id*1LL;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}