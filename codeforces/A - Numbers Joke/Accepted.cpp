/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2017 19:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/784/problem/A
****************************************************************************************/
#include<iostream>
#include<string>
using namespace std;
int smith[]={4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517,526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985, 1086};
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<smith[n-1]<<endl;
    }
    return 0;
}