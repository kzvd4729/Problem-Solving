/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2017 00:22                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 46 ms                                           memory_used: 2200 KB                              
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
        else if(strlen(one)>=strlen(two))cout<<strlen(one)<<endl;
        else cout<<strlen(two)<<endl;
     }
    return 0;
}