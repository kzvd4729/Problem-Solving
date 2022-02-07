/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-21 00:46:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10229
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m;
struct ex
{
    long mat[3][3];
};
ex multiply(ex a,ex b)
{
    ex tmp;
    for(long i=1;i<=2;i++)
    {
        for(long j=1;j<=2;j++)
        {
            tmp.mat[i][j]=0;
            for(long k=1;k<=2;k++)
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
    xx.mat[1][1]=1;
    xx.mat[1][2]=0;
    xx.mat[2][1]=0;
    xx.mat[2][2]=1;
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
        m=(1<<m);
        ex base;
        base.mat[1][1]=1;
        base.mat[1][2]=1;
        base.mat[2][1]=1;
        base.mat[2][2]=0;

        ex ans=expo(base,n-1);

        if(n==0)cout<<0<<endl;
        else if(n==1)cout<<1%m<<endl;
        else cout<<ans.mat[1][1]%m<<endl;

    }
    return 0;
}