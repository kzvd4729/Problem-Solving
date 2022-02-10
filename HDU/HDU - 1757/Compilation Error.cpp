/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-21 01:03:31                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-1757
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m;
struct ex
{
    long mat[13][13];
};
ex multiply(ex a,ex b)
{
    ex tmp;
    for(long i=0; i<=9; i++)
    {
        for(long j=0; j<=9; j++)
        {
            tmp.mat[i][j]=0;
            for(long k=0; k<=9; k++)
            {
                tmp.mat[i][j]=(tmp.mat[i][j]+(a.mat[i][k]*b.mat[k][j])%m)%m;
            }
        }
    }
    return tmp;
}
ex expo(ex base,long n)
{
    ex xx;
    for(long i=0; i<=9; i++)
    {
        for(long j=0; j<=9; j++)
        {
            if(i==j)xx.mat[i][j]=1;
            else xx.mat[i][j]=0;
        }
    }
    while(n>0)
    {
        if(n&1)
        {
            xx=multiply(base,xx);
        }
        base=multiply(base,base);
        n/=2;
    }
    return xx;
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>m)
    {
        ex base;
        for(long i=0; i<=9; i++)
        {
            for(long j=0; j<=9; j++)
            {
                base.mat[i][j]=0;
            }
        }
        for(long i=0; i<=9; i++)
        {
            cin>>base.mat[0][i];
        }
        for(long i=1; i<=9; i++)
        {
            base.mat[i][i-1]=1;
        }
        if(n<=9)
        {
            cout<<n%m<<endl;
        }

        else
        {
            long ans=0;
            ex xx=expo(base,n-9);
            for(long i=0;i<=9;i++)
            {
                ans=(ans+((9-i)*xx.mat[0][i])%m)%m;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}