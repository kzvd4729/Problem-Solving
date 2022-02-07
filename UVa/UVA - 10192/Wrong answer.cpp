/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-07 02:00:28                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
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
        for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                if(i==0)
                {
                    if(str1[i]==str2[j])t[i][j]=1;
                    else if(j>0)t[i][j]=t[i][j-1];
                }
                else
                {
                    if(str1[i]==str2[j])
                    {
                        if(j==0)t[i][j]=1;
                        else t[i][j]=t[i-1][j-1]+1;
                    }
                    else
                    {
                        if(j==0)t[i][j]=t[i-1][j];
                        else t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
                }
            }
        }

        cout<<"Case #"<<++tc<<": you can visit at most "<<t[l1-1][l2-1]<<" cities."<<endl;

    }

    return 0;
}