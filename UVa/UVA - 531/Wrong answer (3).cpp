/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-03 23:17:16                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-531
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string str;
string text1[110];
string text2[110];
vector<string>ans;
int mat[110][110];
int main()
{
    int i,l1,l2,j,mx;
    
        memset(mat,0,sizeof(mat));
        for(i=1;  ;i++)
        {
            cin>>str;
            if(str=="#")break;
            text1[i]=str;

        }
        l1=i;
        for(i=1;  ;i++)
        {
            cin>>str;
            if(str=="#")break;
            text2[i]=str;

        }
        l2=i;

        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                if(j==1)
                {
                    if(text1[i]==text2[j])mat[i][j]=1;
                }
                else
                {
                    if(text1[i]==text2[j])mat[i][j]=mat[i-1][j-1]+1;
                    else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
                }
            }
        }
        /*for(i=1;i<l1;i++)
        {
            for(j=1;j<l2;j++)
            {
                cout<<mat[i][j];
            }
            cout<<endl;
        }*/


        mx=mat[l1][l2];

        for(i=l1+1;i>0;i--)
        {
            for(j=l2+1;j>0;j--)
            {
                if(mx==mat[i][j]&&text1[i]==text2[j])
                {
                    ans.push_back(text2[j]);
                    mx--;
                    break;
                }
            }
        }

        int l=ans.size();

        for(i=l-1;i>0;i--)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;







    


    return 0;
}