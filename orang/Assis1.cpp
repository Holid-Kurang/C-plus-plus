#include <iostream>
using namespace std;

struct mahasiswa{
    //data / attribute
    string nama;
    int nilai;
    string nim;
    int arr[10];
    //fungsi / method
    mahasiswa():nama(""),nilai(0){}
    //contructor
    mahasiswa(string _nama,int _nilai){
        nama=_nama;
        nilai=_nilai;
    }
    void tukarNamaNIM(){
        string temp=nama;
        nama=nim;
        nim =temp;
    }
};
struct matakuliah
{
    /* data */
    string namaMatkul;
    int banyakyangambil=0;
    mahasiswa m[35];
};
mahasiswa _test(mahasiswa input){
    input.nilai=10;
    return input;
}
void view(matakuliah inView){
    while (true)
    {
        system("cls");
        cout<<"===================="<<inView.namaMatkul<<"====================\n";
        //     12345678901234567890
        //==========================nama===================
        for(int i=0;i<inView.banyakyangambil;i++){
        cout<<inView.m[i].nama<<" "<<inView.m[i].nim<<endl;
        }
        //=================================================
        for(int i=0;i<(20+inView.namaMatkul.length()/2);i++){cout<<"=";}
        for(int i=0;i<(20+inView.namaMatkul.length()/2);i++){cout<<"=";}
        if(inView.namaMatkul.length()%2==1)cout<<"=";
        cout<<endl;
        string comm,comm2;
        cout<< "command : ";
        cin >> comm;
        cin >> comm2;
        mahasiswa TempM;
        TempM.nama=comm;
        TempM.nim=comm2;
        TempM = _test(TempM);
        
        inView.m[inView.banyakyangambil]=TempM;
        inView.banyakyangambil++;
        /* code */
        if(comm =="x")break;
    }
}
int main(){
    //int,char,double,float,bool,long,long long dst
    //mahasiswa,string
    string test="test";
    test.length();
    mahasiswa m1;
    m1.nama="rizki";
    m1.nilai=90;

    mahasiswa m2("fahir",80);
    m2.nim="2121";

    m2.tukarNamaNIM();
    
    cout<<m2.nim<<" "<<m2.nama<<endl;

    mahasiswa m[10];
    m[0].nama="asda";
    for(int i=0;i<10;i++){
        //
        m[i].nama="apa";
    }
    m2.tukarNamaNIM();
    matakuliah alpro;
    alpro.namaMatkul="Alpro";
    view(alpro);
    matakuliah matdis;
    matdis.namaMatkul="Diskirt";
    view(matdis);

}
/*
    0

    command : fahir (enter)

    comm="fahir"

    TempM.nama="fahir"

*/