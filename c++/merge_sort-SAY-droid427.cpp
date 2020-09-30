//Merge Sort for sorting the array
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int r)
{
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    int L[n1],R[n2];
    //Copying the elements into separate arrays
    for(i=0;i<n1;i++)
    L[i]=a[l+i];
    for(j=0;j<n2;j++)
    R[j]=a[mid+j+1];
    //Initializing the variables
    i=0;
    j=0;
    k=l;
    //Merging the array
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;        
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }

}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Before sorting: ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
    mergesort(a,0,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}