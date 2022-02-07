/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-02 21:31:33                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-674
****************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
long int currency[]={1,5,10,25,50};
long int dp[7490][5];
long int coin_change(long int i,long int n)
{
    if(n==0)return 1;
    if(n<0)return 0;

    if(i>4)return 0;

    if(dp[n][i]!=-1)return dp[n][i];

    return dp[n][i]=coin_change(i,n-currency[i])+coin_change(i+1,n);
}
int main()
{
    long int n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n)
    {
        long int z=coin_change(0,n);
        cout<<z<<endl;

    }
    return 0;
}