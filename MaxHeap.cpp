// Insertion and Deletion in max-heap
#include <iostream>
using namespace std;
void insertHeap(int arr[], int n, int value){
	n+=1;
	arr[n-1] = value;
	int i = n-1;
	while(i>=1){
		int parent = i/2;
		if(arr[i]>arr[parent]){
			int temp = arr[i];
			arr[i] = arr[parent];
			arr[parent] = temp;
			i = parent;
		}
	}
	cout<<"Heap after insertion of "<<value<<" is: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}
void del(int arr[], int n){
	arr[0] = arr[n-1];
	n--;
	int i=0;
	while(i<n){
		int l = i*2;
		int r = 2*(i+1);
		if(arr[i]<arr[l] && arr[l]>arr[r]){
			int temp = arr[i];
			arr[i] = arr[l];
			arr[l] = temp;
		} 
		if(arr[i]<arr[r] && arr[l]<arr[r]){
			int temp = arr[i];
			arr[i] = arr[r];
			arr[r] = temp;
		}
	}
	cout<<"Final heap is: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n;
	cout<<"Enter the number of elements in the heap: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the heap: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int value;
	cout<<"1. Insertion in the max-heap."<<endl;
	cout<<"2. Deletion from max-heap."<<endl;
	cout<<"3. EXIT"<<endl;
	cout<<"Enter your choice: ";
	int choice;
	cin>>choice;
	char a;
	switch(choice){
		case 1:
			cout<<"Enter the value to be inserted in the heap: ";
			cin>>value;
			insertHeap(arr,n,value);
			break;
		case 2:
			cout<<"Press d if you want to delete from heap.";
			cin>>a;
			if(a=='d'){
				del(arr,n);
			}else{
				return 0;
			}
			break;
		case 3:
			cout<<"EXIT"<<endl;
			exit(0);
	}
}
