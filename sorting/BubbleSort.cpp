#include<iostream>
using namespace std;

void printArray(int*, int);
void bubbleSort(int*, int);

int main()
{
	int a[]={6,5,4,3,2,1};
	int len=sizeof(a)/sizeof(int);
	bubbleSort(a,len);
	printArray(a,len);
    return 0;
}

void bubbleSort(int* a, int len)
{	
	bool swapped=false;
	for(int i=0;(i<len) && (!swapped);i++)
	{
		swapped=true;
		for(int j=0; j < (len-i-1); j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				swapped=false;
			}
		}	
	}
}


void printArray(int* a, int len)
{
    cout<<"Printing Array\n";
    for(int i=0; i < len; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
