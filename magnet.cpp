#include <iostream>
using namespace std;

int main(){
	int arr[10000], n, k;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		if(arr[i] != arr[i-1]){
			k++;
		}
	}
	cout<<k;
}
