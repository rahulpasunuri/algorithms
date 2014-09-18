#include<iostream>
using namespace std;


void printArray(int *a, int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int *a,int len)
{
    for(int k=0; k<len;k++)
    {
        int max=a[k],max_index=k;
        bool swap=false;
        for(int i=k;i<len;i++)
        {
           if(max>a[i])
           {
                max_index=i;
                max=a[i];
                swap=true;
           }
        }       
        if(swap)
        {           
            a[max_index]=a[k];
            a[k]=max;   
        }
    }

}

int main()
{
    int a[]={1,2345,1231,67,123,63233,2356};
    int len=sizeof(a)/sizeof(*a);
    selectionSort(a,len);
    printArray(a,len);    
    return 0;
}
