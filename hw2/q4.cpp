//Modular Exponentiation problem 
#include <iostream>
#include <vector>

using namespace std;


vector<int> BinaryK(int);

int ModularExpo(int,vector<int>,int );

int main(){

	cout<<"Enter three values for a^k mod n: "<<endl;
	int a,k,n;
	cin>>a>>k>>n;
	cout<<"  "<<a <<"^"<<k<< " mod "<<n<< " = "<<endl<<ModularExpo(a,BinaryK(k),n)<<endl;

	return 0;
}
vector<int> BinaryK(int k){
	vector<int> K;
	int tmp=k, i=0;
	while(tmp>0){
		K.push_back(tmp%2);
		tmp=(tmp-K.at(i))/2;
		i++;
	}
	
	return K;
}

int ModularExpo(int a,vector<int> K,int n){
	if(a<n){
		cout<<"'a' cannot be smaller than 'n'. Returning -1"<<endl;
		return -1;
	}

	if(n==1){
		return 0;
	}
	int b=1;
	if(K.size()==0){
		return b;
	}
	if(K.at(0)==1)
		b=a;
	for(int i:K){
		a=(a*a)%n;
		if(i==1)
			b=(a*b)%n;
	}
	return b;
}