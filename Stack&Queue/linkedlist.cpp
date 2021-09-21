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
			this->data=data; //��self.data assign��input data 
		}
};


class linkedlist{
	public :
		Node *first;//���V�Ĥ@��Node 
		void add_back(int data){
			//�b�̧��ݥ[�Jnode
			//Sequential Access 
			Node *x=new Node(data);//�ŧi�@��object pointer,assign data���L��att data,�ðt�mMemory space 
			if(first==0){
				//�p�Glist�O�Ū�,�o��node�N�O�Ĥ@��node 
				first=x;
				x->link=0;//�Nx���U�@�ӫ��VNULL 
				return;
			}
			Node *current=first; //�̪�visit��node,current���Vfirst���V��node 
			while(current->link!=0){ 
				current=current->link;
			}
			current->link=x;//�b���ݥ[�Jnode x 
			x->link=0;//�Nx���U�@�ӫ��VNULL 
		}
		
		void add_front(int data){
			//�b�̫e�ݥ[�Jnode
			Node *x=new Node(data);//allocate memory space 
			x->link=first;
			first=x;
		}
		
		bool insert(int idx,int data){
			//�bidx�e�����J�@��node 
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
			//��idx��node�R��
			int current_idx=0;
			Node *current=first;
			if(idx==0){
				first=current->link;
				delete current;
			}
			Node *target;//�ŧiobject pointer,�٥����V�F�� 
			while(current_idx!=idx-1){
				if(current==0){
					printf("out of idx");
					return false;
				}
				//�j�M�ؼ�idx���e�@�� 
				current=current->link;
			} 
			target=current->link;//�����R����node 
			current->link=target->link;//��W�@��node��link���Vtarget���U�@��node
			delete target; //��target�qMemory�R�� 
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
			target=current->link;//�����R����node 
			current->link=x;//�N�e�@��node���V�s��x 
			x->link=target->link;//�N�s��x���Vtarget���U�@�� 
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
	
	ll.add_front(2);//�b�̫e���[�J2
	ll.printall();//212345
	printf("\n"); 
	
	ll.insert(2,9);	//�bidx=2���e�����J9
	ll.printall();//2129345
	
	printf("\n");
	ll.insert(100,8);//out of idx
	
	printf("\n");
	ll.delete_node(1);//�Nidx=1��node�R��
	ll.printall(); //229345
	
	printf("\n");
	ll.delete_node(100);//out of idx
	
	ll.replace(0,1);
	printf("\n");
	ll.printall();//129345
	
	printf("\n");
	ll.replace(100,1);//out of idx
}



