/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/12/2017 21:56                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/757/problem/A
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[100000];
    int len,i,j,x,z,m,n,cA,cu,cl,cb,ca,cs,cr,lowest;
    while(gets(str))
    {
        cA=0;cu=0;cl=0;cb=0;ca=0;cs=0;cr=0;
        lowest=999999;
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='B')cA++;
            else if(str[i]=='u')cu++;
            else if(str[i]=='l')cl++;
            else if(str[i]=='b')cb++;
            else if(str[i]=='a')ca++;
            else if(str[i]=='s')cs++;
            else if(str[i]=='r')cr++;
         }
        cu=cu/2;
        ca=ca/2;
        if(cA<lowest)lowest=cA;
        if(cu<lowest)lowest=cu;
        if(cl<lowest)lowest=cl;
        if(cb<lowest)lowest=cb;
        if(ca<lowest)lowest=ca;
        if(cs<lowest)lowest=cs;
        if(cr<lowest)lowest=cr;
        printf("%d\n",lowest);
     }
     return 0;
}