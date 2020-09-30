//Moore's Voting Algorithm
#include<bits/stdc++.h>
using namespace std;
int findMajority(int a[],int n)
{
    int maj_index=0,count=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[maj_index])
        count++;
        else
        count--;
        if(count==0)
        {
            maj_index=i;
            count=1;
        }
    }
    return a[maj_index];
}
int majorityElement(int a[],int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(key==a[i])
        count++;
    }
    if(count>n/2)
    return 1;
    else
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int cand=findMajority(a,n);
    if(majorityElement(a,n,cand))
    cout<<cand<<"\n";
    else
    cout<<"No majority element\n";
}