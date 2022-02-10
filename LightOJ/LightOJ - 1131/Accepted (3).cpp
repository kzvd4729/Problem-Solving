/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-24 20:12:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 324                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1131
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,tc,q,n,f0,f1,f2,g0,g1,g2,mod;
struct matrix
{
    long mat[10][10];
};
matrix multiply(matrix one,matrix two)
{
    matrix three;
    for(int i=1; i<=6; i++)
    {
        for(int j=1; j<=6; j++)
        {
            three.mat[i][j]=0;
            for(int k=1; k<=6; k++)
            {
                three.mat[i][j]=(three.mat[i][j]+one.mat[i][k]*two.mat[k][j])%mod;
            }
        }
    }
    return three;
}
matrix expo(matrix base)
{
    matrix tmp;
    for(long i=1;i<=6;i++)
    {
        for(long j=1;j<=6;j++)
        {
            if(i==j)tmp.mat[i][j]=1;
            else tmp.mat[i][j]=0;
        }
    }
    while(n)
    {
        if(n%2==0)
        {
            base=multiply(base,base);
            n/=2;
        }
        else
        {
            tmp=multiply(tmp,base);
            n--;
        }
    }
    return tmp;
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        matrix base;
        for(long i=1;i<=6;i++)
        {
            for(long j=1;j<=6;j++)base.mat[i][j]=0;
        }
        cin>>base.mat[1][1]>>base.mat[1][2]>>base.mat[1][6];
        cin>>base.mat[4][4]>>base.mat[4][5]>>base.mat[4][3];
        base.mat[2][1]=base.mat[3][2]=base.mat[5][4]=base.mat[6][5]=1;
        cin>>f0>>f1>>f2>>g0>>g1>>g2;
        cin>>mod;
        cin>>q;
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>n;
            if(n==0)cout<<f0%mod<<" "<<g0%mod<<endl;
            else if(n==1)cout<<f1%mod<<" "<<g1%mod<<endl;
            else if(n==2)cout<<f2%mod<<" "<<g2%mod<<endl;
            else
            {
                n-=2;
                matrix ans=expo(base);
//                cout<<endl;
//                for(long i=1;i<=6;i++)
//                {
//                    for(long j=1;j<=6;j++)
//                    {
//                        cout<<ans.mat[i][j]<<" ";
//                    }
//                    cout<<endl;
//                }
//                cout<<endl;
                long x=((ans.mat[1][1]*f2)%mod+(ans.mat[1][2]*f1)%mod+(ans.mat[1][3]*f0)%mod+(ans.mat[1][4]*g2)%mod+(ans.mat[1][5]*g1)%mod+(ans.mat[1][6]*g0)%mod)%mod;
                long y=((ans.mat[4][1]*f2)%mod+(ans.mat[4][2]*f1)%mod+(ans.mat[4][3]*f0)%mod+(ans.mat[4][4]*g2)%mod+(ans.mat[4][5]*g1)%mod+(ans.mat[4][6]*g0)%mod)%mod;
                cout<<x<<" "<<y<<endl;
            }
        }
    }
    return 0;
}