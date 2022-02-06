/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2019 20:30                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 2682 ms                                         memory_used: 47600 KB                             
*  problem: https://codeforces.com/contest/632/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double pi=acos(-1.0);
void fft(vector<complex<double> >&a,bool inv)
{
 int n=a.size();
 for(int i=1,j=0;i<n;i++)
 {
  int bit=n/2;
  for( ;j&bit;bit/=2)
   j^=bit;
  j^=bit;
  if(i<j)swap(a[i],a[j]);
 }
 for(int ln=2;ln<=n;ln*=2)
 {
  double ang=2*pi/ln*(inv?-1:1);
  complex<double>wlen(cos(ang),sin(ang));
  for(int i=0;i<n;i+=ln)
  {
   complex<double>w(1);
   for(int j=0;j<ln/2;j++)
   {
    complex<double>u=a[i+j],v=a[i+j+ln/2]*w;
    a[i+j]=u+v;a[i+j+ln/2]=u-v;
    w*=wlen;
   }
  }
 }
 if(inv)for(auto &x:a)x/=n;
}
vector<int>multiply(vector<int>&a,vector<int>&b)
{
 int sz=a.size()+b.size();
 int n=1;while(n<sz)n*=2;
 vector<complex<double> >fa(a.begin(),a.end());
 vector<complex<double> >fb(b.begin(),b.end());
 fa.resize(n);fb.resize(n);
 fft(fa,false);fft(fb,false);
 for(int i=0;i<n;i++)fa[i]*=fb[i];
 fft(fa,true);vector<int>ret(n);
 for(int i=0;i<n;i++)
  ret[i]=round(fa[i].real());
 return ret;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n,k;cin>>n>>k;vector<int>a(1001,0);
 for(int i=1;i<=n;i++)
 {
  int x;cin>>x;a[x]=1;
 }
 vector<int>ans(1001,0);ans[0]=1;
 while(k)
 {
  if(k%2)ans=multiply(ans,a);
  a=multiply(a,a);k/=2;
 }
 for(int i=1;i<ans.size();i++)
  if(ans[i])cout<<i<<" ";
 cout<<endl;
 return 0;
}