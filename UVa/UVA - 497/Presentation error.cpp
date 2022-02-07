/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-25 01:11:10                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-497
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,len,lo,hi,mid;
    string s;
    vector<int>num;
    vector<int>v;
    vector<int>rev;
    int arr[10000];
    while(cin>>t)
    {
        getchar();
        getchar();

        while(t--)
        {
            while(getline(cin,s))
            {
                if(s=="")break;
                stringstream ss(s);
                ss>>n;
                num.push_back(n);

            }
            arr[0]=-999999;
            for(i=1;i<=9999;i++)
            {
                arr[i]=999999;
            }

            len=0;
            for(i=0;i<num.size();i++)
            {
                lo=0;
                hi=len;
                while(lo<=hi)
                {
                    mid=(lo+hi)/2;

                    if(arr[mid]<num[i])
                    {
                        lo=mid+1;
                    }
                    else hi=mid-1;


                }

                arr[lo]=num[i];
                v.push_back(lo);
                if(len<lo)len=lo;

            }
            cout<<"Max hits: "<<len<<endl;

            for(i=v.size()-1;i>=0;i--)
            {
                if(v[i]==len)
                {
                    rev.push_back(num[i]);
                    len--;
                }
            }

            for(i=rev.size()-1;i>=0;i--)
            {
                cout<<rev[i]<<endl;
            }
            num.clear();
            v.clear();
            rev.clear();

        }

    }


    return 0;
}
/*
1

1
6
2
3
5

*/