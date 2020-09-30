//C++ code to implement bubble sort
#include<bits/stdc++.h>
using namespace std;
void bubSort(int a[],int n)
{
    int t;
    for(int i=0;i<n-1;i++)
    {
       for(int j=i;j<n;j++)
       {
           if(a[j]>=a[j+1])
           {
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;     
           }
       }
    }
    cout<<"After sorting:";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubSort(a,n);
}