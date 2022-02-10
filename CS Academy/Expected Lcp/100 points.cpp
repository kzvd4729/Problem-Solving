/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 125 ms                                          memory_used: 53.1 MB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,sz,trie[2000000][27][2];
string s[1000006];
void insrt(string x,int vl)
{
int now=0;
for(int i=0;i<x.size();i++)
{
int z=x[i]-'a';
if(!trie[now][z][0])trie[now][z][0]=++sz;
trie[now][z][1]+=vl;
now=trie[now][z][0];   
}    
}
int query(string x)
{
int now=0,ret=0;
for(int i=0;i<x.size();i++)
{
int z=x[i]-'a';
ret+=trie[now][z][1];
now=trie[now][z][0];       
}
return ret;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    cin>>n;
for(int i=1;i<=n;i++)
{
cin>>s[i];
insrt(s[i],1);
}
int print=0;
for(int i=1;i<=n;i++)
{
insrt(s[i],-1);
print+=query(s[i]);
}
long cnt=(n*1LL*(n-1))/2;
double pr=(print*1.00)/(cnt*1.00);
cout<<setprecision(10)<<fixed<<pr<<endl;
return 0;
}