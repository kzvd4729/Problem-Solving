/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 14:22:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-494
****************************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
    while(getline(cin,s))
    {
        int l=s.size();
        int f,cnt=0,i;
        f=0;
        for(i=0;i<l;i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            {
                f=1;
            }
            else if(f==1)f=2;
            if(f==2)
            {
                cnt++;
                f=0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}