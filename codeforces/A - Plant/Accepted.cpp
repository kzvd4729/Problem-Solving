/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/21/2018 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/185/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1000000007;
long n;
struct ex
{
    long mat[5][5];
};
ex multiply(ex one,ex two)
{
    ex ret;
    for(long i=1; i<=2; i++)
    {
        for(long j=1; j<=2; j++)
        {
            ret.mat[i][j]=0;
            for(long k=1; k<=2; k++)
            {
                ret.mat[i][j]=(ret.mat[i][j]+one.mat[i][k]*two.mat[k][j])%mod;
            }
        }
    }
    return ret;
}
ex expo(ex base)
{
    ex tmp;
    tmp.mat[1][1]=1;
    tmp.mat[1][2]=0;
    tmp.mat[2][1]=0;
    tmp.mat[2][2]=1;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    ex base;
    base.mat[1][1]=3;
    base.mat[1][2]=1;
    base.mat[2][1]=1;
    base.mat[2][2]=3;
     ex ans=expo(base);
     cout<<ans.mat[1][1]<<endl;
     return 0;
}