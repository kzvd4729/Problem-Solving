/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-12 00:18:52                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-13148
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    long long int n;
    while(cin>>n)
    {
        if(n==0)break;

        if(n==1||n==64||n==729||n==4096||n==15625||n==46656||n==117649||n==262144||n==531441||n==1000000||n==1771561||n==2985984||n==4826809||n==7529536||n==11390625||n==1677216||n==24137569||n==34012224||n==47045881||n==64000000||n==85766121)
        {
            cout<<"Special"<<endl;
        }
        else cout<<"Ordinary"<<endl;

    }


    return 0;
}