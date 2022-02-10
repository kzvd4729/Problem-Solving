/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-30 23:03:23                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1058
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,n,x,y,xx,yy;
long mp1[98][98][98],mp2[98][98][98],mp3[98][98][98],mp4[98][98][98];
struct point
{
    long a,b,mid;
} p[1003];
int main()
{
    ///ofstream cout("out.txt");
    cin>>t;
    while(t--)
    {
        memset(mp1,0,sizeof(mp1));
        memset(mp2,0,sizeof(mp2));
        memset(mp3,0,sizeof(mp3));
        memset(mp4,0,sizeof(mp4));
        cin>>n;
        for(long i=1; i<=n; i++)cin>>p[i].a>>p[i].b;
        for(long i=1; i<=n; i++)
        {
            for(long j=i+1; j<=n; j++)
            {
                xx=p[i].a+p[j].a;
                yy=p[i].b+p[j].b;

                x=abs(xx);
                y=abs(yy);
                if(xx>=0&&yy>=0)
                {
                    x*=100007;
                    y*=10009;
                    mp1[x%89][y%89][((x+y)*19)%89]++;
                }

                else if(xx<0&&yy<0)
                {
                    x*=100007;
                    y*=10009;
                    mp2[x%89][y%89][((x+y)*19)%89]++;
                }
                else if(xx>=0&&yy<0)
                {
                    x*=100007;
                    y*=10009;
                    mp3[x%89][y%89][((x+y)*19)%89]++;
                }
                else
                {
                    x*=100007;
                    y*=10009;
                    mp4[x%89][y%89][((x+y)*19)%89]++;
                }
            }
        }
        long ans=0;
        for(int i=0; i<=89; i++)
        {
            for(int j=0; j<=89; j++)
            {
                for(int k=0; k<=89; k++)
                {
                    long x=mp1[i][j][k];
                    ans=ans+(x*(x-1))/2;
                }
            }
        }
        for(int i=0; i<=89; i++)
        {
            for(int j=0; j<=89; j++)
            {
                for(int k=0; k<=89; k++)
                {
                    long x=mp2[i][j][k];
                    ans=ans+(x*(x-1))/2;
                }
            }
        }
        for(int i=0; i<=89; i++)
        {
            for(int j=0; j<=89; j++)
            {
                for(int k=0; k<=89; k++)
                {
                    long x=mp3[i][j][k];
                    ans=ans+(x*(x-1))/2;
                }
            }
        }
        for(int i=0; i<=89; i++)
        {
            for(int j=0; j<=89; j++)
            {
                for(int k=0; k<=89; k++)
                {
                    long x=mp4[i][j][k];
                    ans=ans+(x*(x-1))/2;
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
    return 0;
}