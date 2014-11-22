#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h> //memcpy is defined here..
using namespace std;

//this is a max heap...
class MaxHeap
{
	public:
		int GetHeapSize()
		{
			return this->heapSize;
		}
		
		MaxHeap(int* arr, int length)
		{
			this->arraySize = length;
			this->heapSize = length;
			a = new int[length];
			memcpy(a, arr, length*sizeof(int));			
			//printArray();
			buildHeap(); //sort the new array...			
		}
		
		~MaxHeap()
		{
			delete[] a; //free memory
		}

		void printArray()
		{
			for(int i=0; i<arraySize;i++)
			{
				cout<<a[i]<<" ";				
			}
			cout<<endl;
		}
		void printSortedArray()
		{
			for(int i=arraySize-1; i>=0; i--)
			{
				//exchange the root element with the last element..
				int temp = a[heapSize-1];
				a[heapSize-1] = a[0];
				a[0] = temp;
				cout<<a[heapSize-1]<<" ";				
				//decrement heap size;;
				heapSize--;				
				maxHeapify(0);
				//printArray();
			}
			cout<<endl;
		}

	private:
		int heapSize;
		int arraySize;
		int* a;		

		int left(int i) //return the left index of a node..
		{
			return 2*i+1;
		}

		int right(int i) //returns the right index of a node.
		{
			return 2*i+2;
		}

		void buildHeap() //builds the heap..
		{
			//all elements of floor(arraySize) to arraySize are leaf nodes. so they are max heaps by default.. 
			for(int i = (arraySize/2)-1; i>=0; i--)
			{
				maxHeapify(i);
			}
		}

		void maxHeapify(int i) //ensures that a subtree at node i is a max heap, given both its children are max heaps..
		{
			int l = left(i);
			int r = right(i);
			int largestIndex = i;
			//find the max(a[i], a[l], a[r])
			if( l<heapSize &&  a[l] > a[i])
			{
				largestIndex = l;
			}
			if (r<heapSize && a[r] > a[largestIndex])
			{
				largestIndex = r;
			}
			if(largestIndex!= i ) //it is already a max heap at node i if largestIndex == i.
			{
				//exchange a[largestIndex] and a[i]
				int temp = a[i];
				a[i] = a[largestIndex];
				a[largestIndex] = temp;
				
				//recursively ensure that the new subtree is a max heap..
				maxHeapify(largestIndex);
			}			
		}

};

int main()
{
	//unit tests..
	int a[] = {1,5,10,25,-9,30,5,10};
	//int a[] = {1,1,1,1,1,1,1};
	//int a[]= {1,2,1,2,1,2,1,2};
	
	MaxHeap h(a, sizeof(a)/sizeof(int));
	h.printSortedArray();	
		
	return 0;
}
