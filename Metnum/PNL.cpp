#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double F(double x) {
	return (x*x*x) - (x*x) + (2*x) - (x+2)*(exp(-2*x));
//	return (x*x*x) + (x-2)*(x-2) - 3;
}
double dF(double x) {
	return (3*x*x) - (2*x) + 2 + 2*(x+2)*exp(-2*x) - exp(-2*x);
}
int main() {
//	Biseksi
//	double errorToler = 0.0001;
//	double iterasiN = 15;
//	double a = -2.5, b = 1.0, x;
//	int i = 1;
//	if(F(a)*F(b)>0) {
//		cout<<"tidak ada akar di antara range a dan b";
//		return 0;
//	}
//	do {
//		x=(a+b)/2;
//		cout<<"iterasi : "<< i++ <<endl;
//		cout<<"hasil x : "<< x <<endl;
//		cout<<"hasil F(x) : "<< F(x) <<endl<<endl;
//		if(F(x)*F(a)<0) {
//			b=x;
//		} else {
//			a=x;
//		}
//	} while(abs(F(x)) >= errorToler && i!=iterasiN);
//	cout<<"tipot berada pada x = "<<x;

//	Regula Falsi
//	double errorToler = 0.0001;
//	double iterasiN = 15;
//	double a = -2.0, b = 0.0, x;
//	int i = 1;
//	if(F(a)*F(b)>0) {
//		cout<<"tidak ada akar di antara range a dan b";
//		return 0;
//	}
//	do {
//		x = (F(b)*a-F(a)*b)/(F(b)-F(a));
//		cout<<"iterasi : "<< i++ <<endl;
//		cout<<"hasil x : "<< x <<endl;
//		cout<<"hasil F(x) : "<< F(x) <<endl<<endl;
//		if(F(x)*F(a)<0) {
//			b=x;
//		} else {
//			a=x;
//		}
//	} while(abs(F(x)) >= errorToler && i<=iterasiN);
//	cout<<"tipot berada pada x = "<<x;

//	Newton-Rhapson
//	double errToler = 0.0001;
//	double iterasiN = 15.0;
//	double x0=-5, x1;
//	int i=1;
//	do {
//		x1 = x0 - (F(x0)/dF(x0));
//		cout<<"iterasi : "<< i++ <<endl;
//		cout<<"hasil x_i+1 (setelah) : "<<x1<<endl;
//		cout<<"error : "<< abs(F(x1)) << endl<<endl;
//		x0=x1;
//	} while(abs(F(x1)) >= errToler&& i<=iterasiN);
//	cout<<"tipot berada pada x = "<<x0;

//	Secant
	double errToler=0.0001;
	double iterasiN;
	double x, x0, x1;
	double error;
	cout<<"masukkan x0               : "; cin>>x0;
	cout<<"masukkan x1               : "; cin>>x1;
	cout<<"masukkan batas error      : "; cin>>errToler;
	cout<<"masukkan iterasi maksimal : "; cin>>iterasiN;
	cout<<endl;
	int i=1;
	do {
		x = x1 - F(x1)*((x1-x0)/(F(x1)-F(x0)));
		error = abs(F(x));
		cout<<"iterasi : "<< i++ <<endl;
		cout<<"hasil x_i+1 (setelah) : "<<fixed<<setprecision(10)<<x<<endl;
		cout<<"error : "<<fixed<<setprecision(10)<< error << endl<<endl;
		x0=x1;
		x1=x;
	} while(error>=errToler);
	cout<<"tipot berada pada x = "<<fixed<<setprecision(8)<<x;
}