/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-30 22:45:25                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1058
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,x,y,xx,yy;
long mp[111][111][111];
struct point
{
    long a,b,mid;
}p[1003];
int main()
{
    ///ofstream cout("out.txt");
    cin>>t;
    while(t--)
    {
        memset(mp,0,sizeof(mp));
        cin>>n;
        for(long i=1;i<=n;i++)cin>>p[i].a>>p[i].b;
        for(long i=1;i<=n;i++)
        {
            for(long j=i+1;j<=n;j++)
            {
                x=p[i].a+p[j].a;
                y=p[i].b+p[j].b;
                x+=978987897898500;
                y+=989878976898999;
                x*=119;
                y*=119;
                mp[(x%109)%109][(y%109)%109][((x+y)*19)%109]++;
            }
        }
        long ans=0;
        for(int i=0;i<=109;i++)
        {
            for(int j=0;j<=109;j++)
            {
                for(int k=0;k<=109;k++)
                {
                    long x=mp[i][j][k];
                    ans=ans+(x*(x-1))/2;
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}