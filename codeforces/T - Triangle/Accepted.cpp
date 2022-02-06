/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729          created: Sep/15/2017 21:48                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100819/problem/T
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
bool f(int x,int y,int z)
{
    return (x*x==y*y+z*z);
}
int main()
{
    int a[4],b[4];
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];
    sort(a,a+3);
    sort(b,b+3);
    if(a[0]!=b[0]||a[1]!=b[1]||a[2]!=b[2])cout<<"NO"<<endl;
    else
    {
        if(f(a[0],a[1],a[2])||f(a[2],a[0],a[1])||f(a[1],a[2],a[0]))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}