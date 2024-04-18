#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main() {
	int pilih=1;
   	char a, huruf;
 	int n,batas,banyak,increment=1,sum;
    int n2,cek, prima_n;
    int t1,t2,next;
	do{
 	bool ulangpola=true;
	while(true){
		if(pilih==1){
			system("cls");
			cout<<"|=============================|"<<endl;
			cout<<"| ===>>[ POLA PERTAMA ]<<==== |"<<endl;
			cout<<"|      [ POLA KEDUA   ]       |"<<endl;
			cout<<"|      [ POLA KETIGA  ]       |"<<endl;
			cout<<"|      [     EXIT     ]       |"<<endl;
			cout<<"|=============================|"<<endl;
		}else if(pilih==2){
			system("cls");
			cout<<"|=============================|"<<endl;
			cout<<"|      [ POLA PERTAMA ]       |"<<endl;
			cout<<"| ===>>[ POLA KEDUA   ]<<==== |"<<endl;
			cout<<"|      [ POLA KETIGA  ]       |"<<endl;
			cout<<"|      [     EXIT     ]       |"<<endl;
			cout<<"|=============================|"<<endl;
 		}else if(pilih==3){
			system("cls");
			cout<<"|=============================|"<<endl;
			cout<<"|      [ POLA PERTAMA ]       |"<<endl;
			cout<<"|      [ POLA KEDUA   ]       |"<<endl;
			cout<<"| ===>>[ POLA KETIGA  ]<<==== |"<<endl;
			cout<<"|      [     EXIT     ]       |"<<endl;
			cout<<"|=============================|"<<endl;
		}else if(pilih==4){
			system("cls");
			cout<<"|=============================|"<<endl;
			cout<<"|      [ POLA PERTAMA ]       |"<<endl;
			cout<<"|      [ POLA KEDUA   ]       |"<<endl;
			cout<<"|      [ POLA KETIGA  ]       |"<<endl;
			cout<<"| ===>>[     EXIT     ]<<==== |"<<endl;
			cout<<"|=============================|"<<endl;
		}
		a=getch();
		if(a==72){
			pilih--;
			if(pilih<1){
				pilih=4;
			}
		}else if(a==80){
			pilih++;
			if(pilih>4){
				pilih=1;
			}
		}else if(a==13){
			break;
		}
	}
	switch(pilih){
	   	case 1:
			while(ulangpola){
				system("cls");
    			cout<<"|=============================|"<<endl;
				cout<<"| ===>>[ POLA PERTAMA ]<<==== |"<<endl;
				cout<<"|      [ POLA KEDUA   ]       |"<<endl;
				cout<<"|      [ POLA KETIGA  ]       |"<<endl;
				cout<<"|=============================|"<<endl;
				cout<<"  ===>>[ POLA PERTAMA ]<<====  "<<endl;
				n,batas,banyak,increment=1;
				cout<<"Masukkan Batas Bawah : ";
 				cin>>batas;
    			cout<<"Masukkan Banyak Nilai : ";
	    		cin>>banyak;
		   		n=batas;

				cout<<endl<<"a. Pola Pertama : ";
				sum=0;
				for(int i=0;i<banyak;i++){
			  		if(i%2==0){
            	    	if(i==0){
                	    	cout<<n<<" ";
                		   	sum+=n;
	                	}else{
    		            	n=n+22;
            		    	sum+=n;
							cout<<n<<" ";
						}
            		}else{
            	    	cout<<n+increment<<" ";
            	    	sum=sum+n+increment;
            	  		n=n+increment;
            	  		increment++;
            		}
    			}
    			cout<<endl<<"Jumlah : "<<sum<<endl;

				n2=batas;
				prima_n=banyak;
    			cout<<endl<<"b. Pola Kedua   : ";
				sum=0;
//				cari bilangan prima sebanyak prima_n, dengan bil dimulai dari n2
				for(int i=n2; prima_n>0; i++){
					cek=0;
//					cek apakah i prima
					for(int j=2; j<i; j++){
						if(i%j==0){
							cek=1;
							break;
						}
					}
//					jika i prima, kurangin prima_n
					if(cek==0 && i>1){
						cout<<i<<" ";
						sum+=i;
						prima_n--;
					}
			   	}
	  			cout<<endl<<"Jumlah : "<<sum<<endl<<endl;

	  			cout<<"c. Pola Ketiga  : ";
				sum=0; t1=0; t2=1;
				for(int i=0;i<banyak;){
					if(t1>=batas){
					   cout<<t1<<" ";
					   sum+=t1;
					   i++;
					}
					next = t1 + t2;
					t1 = t2;
					t2 = next;
				}
    			cout<<endl<<"Jumlah : "<<sum<<endl;

				cout<<"\nINGIN COBA LAGI [N/Y] : ";
				cin>>a;
				if(a=='Y'||a=='y'){
					ulangpola=true;
					system("cls");
				}else if(a=='N'||a=='n'){
					ulangpola=false;
					system("cls");
				}
			}
			break;
	   	case 2:
			while(ulangpola){
				system("cls");
				cout<<"|=============================|"<<endl;
				cout<<"|      [ POLA PERTAMA ]       |"<<endl;
				cout<<"| ===>>[ POLA KEDUA   ]<<==== |"<<endl;
				cout<<"|      [ POLA KETIGA  ]       |"<<endl;
				cout<<"|=============================|"<<endl;
				cout<<"  ===>>[ POLA KEDUA   ]<<====  "<<endl;
				int panjang;
				cout<<"Masukkan jumlah baris : ";
				cin>>panjang;
				huruf='@';
				for(int i = (panjang+1)/2; i>=1; i--){
					for(int j = 1; j<=(panjang+1)/2; j++){
						if(j<i){
							cout<<" ";
						}else{
							if(huruf=='Z'){
								huruf='@';
							}
							huruf++;
							cout<<huruf<<" ";
						}
					}
					cout<<endl;
				}
				for(int i = 1; i<=(panjang+1)/2; i++){
					for(int j = 1; j<=(panjang+1)/2; j++){
						if(j>i){
							if(huruf=='Z'){
								huruf='@';
							}
							huruf++;
							cout<<huruf<<" ";
						}else{
							cout<<" ";
						}
					}
					cout<<endl;
				}
				cout<<"INGIN COBA LAGI [N/Y] : "; cin>>a;
				if(a=='Y'||a=='y'){
					ulangpola=true;
					system("cls");
				}else if(a=='N'||a=='n'){
					ulangpola=false;
					system("cls");
				}
			}
			break;
		case 3:
			while(ulangpola){
				system("cls");
				cout<<"|=============================|"<<endl;
				cout<<"|      [ POLA PERTAMA ]       |"<<endl;
				cout<<"|      [ POLA KEDUA   ]       |"<<endl;
				cout<<"| ===>>[ POLA KETIGA  ]<<==== |"<<endl;
				cout<<"|=============================|"<<endl;
				cout<<"  ===>>[ POLA KETIGA  ]<<====  "<<endl;
				int i,k;
				cout<<"Masukkan Panjang Pola : ";
				cin>>i;
				cout<<endl;
				for(int y=i; y>=1; y--){
					for(int x=1; x<=i; x++){
						k=x-y+1;
						cout<<setw(3);
						if(k<=0){
							k=k*-1;
							k+=2;
							if(k==2){
								k=0;
							}else if(x+y==i+1){
								k=1;
							}
						}else if(k==2){
							k=0;
						}else if(x+y==i+1){
							k=1;
						}
						cout<<k;
					}
					cout<<endl;
				}
				cout<<"\nINGIN COBA LAGI [N/Y] : ";
				cin>>a;
				if(a=='Y'||a=='y'){
					ulangpola=true;
					system("cls");
				}else if(a=='N'||a=='n'){
					ulangpola=false;
					system("cls");
				}
			}
			break;
		case 4:
			return 0;
			break;
		}
	}while(true);
}