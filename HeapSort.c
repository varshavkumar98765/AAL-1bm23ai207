#include<stdio.h>

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void heapify(int arr[],int n,int i){
	int largest=i;
	int lc=2*i+1;
	int rc=2*i+2;
	if(lc<n && arr[largest]<arr[lc])
		largest=lc;
	if(rc<n && arr[largest]<arr[rc])
		largest=rc;
	if(largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}

void HeapSort(int arr[],int n){
	int i;
	for(i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(i=n-1;i>0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

int main() {
    int arr[] = {9, 4, 3, 8, 10, 2, 5,64,1,9,0,0}; 
    int n = sizeof(arr) / sizeof(arr[0]);
	int i;
    HeapSort(arr, n);

    printf("Sorted array is \n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
