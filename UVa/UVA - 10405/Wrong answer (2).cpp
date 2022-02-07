/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-06 20:36:00                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10405
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char str1[1002],str2[1002];
long int t[1002][1002];
int main()
{
    int i,j,l1,l2;
    while(cin>>str1>>str2)
    {
        memset(t,0,sizeof(t));
        l1=strlen(str1);
        l2=strlen(str2);
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

        /*for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                cout<<t[i][j];
            }
            cout<<endl;
        }*/
        cout<<t[l1-1][l2-1]<<endl;



    }



    return 0;
}