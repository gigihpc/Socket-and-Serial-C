#include<iostream.h>

#include<conio.h>

#include<string.h>

/*void main()

{

char kata[]="DUA kali";


strrev(kata);

cout<<"Setelah Diubah Menjadi: "<<kata<<endl;

}*/

void main(){
	char kata[100],tmp[100];
	int a,b;

	cout<<"Masukkan kata/kalimat:";
	cin>>kata;

	b=strlen(kata);

	for(a=b;a>=1;a--){
		tmp[a]=kata[a-1];
	cout<<"Hasil kalimat yang telah dibalik:"<<tmp[a]<<a<<endl;
	}
/*	for(int i=b;i<b;i--)
		hasil=tmp[i];
	cout<<"Hasil kalimat yang telah dibalik:"<<hasil<<endl;
}*/


/*class calculator
{
private:
float angka_1,angka_2,hasil;
char operasi,eksekusi;
public:
void masukan ();
void proses ();
void keluaran ();
};

void calculator::masukan ()
{
cout<<"Masukkan Angka pertama = "; cin>>angka_1;
cout<<"Jenis Operasi perhitungan * / + - = "; cin>>operasi;
cout<<"Masukkan Angka kedua = "; cin>>angka_2;
}

void calculator::proses ()
{
if(operasi=='*')
{
hasil=angka_1*angka_2;
}
else if(operasi=='/')
{
hasil=angka_1/angka_2;
}
else if(operasi=='+')
{
hasil=angka_1+angka_2;
}
else if(operasi=='-')
{
hasil=angka_1-angka_2;
}
}

void calculator::keluaran()
{
cout<<"Tekan tombol (=) "; 
do { cin>>eksekusi;
if(eksekusi=='=')
{
	cout<<"Hasil perhitungan = "<<hasil<<endl;}
else{
	cout<<"Anda tidak menekan tombol sama dengan (=) "; } 
}while(eksekusi!='='); } 
void main() { 
	class calculator jadi; char pil; 
do {  jadi.masukan(); jadi.proses(); jadi.keluaran(); cout<<"Apakah anda ingin mengulang? (y or n) "; cin>>pil;
}while(pil=='y'||pil=='Y');
}
*/
