#include<stdio.h>
#include<string.h>

void mahoa(char *x, int a, int b){
	int l = strlen(x);
	for (int i = 0; i < l; i++){
		if (x[i]>='A' && x[i]<='Z')
			x[i] = (a*(x[i]-'A') + b) % 26 + 'A';
		else if (x[i]>='a' && x[i]<='z')
			x[i] = (a*(x[i]-'a') + b) % 26 + 'a';
	}
}

int gcd(int a, int b)
{
	if (a==0 || b==0) 
		return a+b;
	while (a!=b)
	{
		if (a > b) a-=b;
		else b-=a;
	}
	return a;
}
int nghichdao(int a)
{
	int k, du, ngd;
	k = 1; 
		do
		{ 
			du = (k*26+1)%a ;
			if ( du==0 ) 
				ngd = (k*26+1)/a ; 
			k++; 
		} 
		while (du!=0);
	return ngd;
}

void giaima(char *y, int ngd, int b)
{
	int t, l = strlen(y);
	for (int i = 0; i < l; i++){
		if (y[i]>='A' && y[i]<='Z'){
			t = ngd*(y[i]-'A' - b );
			if (t>=0)
				y[i] = t % 26 + 'A';
			else 
				y[i] = 26- (-t) % 26 + 'A';
	}
		else if (y[i]>='a' && y[i]<='z')
		{
			t = ngd*(y[i]-'a' - b );
			if (t>=0)
				y[i] = t % 26 + 'a';
			else 
				y[i] = 26- (-t) % 26 + 'a';
			}
	}
}
int main(){
	char x[100];
	int a, b, ngd ;
	printf("Nhap thong diep: "); fgets(x,sizeof(x),stdin);
	printf("Nhap khoa: k = (a, b) "); scanf("%d%d", &a, &b); 
	x[strcspn(x,"\n")]='\0';
	mahoa(x,a,b);
	printf("Thong diep da ma hoa: %s\n", x);
	if (gcd(a,26)!=1)
		printf("Khong giai ma duoc");
	else
	{
		ngd = nghichdao(a);
		giaima(x,ngd,b);
		printf("Thong diep da giai ma: %s\n", x);
	}
	return 0;
}
