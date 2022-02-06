/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2019 13:04                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1261/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s;
vector<pair<int,int> >v;
void place(int i,char c)
{
  i--;//cout<<c;
  if(s[i]==c)return ;
  int n=s.size();
  for(int j=i+1;j<n;j++)
  {
    if(s[j]==c)
    {
      reverse(s.begin()+i,s.end()-(n-j-1));
      v.push_back({i+1,j+1});return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k>>s;
    for(int i=1;i<=2*k;i+=2)
    {
      place(i,'(');place(i+1,')');
    }
    int rm=n-2*k;
    for(int i=2*k+1;i<=2*k+rm/2;i++)
      place(i,'(');
    for(int i=2*k+rm/2+1;i<=n;i++)
      place(i,')');
    //cout<<endl;
    cout<<v.size()<<"\n";
    for(auto x:v)
      cout<<x.first<<" "<<x.second<<"\n";
    v.clear();
  }
  return 0;
}