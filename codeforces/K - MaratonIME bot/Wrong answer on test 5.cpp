/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 14:28                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/gym/101375/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char s[30000];
int l,i;
bool check()
{
    for(i=0;i<=l-5;i++)
    {
        if(s[i]=='S'&&s[i+1]=='u'&&s[i+2]=='s'&&s[i+3]=='s'&&s[i+4]=='u')return true;
    }
    return false;
}
int main()
{
    gets(s);
    l=strlen(s);
    if(s[l-1]=='?')cout<<7<<endl;
    else if(check())cout<<"AI SUSSU!"<<endl;
    else cout<<"O cara é bom!"<<endl;
    return 0;
}