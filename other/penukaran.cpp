#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int mx, m1=10, m2 =4 , m3=6 , m4=9 , m5=7;
	mx=m1;
	m1=m5;
	m5=mx;
	
	mx=m2;
	m2=m4;
	m4=mx;
	
	mx=m3;
	m3=m1;
	m1=mx;
	
	cout<<m1<<" "<<m2<<" "<<m3<<" "<<m4<<" "<<m5;
}

