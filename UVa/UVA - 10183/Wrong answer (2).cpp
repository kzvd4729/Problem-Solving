/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-08 15:15:04                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10183
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s[501];
char temp[50001],order[50001];
void fibonacci(void)
{
    int i,l1,l2,x,c,k,z,l3,j;
    s[0]="0";
    s[1]="1";
    for(i=2;i<=500;i++)
    {
        l1=s[i-2].size();
        l2=s[i-1].size();
        c=0;
        k=0;
        while(l2!=0)
        {
            l1--;
            l2--;
            if(l1<0)x=int(s[i-1][l2]-'0')+c;
            else x=int(s[i-2][l1]-'0'+s[i-1][l2]-'0')+c;
            z=x%10;
            c=x/10;
            temp[k]=char(z+'0');
            k++;
        }

        while(c)
        {
            z=c%10;
            temp[k]=char(z+'0');
            k++;
            c=c/10;
        }
        temp[k]='\0';
        k=strlen(temp);

        for(j=0;j<strlen(temp);j++)
        {
            k--;
            order[j]=temp[k];
        }
        s[i]=order;


    }

}
int main()
{
    fibonacci();
    string s1,s2;
    int l1,l2,l,cnt,i;
    while(cin>>s1>>s2)
    {
        if(s1=="0"&&s2=="0")break;
        l1=s1.size();
        l2=s2.size();
        cnt=0;
        for(i=0;i<501;i++)
        {
            l=s[i].size();
            if(l>l2)break;
            if(l==l1&&l<l2)
            {
                if(s[i]>=s1)cnt++;
            }
            else if(l==l1&&l==l2)
            {
                if(s[i]>=s1&&s[i]<=s2)cnt++;
            }
            else if(l>l1&&l==l2)
            {
                if(s[i]<=s2)cnt++;
            }
            else if(l>l1&&l<l2)cnt++;

        }

        cout<<cnt<<endl;

    }
    return 0;
}