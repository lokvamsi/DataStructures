#include <stdio.h>
#include <iostream>
#include <array>
using namespace std;

//Function to swap the values in an array A[] and indexes a and b.
void SwapValuesAt(int A[], int a, int b){
	int temp = A[a];
	A[a] = A[b];
	A[b] = temp;
	return;
}

//Function to heapify (Percolate Down) the given array A starting from index i.
void Heapify(int A[], int i){
	int right = i*2;
	int left = i*2 + 1;
	int largest = i;
	if(A[left]>A[largest] && left<=A[0]){
		largest = left;
	}
	if(A[right]>A[largest] && right<=A[0]){
		largest = right;
	}
	if(i!=largest){
		SwapValuesAt(A,i,largest);
		Heapify(A, largest);
	}
	return;
}

//Function to build the heap using Heapify.
void BuildHeap(int A[]){
	for(int i = A[0]/2; i>0; i--){
		Heapify(A,i);
	}
	return;
}

//Function to print the elements of array A.
void PrintList(int A[]){
	for(int i = 0; i<A[0]+1; i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return;
}

//Function implementing HeapSort in place on A.
void HeapSort(int A[]){
	
	BuildHeap(A);
	printf("Printing Array after BuildHeap.\n");
	PrintList(A);
	printf("\n");
	
	int size = A[0];
	while (A[0]>1){
		SwapValuesAt(A,1, A[0]);
		A[0]--;
		Heapify(A, 1);
	}
	A[0] = size;
	return;
}

//Function to remove the null (-1) values by swapping to the end of array.
void Remove_Nulls(int A[]){
	int end = 21;
	for(int i = 1; i<end; i++){
		if(A[i] == -1){
			SwapValuesAt(A,i,end);
			end--;
		}
	}
	A[0] = end;
}

//Main function initializing array A and calling HeapSort.
//We assume the first element denotes the number of elements in the array.
int main(){
	int A[22]=
	{20,4,3,5,1,6,2,20,16,12,17,7,10,8,9,-1,13,15,11,18,19,14};

	printf("Initial Array\n");
	for(int i = 0; i<22;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	printf("\n");
	
	printf("Removing NULL values.\n");
	
	Remove_Nulls(A);

	printf("NULL values Removed.\n");

	PrintList(A);
	printf("\n");

	printf("Starting HeapSort\n");
	printf("\n");
	HeapSort(A);
	printf("Finished HeapSort, sorted Array:\n");

	PrintList(A);

	return 0;

}
