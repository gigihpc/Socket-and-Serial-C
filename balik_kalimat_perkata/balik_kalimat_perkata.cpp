#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

//using namespace std;
/*void str_reverse(char *strStart, char* strEnd)
{
	char* str1 = strStart;
	char* str2 = strEnd;
	while( str1 < str2 )
	{
		char temp = *str1;
		*str1 = *str2;
		*str2 = temp;
		str1++;
		str2--;
	}
}
void reverse_words(char *str)
{
	// Point two pointers to the required string.
	char* str1 = str;
	char* str2 = str;
	// Reverse the whole string.
	str_reverse(str1, str2 + strlen(str2) -1 );
	// Start reversing now each word in the string.
	while( *str2 != '\0' ) // Parse the string till the end
	{
		if( *str2 == ' ' ) // If space found
		{
			*str2--; 
			str_reverse(str1, str2); // reverse word..
			*str2++;	
			while( *str1 != ' ' )
			{
				*str1++;
			}
			*str1++;
		}
		*str2++;
	}
	// Reverse last word in the string
	if( *str2 == '\0' )
	{
		*str2--;
		str_reverse(str1, str2);
	}
	// Done !
}
void main()
{
	char str1[]="gigih prasetyo cahyono";
	//cout<<"Masukkan kalimat :";cin>>str1;
	reverse_words(str1);
	cout<<str1<<endl;
	//getch();
}*/

class calculator
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

