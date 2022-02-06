/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/22/2017 15:18                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/557/problem/A
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    long long int n,a1,a2,b1,b2,c1,c2,mx,mn,s1,s2,s3,x1,x2,x3;
    while(cin>>n)
    {
        cin>>a1>>a2>>b1>>b2>>c1>>c2;
        mx=a2+b2+c2;
        mn=a1+b1+c1;
          x3=n-(a2+b2);
        if(x3<=c1)x3=c1;
          n=n-x3;
          x1=(n-b1);
        if(x1<=a1)x1=a1;
        if(x1>=a2)x1=a2;
         x2=n-x1;
              cout<<x1<<" "<<x2<<" "<<x3<<endl;
       }
      return 0;
}