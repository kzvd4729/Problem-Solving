/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-13 16:46:04                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1067
****************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
vector<long long int>f;
#define m 1000003
long long int fact(void)
{
    long long int i;
    f.push_back(1);
    for(i=1;i<=1000001;i++)
    {
       f.push_back((i*f[i-1])%m);
    }

}
int main()
{
    fact();
    long long int t,n,k,z,x,tc=0;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>k;
            x=n-k;

            z=(f[n]/(f[k]*f[x]));

            cout<<"Case "<<++tc<<": "<<z<<endl;
        }

    }

    return 0;
}