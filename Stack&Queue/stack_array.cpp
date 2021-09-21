#include<stdio.h>
#include<iostream>
using namespace std;



class Stack{
	public:
		int top;
		int n;//stack size
		int* stack;
		
		void creat(int size){
			//因沒有其他同名var蓋掉,不用加(*this) 
			n=size;
			top=-1;
			stack=new int[n]; //allocate memory space to array
		}
		
		bool isEmpty(){
			return top==-1;
		}
		
		bool isFull(){
			return top==n-1;
		}
		
		bool push(int item){
			if(isFull()){
				return false;
			}
			else{
				top+=1;
				stack[top]=item;
				return true;
			}
		}
		bool pop(){//call-by reference
			if(isEmpty()){
				return false;
			}
			else{
				stack[top]=NULL;
				top-=1;
				return true; 
			}
		}
};


int main(){
	int stack_size=5;
	Stack s;
	s.creat(stack_size);
	
	//[1,2,3,4,5]
	for(int i=1;i<=stack_size;i++){
		s.push(i);
	}
	printf("top : %d \n",s.top);
	for(int j=0;j<stack_size;j++){
		cout<<s.stack[j]<<"\n";
	}
	s.pop();
	printf("top : %d \n",s.top);
	for(int k=0;k<stack_size;k++){
		cout<<s.stack[k]<<"\n";
	}
}
