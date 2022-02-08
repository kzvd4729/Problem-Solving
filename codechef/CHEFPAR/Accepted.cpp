/****************************************************************************************
*  @author: kzvd4729                                         created: 16-04-2018 19:41:59                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 28.8M                                
*  problem: https://www.codechef.com/APRIL18A/problems/CHEFPAR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,aa[10004],md[10004];
vector<long>pr;
map<long,long>mp;
bool prime(long x)
{
long lim=sqrt(x+1);
for(int i=2;i<=lim;i++)if(x%i==0)return false;
return true;
}
void kato(void)
{
long rt=md[m];
for(int i=1;i<=m;i++)
{
long x=md[i];
while(x<=rt)mp[x]=1,x+=x;
}   
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>k;
for(long i=1;i<=n;i++)cin>>aa[i];
for(long i=1;i<=m;i++)cin>>md[i];
    for(long i=md[m]+1; ;i++)
{
if(prime(i))
{
pr.push_back(i);
break;
}
}
pr.push_back(md[1]-1);
pr.push_back(-1);
kato();
for(long i=md[1];i<=md[m];i++)if(mp[i]==0)pr.push_back(i);
    sort(pr.begin(),pr.end());
for(long i=1;i<=n;i++)
{
long x=upper_bound(pr.begin(),pr.end(),aa[i]+k)-pr.begin()-1;
x=pr[x];
if(x<aa[i])aa[i]+=k;
else aa[i]=x;
}
for(long i=1;i<=n;i++)cout<<aa[i]<<" ";
cout<<endl;   
return 0;
}