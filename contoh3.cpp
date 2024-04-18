#include <iostream>
#include <cmath>
using namespace std;

double Fx(double x){
    return (x*x*x) - (x*x) + (2*x) - (x+2)*(exp(-2*x));
}

int main(){
	double errTol = 0.0001;
	double iterasiN = 15.0;
	double x, x0=0.0, x1=2.0;
	double error;
	int i=1;
	do{
		x = x1 - Fx(x1)*((x1-x0)/(Fx(x1)-Fx(x0)));
		error = abs(Fx(x));
		cout<<"iterasi : "<< i++ <<endl;
		cout<<"hasil x i+1 (setelah) : "<<x<<endl;
		cout<<"error : "<< error << endl<<endl;
		x0=x1;	
		x1=x;
	}while(error>=errTol&& i!=iterasiN);
	cout<<"tipot berada pada x = "<<x;
//	0 1 2 3 4 5
//	1 0 1 2 3 4
//	2 1 0 1 2 3
//	3 2 1 0 1 2
//	4 3 2 1 0 1
//	5 4 3 2 1 0
//	int n, angka;
//	cin>>angka;
// 	for(int i=1; i<angka; i++){
//		for(int j=1; j<angka; j++){
//			n=i-j;
//			if(n<0){
//				n*=-1;
//			}
//			cout<<n<<" ";
//		}
//		cout<<endl;
//	}


//	int n, angka;
//	cin>>angka;
// 	for(int i=1; i<=angka; i++){
//		for(int j=1; j<=angka; j++){
//			n++;
//			cout<<n<<" ";
//		}
//		n=n-(angka-1);
//		cout<<endl;
//	}

//	n=angka;
//	for(int i=1; i<=angka; i++){
//		for(int j=1; j<=angka; j++){
//			cout<<n<<" ";
//			n--;
//		}
//		n=n+(angka-1);
//		cout<<endl;
//	}

}
