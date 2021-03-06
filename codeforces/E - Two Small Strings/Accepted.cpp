/****************************************************************************************
*  @author: * kzvd4729                                       created: Aug/30/2019 21:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1213/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n;
void print1(vector<char>v)
{
  cout<<"YES\n";
  for(int i=1;i<=n;i++)
    cout<<v[0]<<v[1]<<v[2];
  cout<<endl;exit(0);
}
void print2(vector<char>v)
{
  cout<<"YES\n";
  for(int i=1;i<=n;i++)cout<<v[0];
  for(int i=1;i<=n;i++)cout<<v[1];
  for(int i=1;i<=n;i++)cout<<v[2];
  cout<<endl;exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;string a,b;cin>>a>>b;
  vector<char>v;
  v.push_back('a');v.push_back('b');v.push_back('c');
   do
  {
    string x,y,z;
    x.push_back(v[0]);x.push_back(v[1]);
    y.push_back(v[1]);y.push_back(v[2]);
    z.push_back(v[2]);z.push_back(v[0]);
    if(x!=a&&x!=b&&y!=a&&y!=b&&z!=a&&z!=b)
      print1(v);
  }while(next_permutation(v.begin(),v.end()));
   if(a=="aa"||b=="aa"||a=="bb"||b=="bb"||a=="cc"||b=="cc")assert(0);
   sort(v.begin(),v.end());
  do
  {
    string x,y;
    x.push_back(v[0]);x.push_back(v[1]);
    y.push_back(v[1]);y.push_back(v[2]);
    if(x!=a&&x!=b&&y!=a&&y!=b)
      print2(v);
  }while(next_permutation(v.begin(),v.end()));
  cout<<"NO"<<endl;
  return 0;
}