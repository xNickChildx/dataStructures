//Extended Euclidean Algorithm GCD(a,b)=S*a +T*b

#include <iostream>

using namespace std;

void EEA(int,int, int &,int &);

int main(){
	cout<<"Enter two numbers: "<<endl;
	int a, b;
	cin>>a>>b;
	int s=0,t=0;
	EEA(a,b, s,t);
	cout<<"S= "<< s<< "T= "<< t<<endl; 
	return 0;
}

void EEA(int a, int b, int& finalS, int& finalT){
	int s=0, old_s=1, t=1, old_t=0, r=b, old_r=a;

	while(r!=0){
		int q=old_r/r;
		int temp=old_r;
		old_r=r;
		r=temp-q*r;
		temp=old_s;
		old_s=s;
		s=temp-q*s;
		temp=old_t;
		old_t=t;
		t=temp-q*t;
	}
	cout<<"GCD = "<< old_r<<endl;

	finalS=old_s;
	finalT=old_t;

}