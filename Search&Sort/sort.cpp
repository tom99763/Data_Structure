#include<stdio.h>
#include<iostream>
#include<cstdlib> //隨機亂數套件 
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
	將第i筆data放進前i-1筆已sorted的data,直到全部都跑過一次 
	比較data:
	    先放入i-1筆的最後一個,跟前面的j比較,若i<j,i跟j,swap
	best case: 小到大 O(n)-->n回合,每回合搜尋1次 
	worst case : 大到小 O(n^2)-->n回合,每回合搜尋n次 
	stable sorting : [5',5,8,1]-->[1,5',5,8]
	*/
	for(int i=1;i<n;i++){
		int j=i;
		while(j>=0){
			if(seq[j]<seq[j-1]){
				//不能<=,這樣會變成unstable sorting 
				swap(seq[j],seq[j-1]);//call by address
			}
			j--;
		}
	}
}

void selection_sort(int list[],int n){
	/*
	從尚未選擇的element中挑選最小的跟第i個element做swap  
	best case = worst case: O(n^2), 做n回合,每回合都要掃過n-k筆資料才找到最小 
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
	每次如果list[i]>list[j]則前後swap直到此回合沒有發生swap 
	best case : 小到大 O(n),此回合都沒交換 
	worst case: 大到小 O(n^2) 
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
			return ;//如果此回合都沒有swap代表排好了,直接return 
		}
	}
}

void shell_sort(int list[]){
	/*
	類似bubble sort,但stepsize由span決定
	通常挑span=無條件進位[n/2],n為回合數,且每回合n會被更新為[n/2]
	每回合有span次搜尋路徑 
	Best Case:由span決定
	Worst Case=Average Case : O(n^2) 
	*/
}



//overloading
void quick_sort(int list[],int left,int right){
	/*
	input : left=0,right=n-1
	每回合取第一個element為pivot key後:
	     i從pivot的下一個開始找比pivot大的,j從最後開始找小的,若都找到swap(list[i],list[j])
	     若j<=i,則將pivot key跟list[j]交換 
	Note :每回合結束後,pivot key的左邊要比自己小,右邊要比自己大  
	Best Case : T(n)=2*T(n/2)+c*n-->O(nlogn)
	Worst Case : 大到小or小到大or全部相同 T(n)=T(n-1)+c*n --> O(n^2) 
	unstable sorting : [2,5,5'.....1]--->[2,1,5',.....5]
	*/
	if(left<right){
		int pivot=list[left];
		int i=left,j=right+1;
		do{
			do{
				i++;//往左開始找,找比pivot大的 
			}while(pivot>list[i]&i<right);	
			do{
				j--;//往右開始找,找比pivot小的 
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
	/*
	兩兩合併法
	有分為iterative跟recursive兩種方法 
	Best case=Worst case=Average Case : 每回合最多比n-1次O(n),且分割圖像是一個倒立的Complete B.T.O(logn)-->O(nlogn)
	Stable sorting 
	*/ 
}

void heap_sort(int list){
	/*
	heap : 為一個Complete B.T.
	Max-Heap : parent的值必定大於child
	Min-Heap : parent的值必定小於child 
	Sort使用delete來實現 
	*/
}

int main(){
	int n=100;
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
	cout<<"\nafter bubble sort: \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	gen_arr(arr,n);
	//quick sort
	quick_sort(arr,0,n-1);
	cout<<"\nafter quick sort : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
