/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 19:48:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12027
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
string s;
bool ck(int n,int l)
{
 n*=n;string a;
 while(n)
 {
  a.push_back((char)(n%10+'0'));
  n/=10;
 }
 reverse(a.begin(),a.end());
 if(a.size()+l+l<s.size())return true;
 if(a.size()+l+l>s.size())return false;
 for(int i=0;i<a.size();i++)
 {
  if(a[i]>s[i])return false;
  if(a[i]<s[i])return true;
 }
 return true;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 while(cin>>s)
 {
  if(s=="0")break;int ln=s.size();
  int tr=(ln+1)/2-2;tr=max(tr,0);
  int ans=-1,prn;
  while(true)
  {
   int f=0;
   for(int i=1;i<=9;i++)
   {
    if(ck(i,tr))
    {
     ans=i;prn=tr;
     f=1;
    }
   }
   if(!f)break;tr++;
  }
  if(ans==-1)assert(0);
  cout<<ans;
  while(prn--)
   cout<<0;
  cout<<"\n";
 }
 return 0;
}