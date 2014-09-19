#include<iostream>
using namespace std;


void printArray(int*,int);
void sortArray(int*, int);

int main()
{
//    int a[]={4,3,2,11,234,1234,54,2321,2321};
    int a[]={1,2,3,1,5,1};
    int len=sizeof(a)/sizeof(*a);
    sortArray(a,len);
    printArray(a,len);
    return 0;
}

void sortArray(int *a,int len)
{
    for(int i=1;i<len;i++)
    {
        printArray(a,len);
        if(a[i-1]<=a[i])
        {
            continue;
        }
        for(int j=(i-2);j>=0;j--)
        {
            if(a[j]>a[i])
            {
                continue;
            }

            if(a[j]==a[i])
            {
                //we will maintain the original order of the values which are equal..
                //i.e., we will not swap values which are equal.
                j++;
            }        
            cout<<"printing j"<<j<<"\n";
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

void printArray(int* a, int len)
{
    cout<<"printing array\n";
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
