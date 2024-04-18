#include <iostream>
using namespace std;

int main(){
//	string teks;
//	char a;
//	cout<<"Masukkan Teks: ";
//	getline(cin, teks);
//	cout<<endl<<"kalimat asli   : ";
//	for(int i=0; i<teks.size(); i++){
//		cout<<teks[i]<<", ";
//		if(teks[i]>96){
//			teks[i]-=32;
//		}
//	}cout<<endl;
//	cout<<"kalimat sorting: ";
//	for(int i=0; i<teks.size(); i++){
//		for(int j=0; j<teks.size()-1; j++){
//			for(int k=teks.size()-1; k>0; k--){
//				if(teks[k]<teks[k-1]){
//					a=teks[k];
//					teks[k]=teks[k-1];
//					teks[k-1]=a;
//				}
//			}
//		}
//		if(teks[i]!=' '){
//			cout<<teks[i]<<", ";
//		}
//	}

//	string text, key;
//	int j=0;
//	cout<<"Plaintext : "; getline(cin,text);
//	cout<<"Key       : "; getline(cin,key);
//	cout<<"Chipertext: ";
//	for(int i=0; i<text.size(); i++){
//		if(text[i]>96) text[i]-=32;
//		if(key[j]>96) key[j]-=32;
//		if(text[i]==' '){
//			continue;
//		}else if(text[i]!=65 || key[j]!=65){
//			text[i]=((text[i]+key[j])%26)+65;
//		}j++;
//		if(j==key.size()){
//			j=0;
//		}
//	}cout<<text;

	string kalimat,grup;
	int level=0,kurung=0;
	cout<<"kalimat      : ";	
	getline(cin,kalimat);
  	cout<<"Real kalimat : ";
	for(int i = 0; i < kalimat.size(); i++){
		if(kalimat[i]=='('){
			level++;
		}if(kalimat[i]!='(' &&kalimat[i]!=')'){
			cout<<kalimat[i];
		}
  	}cout<<endl;
	for(int i=0; i<=level; i++){
    	for(int j=0; j<kalimat.size(); j++){
      		if(kalimat[j]=='('){
				kurung++;
				continue;
			}else if(kalimat[j]==')'){
				kurung--;
				continue;
			}
			if(kurung==i){
				grup+=kalimat[j];
			}
    	}
    	if(grup==""){
    		continue;
		}else{
    		cout<<"level "<<i<<" : ";
			cout<<grup<<endl;	
		}
		grup="";
  	}

//  	raihan makan (nasi (campurcan)(makan(nasi) tai)(mputasdasd) goreng) eskrim
//  	abcd(bbcde(cdef)defg)efgh
//	abcd(bbcde (  c  d  e  f  )  d  e  f  g  )  e  f  g  h
//	0123456789 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
//	abcd (bbcde (cdefkalimat) defg) efgh
//	raihan makan (nasi (campurcan)(mputasdasd) goreng) eskrim
  	
//	string kalimat;
//	cout<<"kalimat      : ";
//	getline(cin, kalimat); 
//	int buka=0, tutup=0, bnext=0, tnext=0, level=0;
//	int tmax=kalimat.size(), bmin=-1;
//	cout<<"Real kalimat : ";
//	for(int i=0; i<kalimat.size(); i++){
//		if(kalimat[i]=='('){
//			level++;
//		}if(kalimat[i]!='(' &&kalimat[i]!=')'){
//			cout<<kalimat[i];
//		}
//	}cout<<endl<<"=============================="<<endl;
//	for(int l=0; l<level;l++){
//		for(int i=0+bnext; i<kalimat.size(); i++){
//			if(kalimat[i]=='('){
//				buka=i;
//				bnext=buka+1;
//				break;
//			}
//		}for(int j=(kalimat.size()-1)-tnext; j>=0; j--){
//			if(kalimat[j]==')'){
//				tutup=j;
//				tnext=kalimat.size()-tutup;
//				break;
//			}
//		}
//		cout<<"Level "<<l<<" : ";
//		for(int k=0; k<kalimat.size(); k++){
//			if(kalimat[k]=='(' || kalimat[k]==')'){
//				continue;
//			}
//			if(k>bmin&&k<buka || k>tutup&&k<tmax ){
//				cout<<kalimat[k];
//			}
//		}cout<<endl;
//		bmin=buka; tmax=tutup;
//	}cout<<"Level "<<level<<" : ";
//	for(int i=0; i<kalimat.size(); i++){
//		if(i>bmin && i<tmax){
//			cout<<kalimat[i];
//		}
//	}

}
