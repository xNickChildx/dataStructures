
/**This question is the implementation of selection sort**/
#include <iostream>

using namespace std;
void selectionSort(int [], int);
int main(){
	int p;
	cout<<"Enter Size of Array"<<endl;
	cin>>p;
	int arr[p];
	cout<<"Enter " << p <<" Values"<<endl;
	for(int i=0; i<p;i++){
		cin>>arr[i];
	}
	
	selectionSort(arr,p);
	return 0;
}

void selectionSort(int a[], int n){
	cout<<"Array is: ";
	for(int i=0;i<n;i++ ){
		cout<<a[i]<< ", ";
	}
	cout<<endl;

	for(int i=0; i<n-1;i++){
		int maxIndex=i;
		for(int j=i+1; j<n;j++){
			if(a[j]>a[maxIndex])
				maxIndex=j;
		}
		int tmp=a[i];
		a[i]=a[maxIndex];
		a[maxIndex]=tmp;
		}
	
	cout<<"Sorted Array is: ";
	for(int i=0;i<n;i++ ){
		cout<<a[i]<< ", ";
	}
	cout<<endl;

}