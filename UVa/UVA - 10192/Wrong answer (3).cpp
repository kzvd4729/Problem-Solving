/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-06 21:40:56                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10192
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char str1[103],str2[103];
int t[103][103];
int main()
{
    int i,j,l1,l2,tc=0;
    while(gets(str1))
    {
        if(str1[0]=='#')break;
        gets(str2);

        memset(t,0,sizeof(t));

        int l1=strlen(str1);
        int l2=strlen(str2);
        int i,j;
        for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                if(i==0)
                {
                    if(str1[i]==str2[j])t[i][j]=1;
                    else
                    {
                        if(j>0)t[i][j]=t[i][j-1];
                    }
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

        if(t[l1-1][l2-1]==1||t[l1-1][l2-1]==0)cout<<"Case #"<<++tc<<": you can visit at most "<<t[l1-1][l2-1]<<" city."<<endl;

        else cout<<"Case #"<<++tc<<": you can visit at most "<<t[l1-1][l2-1]<<" cities."<<endl;

    }


    return 0;
}