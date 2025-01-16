#include<iostream>
using namespace std;
int main()
{
    int n,a[20],key;
    int count=0;
    cout<<"Enter the total no. of keys:"<<endl;
    cin>>n;
    cout<<"Enter the actual keys:"<<endl;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    while(low<=high)
    {
        if(a[mid]==0)
        {
            if(a[mid-1]==1 && a[mid]==0)
            {
                count=n-mid;
            break;
            }
        else
        {
            high=mid-1;
        }
    }
    else
    {
        low=mid+1;
    }
}
if(count==0)
{
    cout<<"Not FOund"<<endl;
}
else
{
    cout<<"count of zero is"<<count<<endl;
}
return 0;
}
