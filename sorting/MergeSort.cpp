#include<iostream>
using namespace std;

void printArray(int*,int,int);
void mergeSort(int*,int);
int computeMid(int start, int end);
void merge(int* a, int start, int end);

int* b;//global variable...//will be used as a temp array.


void mergeSort(int* a,int start,int end)
{	
	if((end-start)<1)
	{
		return;
	}
	int mid=computeMid(start,end);
	mergeSort(a,start,mid);
	mergeSort(a,mid+1,end);
	merge(a,start,end);
}

int main()
{
	int a[]={6,5,4,3,2,1,11,23,4};
	int len=sizeof(a)/sizeof(int);
	b=new int[len];	
	mergeSort(a,0,len-1);
    printArray(a,0,len-1);
    return 0;
}


int computeMid(int start, int end)
{
	return (start+end)/2;
}

void merge(int* a, int start, int end)
{
	if((end-start)<1)
	{
		return;
	}
	int mid=computeMid(start,end);
	int s1=start;int s2=mid+1;
	int l=start;
	while(s1<=mid && s2<=end)
	{
		if(a[s1]<=a[s2])
		{
			b[l]=a[s1];
			s1++;
		}
		else
		{
			b[l]=a[s2];
			s2++;
		}
		l++;
	}
	while(s1<=mid)
	{
		b[l]=a[s1];
		s1++;
		l++;
	}
	while(s2<=end)
	{
		b[l]=a[s2];
		s2++;
		l++;
	}
	for(int i=start;i<=end;i++)
	{
		a[i]=b[i];
	}
}


void printArray(int* a,int start, int end)
{
	cout<<"Printing Array:\n";
	for(int i=start;i<=end;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


