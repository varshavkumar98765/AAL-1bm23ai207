#include<stdio.h>
int len(char a[]){
	int k=0;
	while(a[k]!='\0')
		k++;
	return k;
}
int main(){
	char str[]="Nobody notices hm";
	char pat[]="him";
	int s=len(str);
	int p=len(pat);
	
	bool flag=false;
	
	int i,j;
	for(i=0;i<s-p+1;i++){
		flag=false;
		for(j=0;j<p;j++){
			if(str[i+j]!=pat[j])
			break;
			flag=true;
		}
		if(flag){
			break;
		}
		
	}
	
	printf(flag?"Pattern present at position %d":"Absent",i);
	
	return 0;
}
