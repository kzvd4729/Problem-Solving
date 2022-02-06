/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2018 12:03                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/850/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const int R=4e4;
int vis[R+2];
vector<int>pr;
void seive(void)
{
 for(int i=2;i<=R;i++)
 {
  if(vis[i])continue;
  pr.push_back(i);
  for(int j=i+i;j<=R;j+=i)
   vis[j]=1;
 }
}
int grundy(vector<int>v)
{
 set<int>st;
 for(int i=0;i<pr.size();i++)
 {
  long prime=pr[i];
  while(true)
  {
   vector<int>tmp=v;int f=0;
   for(int j=0;j<tmp.size();j++)
   {
    if(tmp[j]%prime==0)
    {
     tmp[j]/=prime;
     f=1;
    }
   }
   if(f)
   {
    st.insert(grundy(tmp));
    prime*=(pr[i]*1LL);
   }
   else break;
  }
 }
 for(int i=0;i<50;i++)
  if(st.find(i)==st.end())return i;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 seive();int n;cin>>n;vector<int>v;
 for(int i=1;i<=n;i++)
 {
  int x;cin>>x;v.push_back(x);
 }
 if(grundy(v))cout<<"Mojtaba"<<endl;
 else cout<<"Arpa"<<endl;
 return 0;
}