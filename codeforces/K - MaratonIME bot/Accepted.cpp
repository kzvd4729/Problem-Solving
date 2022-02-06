/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 18:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/gym/101375/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string str,tmp;
int l,i;
bool check()
{
    for(i=0;i<l;i++)
    {
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='z'))tmp+=str[i];
        else
        {
            if(tmp=="Sussu")return true;
            tmp.clear();
        }
    }
    return false;
 }
int main()
{
    getline(cin,str);
    l=str.size();
    if(str[l-1]=='?')cout<<7<<endl;
    else if(check())cout<<"AI SUSSU!"<<endl;
    else cout<<"O cara é bom!"<<endl;
    return 0;
}