/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-23 15:05:17                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 439                                        memory_used (MB): 9.9                             
*  problem: https://vjudge.net/problem/LightOJ-1234
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int R=1e8;
double mm[1000006];
int t,tc,n;
 
void precal(void)
{
for(int i=0;i<=1000005;i++)mm[i]=0.0;
for(int i=1;i<=R;i++)
mm[(i/100)+1]+=(1.00/(i*1.00));
for(int i=1;i<=1000001;i++)
    mm[i]+=mm[i-1];
}
 
int main()
{
precal();
//for(int i=0;i<10;i++)cout<<mm[i]<<" ";
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
int x=n/100;
double ans=mm[x];
//cout<<ans<<" "<<x<<endl;
for(int i=x*100;i<=n;i++)
{
if(i==0)continue;
ans+=(1.00/(i*1.00));
}
printf("Case %d: %0.12lf\n",++tc,ans);
/*cout<<setprecision(12)<<fixed;
cout<<"Case "<<++tc<<": "<<ans<<endl;*/
}
return 0;
}