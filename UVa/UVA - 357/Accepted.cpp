/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-24 20:24:58                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-357
****************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
long long int coin[]={1,5,10,25,50};
long long int dp[6][100000];
long long int f(long long int n,long long int k)
{
    if(k<0||n<0)return 0;
    if(n==0)return 1;
    if(dp[k][n]!=-1)return dp[k][n];

    dp[k][n]=f(n-coin[k],k)+f(n,k-1);
    return dp[k][n];


}
int main()
{
    long long int n,z;
    memset(dp,-1,sizeof(dp));
    while(cin>>n)
    {
        z=f(n,4);
        if(z==1)cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        else cout<<"There are "<<z<<" ways to produce "<<n<<" cents change."<<endl;

    }

    return 0;
}