//Finds two biggest integers in list
#include <iostream>
#include <array>
using namespace std;

void TwoLargest(int[], int);

int main(){
	cout<<"Enter list size: "<<endl;
	int n;
	cin>>n;
	cout<<" Enter "<< n <<" numbers: "<<endl;
	int a[n];
	for(int i=0 ;i<n;i++){
		cin>>a[i];
	}
	TwoLargest(a, n);
	return 0;
}
void TwoLargest(int* A, int n){
	
	int large_1 ,large_2;
	if(A[0]>A[1]){
		large_1=A[0];
		large_2=A[1];
	}
	else {
		large_2=A[0];
		large_1=A[1];
	}

	for (int i = 2;i<n;i++){
		if (A[i] > large_1){
			large_2 = large_1;
			large_1 = A[i];
		}
		else if (large_2 < A[i])
			large_2 = A[i];
	}
	cout<<"Largest is "<<large_1 << endl<<"second largest is "<<large_2<<endl;
}