#include<stdio.h>
using namespace std;

//recursive method
int bin(int n,int m){
	if(n<m){
		return 0;
	}else if(n==m or m==0){
		return 1;
	}else{
		return bin(n-1,m)+bin(n-1,m-1);
	}
} 


int main(){
	printf("recursive output : %d",bin(5,2));
}
