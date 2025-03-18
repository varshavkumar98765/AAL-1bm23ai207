#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	time_t start,end;
	
	int n=5;
	int a[n];
	int j,i;
	for(i=0;i<n;i++){
		a[i]=rand() %10;
		printf("%d\t",a[i]);
	}
	
	start=time(NULL);
	int min,t;
	
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		t=a[min];
		a[min]=a[i];
		a[i]=t;
	}
	
	end=time(NULL);
	
	printf("\n\Selection Sort\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n\nTime taken for selection sort : %d",(end-start));
	return 0;
}
