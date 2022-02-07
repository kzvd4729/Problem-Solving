/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-21 11:23:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 70                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10870
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long fn[20],n,m,d;
struct ex
{
    long mat[20][20];
};
ex multiply(ex a,ex b)
{
    ex tmp;
    for(long i=1;i<=d;i++)
    {
        for(long j=1;j<=d;j++)
        {
            tmp.mat[i][j]=0;
            for(long c=1;c<=d;c++)
            {
                tmp.mat[i][j]=(tmp.mat[i][j]+(a.mat[i][c]*b.mat[c][j])%m)%m;
            }
        }
    }
    return tmp;
}
ex matrix_expo(ex base,long k)
{
    ex tmp;
    for(long i=1;i<=d;i++)
    {
        for(long j=1;j<=d;j++)
        {
            if(i==j)tmp.mat[i][j]=1;
            else tmp.mat[i][j]=0;
        }
    }
    while(k)
    {
        if(k%2==1)
        {
            tmp=multiply(base,tmp);
        }
        base=multiply(base,base);
        k/=2;
    }
    return tmp;
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>d>>n>>m)
    {
        if(d==0&&n==0&&m==0)break;
        ex base;
        for(long i=1; i<=d; i++)
        {
            for(long j=1; j<=d; j++)
            {
                base.mat[i][j]=0;
            }
        }
        for(long i=1; i<=d; i++)
        {
            cin>>base.mat[1][i];
        }
        for(long i=2; i<=d; i++)
        {
            base.mat[i][i-1]=1;
        }
        for(long i=1; i<=d; i++)cin>>fn[i];
        if(n<=d)
        {
            cout<<fn[n]%m<<endl;
        }
        else
        {
            long ans=0;
            ex xx=matrix_expo(base,n-d);
            for(long i=1;i<=d;i++)
            {
                ans=(ans+(xx.mat[1][i]*fn[d-i+1])%m)%m;
            }
            cout<<ans<<endl;
        }

    }

    return 0;
}