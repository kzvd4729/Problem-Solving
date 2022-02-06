/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/28/2020 19:31                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/518/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long stringToNum(string s)
{
  long f=1;
  if(s[0]=='-')s.erase(s.begin()),f=-1;
  long ret=0;
  for(auto x:s)ret=ret*10+x-'0';
  return ret*f;
}
long aa[N+2];long qm[N+2];
void print(long n)
{
  for(long i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,k,id=n+1;cin>>n>>k;
  for(long i=1;i<=n;i++)
  {
    string s;cin>>s;
    if(s=="?")id=i;else aa[i]=stringToNum(s);
  }
  for(long i=1;i<=n;i++)qm[i]=qm[i-1]+aa[i];
  vector<long>a,b,c;
  for(long i=k;i<=n;i++)
  {
    long l=i-k+1,r=i;
    if(id>r)a.push_back(qm[r]-qm[l-1]);
    else if(id>=l&&id<=r)b.push_back(qm[r]-qm[l-1]);
    else c.push_back(qm[r]-qm[l-1]);
  }
  //cout<<a.size()<<" "<<b.size()<<" "<<c.size()<<endl;
  for(long i=1;i<a.size();i++)if(a[i-1]>=a[i])cout<<"Incorrect sequence\n",exit(0);
  for(long i=1;i<b.size();i++)if(b[i-1]>=b[i])cout<<"Incorrect sequence\n",exit(0);
  for(long i=1;i<c.size();i++)if(c[i-1]>=c[i])cout<<"Incorrect sequence\n",exit(0);
   if(b.size()==0)print(n);
  long mn=-inf*inf;if(a.size())mn=a.back();
  long mx=inf*inf;if(c.size())mx=c[0];
   //cout<<mn<<" ** "<<mx<<endl;
   long ad=(mn+1)-b[0];if(ad>inf)ad=inf;if(ad<-inf)ad=-inf;
  //cout<<ad<<endl;
  if(ad+b.back()>=mx)cout<<"Incorrect sequence\n",exit(0);
  long bd=ad+mx-(b.back()+ad)-1;
   if(ad<=0&&bd>=0)aa[id]=0;
  else if(ad<0&&bd<0)aa[id]=bd;
  else aa[id]=ad;print(n);
   return 0;
}