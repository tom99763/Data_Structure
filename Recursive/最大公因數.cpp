#include<stdio.h>
using namespace std;


int gcd(int a,int b){
	if(a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}

int gcd(int a,int b,char mode){//overloading gcd
	int temp;
	while(true){
		if(a%b==0){
			return b;
		}
		temp=b;
		b=a%b;
		a=temp;
	}
}


int main(){
	printf("recursive output : %d\n",gcd(16,56));
	printf("iterative output : %d",gcd(16,56,'i'));
}
