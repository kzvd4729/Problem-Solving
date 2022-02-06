/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/23/2017 21:01                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++11                               
*  run_time: 0 ms                                            memory_used: 2000 KB                              
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
             if(name2!=sus1)name1=sus1;
            else name1=sus2;
             cout<<name1<<" "<<name2<<endl;
          }
      }
      return 0;
}