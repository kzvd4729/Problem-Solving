/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-07 02:09:05                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10192
****************************************************************************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
string str1,str2;
long int t[109][109];
int main()
{
    int i,j,l1,l2,tc=0;
    while(getline(cin,str1))
    {
        if(str1[0]=='#')break;
        getline(cin,str2);
        memset(t,0,sizeof(t));
        l1=str1.size();
        l2=str2.size();

        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                if(str1[i-1]==str2[j-1])
                    {
                        t[i][j]=t[i-1][j-1]+1;
                    }
                    else
                    {
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
            }
        }

        cout<<"Case #"<<++tc<<": you can visit at most "<<t[l1][l2]<<" cities."<<endl;

    }

    return 0;
}