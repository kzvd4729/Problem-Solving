/****************************************************************************************
*  @author: kzvd4729                                         created: 16-04-2018 20:50:29                      
*  solution_verdict: Compilation Error                       language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
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
for(long i=1;i<=m;i++)if(x%md[i]==0)return false;
return true;
}
void kato(void)
{
long rt=md[m];
for(int i=1;i<=m;i++)
{
long x=md[i];
while(x<=rt)mp[x]=1,x+=md[i];
}   
}
void extra(void)
{
for(long i=md[1]-1;i>=(md[1]-100LL);i--)pr.push_back(i);
for(long i=md[m]+1;i<=(md[m]+10000LL);i++)
{
if(prime(i))pr.push_back(i);     
}
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>k;
for(long i=1;i<=n;i++)cin>>aa[i];
for(long i=1;i<=m;i++)cin>>md[i];
    extra();
kato();
for(long i=md[1];i<=md[m];i++)if(mp[i]==0)pr.push_back(i);
pr.push_back(-1);   
sort(pr.begin(),pr.end());
for(long i=1;i<=n;i++)
{
        if(aa[i]+k<md[1])aa[i]+=k;
        else if(aa[i]+k>md[m])
{
int f=0;
for(long j=aa[i]+k;j>=aa[i];j--)
{
if(prime(j))
{
aa[i]=j;
f=1;
break;          
}    
}
if(f==0)aa[i]+=k;    
}
 else
{    
long x=lower_bound(pr.begin(),pr.end(),aa[i]+k+1)-pr.begin()-1;
x=pr[x];
if(x<aa[i]||x>aa[i]+k)aa[i]+=k;
else aa[i]=x;
}
}
for(long i=1;i<=n;i++)cout<<aa[i]<<" ";
cout<<endl;   
return 0;
}a