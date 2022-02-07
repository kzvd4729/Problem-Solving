/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-11 19:14:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 190                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-941
****************************************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
string s;
long long int n,l,root,take;
long long int f[22];
void factorial(void)
{
    f[0]=1;
    f[1]=1;
    for(long long int i=2;i<=20;i++)
    {
        f[i]=f[i-1]*i;
    }

}
void permutation(void)
{
    long long int k=0,i;
    l=s.size();
    while(l)
    {

        root=f[l-1];
        take=ceil((long double)n/(long double)root);
        cout<<s[take-1];
        s.erase(s.begin()+(take-1));
        n=n-(root*(take-1));
        l=s.size();

    }
    cout<<endl;

}
int main()
{
    factorial();
    long long int t;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>s;
            cin>>n;
            n=n+1;
            sort(s.begin(),s.end());
            permutation();

            s.clear();

        }

    }

    return 0;
}