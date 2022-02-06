/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2018 02:14                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/678/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000007;
long a,b,x,n;
struct data
{
    long mat[4][4];
};
data multiply(data a,data b)
{
    data ret;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            ret.mat[i][j]=0;
            for(int k=1;k<=2;k++)
            {
                ret.mat[i][j]=(ret.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
            }
        }
    }
    return ret;
}
data expo(data base,int n)
{
    data unq;
    unq.mat[1][1]=1;
    unq.mat[1][2]=0;
    unq.mat[2][1]=0;
    unq.mat[2][2]=1;
    while(n)
    {
        if(n&1)unq=multiply(unq,base);
        base=multiply(base,base);
        n/=2;
    }
    return unq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        cin>>a>>b>>n>>x;
    data base;
    base.mat[1][1]=a;
    base.mat[1][2]=b;
    base.mat[2][1]=0;
    base.mat[2][2]=1;
    data ans=expo(base,n);
     cout<<(ans.mat[1][1]*x+ans.mat[1][2])%mod<<endl;
    return 0;
}