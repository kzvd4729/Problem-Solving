/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-13 16:12:13                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-374
****************************************************************************************/
#include<iostream>
using namespace std;
long long int bigmod(long long int b,long long int p,long long int m)
{
    long long int x;

    if(p==0)return 1;

    if(p%2==0)
    {
        x=bigmod(b,p/2,m);
        return ((x%m)*(x%m))%m;
    }

    else return (b%m)*(bigmod(b,p-1,m)%m);


}
int main()
{
    long long int b,p,m,z;
    while(cin>>b>>p>>m)
    {

        z=bigmod(b,p,m);

        cout<<z<<endl;

    }

    return 0;
}