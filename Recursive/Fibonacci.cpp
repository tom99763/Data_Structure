 #include<stdio.h>
 using namespace std;
 
 
 //note : idx ±q0¶}©l 
 //recursive method
 int F(int n){
 	if(n==0 || n==1){
 		return n;
	 }else{
	 	return F(n-1)+F(n-2);
	 }
 }
 
 //iterative method
 int F(int n,char mode){//overloading F
 	int f1=0,f2=1,temp;
 	for(int i=1;i<n;i++){
 		temp=f1+f2;
 		f1=f2;
 		f2=temp;
	 }
	 return temp;
 }
 
 
 int main(){
 	printf("recursive output : %d\n",F(6));
 	printf("iterative output: %d",F(6,'i'));
 }
