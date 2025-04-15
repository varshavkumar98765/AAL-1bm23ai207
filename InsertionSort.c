#include<stdio.h>

int main(){
	int us[]={2,1,4,3,6,5,7,29,3,45};
	int n=sizeof(us)/sizeof(us[0]),i,j,t;
	int s[n];
	s[0]=us[0];
	
	for(i=1;i<n;i++){
		s[i]=us[i];
		for(j=i;j>0;j--){
			if(s[j]<s[j-1]){
				t=s[j];
				s[j]=s[j-1];
				s[j-1]=t;
			}
			else break;
		}
	}
	for(i=0;i<n;i++)printf("%d\t",us[i]);
	printf("\n\nSorted array\n");
	for(i=0;i<n;i++)printf("%d\t",s[i]);
	return 0;
}
