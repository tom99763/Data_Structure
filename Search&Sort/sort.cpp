#include<stdio.h>
#include<iostream>
#include<cstdlib> //�H���üƮM�� 
using namespace std;

//generate unsorted sequence
void gen_arr(int arr[],int n){
	srand(0);
	for(int i=0;i<n;i++){
		arr[i]=rand();
	}
}

//call by reference
//overloading
void swap(int &a,int &b){
	//cout<<"call by reference\n";
	int temp;
	temp=a;
	a=b;
	b=temp;
}

//call by address
//overloading
void swap(int *a,int *b){
	//cout<<"call by address\n";
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}



void insertion_sort(int seq[],int n){
	/*
	�N��i��data��i�ei-1���wsorted��data,����������]�L�@�� 
	���data:
	    ����Ji-1�����̫�@��,��e����j���,�Yi<j,i��j,swap
	best case: �p��j O(n)-->n�^�X,�C�^�X�j�M1�� 
	worst case : �j��p O(n^2)-->n�^�X,�C�^�X�j�Mn�� 
	stable sorting : [5',5,8,1]-->[1,5',5,8]
	*/
	for(int i=1;i<n;i++){
		int j=i;
		while(j>=0){
			if(seq[j]<seq[j-1]){
				//����<=,�o�˷|�ܦ�unstable sorting 
				swap(seq[j],seq[j-1]);//call by address
			}
			j--;
		}
	}
}

void selection_sort(int list[],int n){
	/*
	�q�|����ܪ�element���D��̤p�����i��element��swap  
	best case = worst case: O(n^2), ��n�^�X,�C�^�X���n���Ln-k����Ƥ~���̤p 
	unstable sorting : [5,5',1]-->[1,5',5]
	*/
	for(int i=0;i<n;i++){
		int j=i+1;
		int min=list[j];
		int idx=j;
		j++;
		while(j<n){
			if(list[j]<min){
				min=list[j];
				idx=j;
			}
			j++;
		}
		if(list[i]>list[idx]){
			swap(list[i],list[idx]);
		}
	}
}

void bubble_sort(int list[],int n){
	/*
	�C���p�Glist[i]>list[j]�h�e��swap���즹�^�X�S���o��swap 
	best case : �p��j O(n),���^�X���S�洫 
	worst case: �j��p O(n^2) 
	stable sorting
	*/
	while(true){
		bool flag=false;
		for(int i=0;i<n;i++){
			if(list[i]>list[i+1]){
				swap(list[i],list[i+1]);
				flag=true;
			}
		}
		if(flag==false){
			return ;//�p�G���^�X���S��swap�N��Ʀn�F,����return 
		}
	}
}

void shell_sort(int list[]){
}



//overloading
void quick_sort(int list[],int left,int right){
	/*
	input : left=0,right=n-1
	�C�^�X���Ĥ@��element��pivot key��:
	     i�qpivot���U�@�Ӷ}�l���pivot�j��,j�q�̫�}�l��p��,�Y�����swap(list[i],list[j])
	     �Yj<=i,�h�Npivot key��list[j]�洫 
	Note :�C�^�X������,pivot key������n��ۤv�p,�k��n��ۤv�j  
	Best Case : T(n)=2*T(n/2)+c*n-->O(nlogn)
	Worst Case : �j��por�p��j --> O(n^2) 
	unstable sorting : [2,5,5'.....1]--->[2,1,5',.....5]
	*/
	if(left<right){
		int pivot=list[left];
		int i=left,j=right+1;
		do{
			do{
				i++;//�����}�l��,���pivot�j�� 
			}while(pivot>list[i]&i<right);
			do{
				j--;//���k�}�l��,���pivot�p�� 
			}while(pivot<=list[j]&j>left); 
			if(i<j){
				swap(list[i],list[j]);
			}
		}while(i<j);
		swap(list[left],list[j]);
		quick_sort(list,left,j-1);
		quick_sort(list,j+1,right);
	}
}


void merge_sort(int list){
}

void heap_sort(int list){
}

int main(){
	int n=16;
	int arr[n];
	gen_arr(arr,n);//gen data
	cout<<"origin array : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	//insertion sort
	insertion_sort(arr,sizeof(arr)/sizeof(arr[0]));
	cout<<"\nafter insertion sort : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
	gen_arr(arr,n);//gen data
	//selection sort
	selection_sort(arr,n);
	cout<<"\nafter selection sort : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	gen_arr(arr,n);//gen data
	//bubble sort
	bubble_sort(arr,n);
	cout<<"\nafter bubble sort sort : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	gen_arr(arr,n);
	//quick sort
	quick_sort(arr,0,n-1);
	cout<<"\nafter quick sort sort : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
