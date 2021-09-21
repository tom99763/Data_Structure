#include<stdio.h>
#include<iostream>
using namespace std;


class Node{
	public:
		int data;
		Node *link;//object pointer
		Node(int data){
			//constructor
			//assign data
			this->data=data; //把self.data assign給input data 
		}
};


class linkedlist{
	public :
		Node *first;//指向第一個Node 
		void add_back(int data){
			//在最尾端加入node
			//Sequential Access 
			Node *x=new Node(data);//宣告一個object pointer,assign data給他的att data,並配置Memory space 
			if(first==0){
				//如果list是空的,這個node就是第一個node 
				first=x;
				x->link=0;//將x的下一個指向NULL 
				return;
			}
			Node *current=first; //最近visit的node,current指向first指向的node 
			while(current->link!=0){ 
				current=current->link;
			}
			current->link=x;//在尾端加入node x 
			x->link=0;//將x的下一個指向NULL 
		}
		
		void add_front(int data){
			//在最前端加入node
			Node *x=new Node(data);//allocate memory space 
			x->link=first;//x的指向first指向的node
			first=x;//first重新指向
		}
		
		bool insert(int idx,int data){
			//在idx前面插入一個node 
			Node *x=new Node(data);
			int current_idx=0;
			Node *current=first;
			while(current_idx!=idx){
				if(current==0){
					printf("out of idx");
					return false;
				}
				current_idx+=1;
				current=current->link;
			}
			x->link=current->link;
			current->link=x;
		}
		
		bool delete_node(int idx){
			//把idx的node刪除
			int current_idx=0;
			Node *current=first;
			if(idx==0){
				first=current->link;
				delete current;
			}
			Node *target;//宣告object pointer,還未指向東西 
			while(current_idx!=idx-1){
				if(current==0){
					printf("out of idx");
					return false;
				}
				//搜尋目標idx的前一個 
				current=current->link;
			} 
			target=current->link;//找到欲刪除的node 
			current->link=target->link;//把上一個node的link指向target的下一個node
			delete target; //把target從Memory刪除 
			return true;
		}
		
		bool replace(int idx,int data){
			Node *x=new Node(data);
			Node *current=first;
			if(idx==0){
				x->link=current->link;
				first=x;
				delete current;
				return true;
			}
			Node *target;
			int current_idx=0;
			while(current_idx!=idx-1){
				if(current==0){
					printf("out of idx");
					return false;
				}
				current=current->link;
			}
			target=current->link;//找到欲刪除的node 
			current->link=x;//將前一個node指向新的x 
			x->link=target->link;//將新的x指向target的下一個 
			delete target;
			return true;
		}
		
		
		void printall(){
			Node *current=first;
			while(current!=0){
				cout<<current->data;
				current=current->link;
			}
		}
};



int main(){
	linkedlist ll;
	for(int i=1;i<=5;i++){
		ll.add_back(i);
 }
	ll.printall();//12345
	printf("\n");
	
	ll.add_front(2);//在最前面加入2
	ll.printall();//212345
	printf("\n"); 
	
	ll.insert(2,9);	//在idx=2的前面插入9
	ll.printall();//2129345
	
	printf("\n");
	ll.insert(100,8);//out of idx
	
	printf("\n");
	ll.delete_node(1);//將idx=1的node刪除
	ll.printall(); //229345
	
	printf("\n");
	ll.delete_node(100);//out of idx
	
	ll.replace(0,1);
	printf("\n");
	ll.printall();//129345
	
	printf("\n");
	ll.replace(100,1);//out of idx
}



