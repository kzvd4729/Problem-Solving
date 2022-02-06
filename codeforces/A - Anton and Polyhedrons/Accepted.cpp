/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/15/2017 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 452 ms                                          memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/785/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n,i,sum;
    while(cin>>n)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            cin>>s;
            if(s=="Tetrahedron")sum=sum+4;
            else if(s=="Cube")sum=sum+6;
            else if(s=="Octahedron")sum=sum+8;
            else if(s=="Dodecahedron")sum=sum+12;
            else if(s=="Icosahedron")sum=sum+20;
        }
        cout<<sum<<endl;
      }
      return 0;
}