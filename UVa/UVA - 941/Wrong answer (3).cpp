/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-11 18:13:36                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-941
****************************************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
string s;
long long int n,l,root,take;
long long int f[22];
vector<char>v;
void factorial(void)
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=20;i++)
    {
        f[i]=f[i-1]*i;
    }

}
void permutation(void)
{
    long long k=0,i;
    while(l!=1)
    {
        //cout<<s<<endl;
        l=s.size();
        root=f[l-1];

        take=ceil((double)n/(double)root);
        v.push_back(s[take-1]);
        s.erase(s.begin()+(take-1));
        n=n-(root*(take-1));

    }
    for(i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<endl;


}
int main()
{
    factorial();
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>s;
            cin>>n;
            n=n+1;
            sort(s.begin(),s.end());
            l=s.size();
            permutation();

            v.clear();
            s.clear();

        }

    }

    return 0;
}