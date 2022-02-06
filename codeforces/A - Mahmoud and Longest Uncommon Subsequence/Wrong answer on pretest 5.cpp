/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2017 00:19                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/766/problem/A
****************************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    char one[100001],two[100001];
    int lone,ltwo,cnt,best,flag,i,j,x,z;
    while(cin>>one>>two)
    {
        if(!strcmp(one,two))cout<<-1<<endl;
        else cout<<strlen(two)<<endl;
     }
    return 0;
}