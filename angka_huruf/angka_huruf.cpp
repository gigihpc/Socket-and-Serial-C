#include <iostream.h>
#include <string.h>
#include <conio.h>

char input[10];
int belas(char index)
{
if(index=='1') cout<<" satu ";
else if(index=='2') cout<<" dua ";
else if(index=='3') cout<<" tiga ";
else if(index=='4') cout<<" empat ";
else if(index=='5') cout<<" lima ";
else if(index=='6') cout<<" enam ";
else if(index=='7') cout<<" tujuh ";
else if(index=='8') cout<<" delapan ";
else if(index=='9') cout<<" sembilan ";
cout<<" Belas ";
return 0;
}
int angka(char index)
{
if(index=='1') cout<<" Satu ";
else if(index=='2') cout<<' Dua';
else if(index=='3') cout<<' Tiga';
else if(index=='4') cout<<' Empat';
else if(index=='5') cout<<" Lima";
else if(index=='6') cout<<" Enam";
else if(index=='7') cout<<" Tujuh";
else if(index=='8') cout<<" Delapan";
else if(index=='9') cout<<" Sembilan";
return 0;
}

int bilangan(int a,int b,char index)
{
int c;
c=a+(11-b);
if(c==1) cout<<" Milyar";
else if(c==8||c==5||c==2) cout<<"Ratus";
else if((c==9||c==6||c==3)&&index==’1?)cout<<"belas ";
else if(c==9||c==6||c==3) cout<<" Puluh";
return 0;
}

int bilangan2(int a,int b)
{
int c;
c=a+(11-b);
if(c==7) cout<<" Ribu";
else if(c==4) cout<<" Juta";
return 0;
}

void main()
{
int a,b;
cout<<"KONVERSI ANGKA KE HURUF(10 digit)"<<endl;
cout<>input;
b=strlen(input);

for(a=0;a<b;a++)
{
/*NOL*/
if((b==1)&&(a==(b-1))&&input[a]=='0')
{}
else if((b<3)&&(a==(b-4))&&input[a]=='1')
{}
else if((b<2)&&(a==(b-9)||a==(b-6)||a==(b-3))&&input[a]=='1')
{}
else if (b==5)
{
bilangan2(a+1,b);
a=a+1;
}
else if(b>8)
{
bilangan2(a+1,b);
a=a+1;
}
else
{
a=a+1;
}
}

/*BELASAN*/
if(input[a]=='1'&&(b>1)&&(a==(b-2)||a==(b-5)||a==(b-8)))
{}
if(input[a+1]=='1')
{}
if(input[a]=4)
{
bilangan2(a+1,b);
a=a+1;
}
else if(b>7)
{
bilangan2(a+1,b);
a=a+1;
}
else
{
a=a+1;
}
}

else if(input[a+1]=='0')
{
cout<<4;
{
bilangan2(a+1,b);
a=a+1;
}
else if(b>7)
{
bilangan2(a+1,b);
a=a+1;
}
else
{
a=a+1;
}
}

else if(input[a+1]!='1')
{
angka(input[a+1]);
bilangan(a,b,input[a]);
if(b>4)
{
bilangan2(a+1,b);
a=a+1;
}
else if(b>7)
{
bilangan2(a+1,b);
a=a+1;
}
else
{
a=a+1;
}
}

}

/*RIBUAN*/
else if((b>3)&&(a==(b-4)))
{
if(input[a]!='0')
{
angka(input[a]);
bilangan2(a,b);
}
else if ((b>6)&&(a==(b-4)&&input[a]=='0' && input[a-1]=='0' && input[a-2]=='0')){}
else
{
bilangan2(a,b);
}
}

/*JUTAAN*/
else if ((b>6)&&(a==(b-7)))
{
if(input[a]!='0')
{
angka(input[a]);
bilangan2(a,b);
}
else
{
bilangan2(a,b);
}
}
/*SATUAN*/
else
{

angka(input[a]);
if(input[a]!='0') bilangan(a,b,input[a]);

}
}
getch();
}

