#include<iostream>
using namespace std;


void printArray(int*,int);
void sortArray(int*, int);

int main()
{
    int a[]={4,3,2,11,234,1234,54,2321,2321};
    int len=sizeof(a)/sizeof(*a);
    sortArray(a,len);
    printArray(a,len);
    return 0;
}

void sortArray(int *a,int len)
{
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[i])
            {
                int temp=a[i];
                for(int k=i-1;k>=j;k--)
                {
                    a[k+1]=a[k];
                }
                a[j]=temp;
                break;
            }            
        }
    }
}

void printArray(int* a, int len)
{
    cout<<"printing array\n";
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
