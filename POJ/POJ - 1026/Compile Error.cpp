/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-25 23:27:13                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-1026
****************************************************************************************/
#include<iostream>
#define long long long
using namespace std;
long n,key[202],k;
string s;
char str[202];
void convert(void)
{
    char tmp[202];
    for(long i=1;i<=n;i++)tmp[i]=' ';
    for(long i=1;i<=n;i++)
    {
        tmp[key[i]]=str[i];
        ///cout<<str[i]<<" "<<key[i]<<endl;
    }
    for(long i=1;i<=n;i++)str[i]=tmp[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        if(!n)break;
        for(long i=1;i<=n;i++)cin>>key[i];
        while(cin>>k)
        {
            if(!k)break;
            getline(cin,s);
            ///cout<<s<<endl;
            for(long i=1;i<=n;i++)str[i]=' ';
            for(long i=1;i<s.size();i++)str[i]=s[i];
            while(k--)convert();
            for(long i=1;i<=n;i++)
            {
                cout<<str[i];
            }
            cout<<endl;
        }
    }
    return 0;
}