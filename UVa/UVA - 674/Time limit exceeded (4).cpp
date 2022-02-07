/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-02 21:16:16                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-674
****************************************************************************************/
#include<iostream>
using namespace std;
long int currency[]={1,5,10,25,50};
long int coin_change(long int i,long int n)
{
    if(n==0)return 1;
    if(n<0)return 0;

    if(i>=5)return 0;

    return coin_change(i,n-currency[i])+coin_change(i+1,n);
}
int main()
{
    long int n;
    while(cin>>n)
    {
        long int z=coin_change(0,n);
        cout<<z<<endl;

    }
    return 0;
}