/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-15 15:11:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 410                                        memory_used (MB): 223.2                           
*  problem: https://vjudge.net/problem/SPOJ-TDPRIMES
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e8;
int pr[50000000],id;
bitset<N+2>vis;

void seive(void)
{
int lim=sqrt(N+1);
pr[++id]=2;
for(int i=4;i<=N;i+=2)vis[i]=1;
for(int i=3;i<=N;i+=2)
{
if(vis[i])continue;
//id++;
pr[++id]=i;
if(i>lim)continue;
for(int j=i*i;j<=N;j+=2*i)
vis[j]=1;
}
}

int main()
{
seive();
//cout<<id<<endl;
for(int i=1;i<=id;i+=100)
{
printf("%d\n",pr[i]);
//getchar();
}

return 0;
}