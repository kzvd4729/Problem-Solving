/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/23/2017 21:10                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/776/problem/A
****************************************************************************************/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    string name1,name2,sus1,sus2;
    int day,i;
    while(cin>>name1>>name2)
    {
        cin>>day;
        cout<<name1<<" "<<name2<<endl;
        for(i=1;i<=day;i++)
        {
            cin>>sus1>>sus2;
            if(name1==sus1)name1=sus2;
            else if(name1==sus2)name1=sus1;
            else if(name2==sus1)name2=sus2;
            else if(name2==sus2)name2=sus1;
             cout<<name1<<" "<<name2<<endl;
          }
      }
      return 0;
}