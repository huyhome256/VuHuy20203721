#include<stdio.h>

int main (){
	int gio, phut, giay;
	printf("Nhap so giay: ");
	scanf("%d", &giay);
	gio = giay/3600;
	giay = giay % 3600;
	phut= giay/60;
	giay= giay % 60;
	printf("%d gio %d phut %d giay", gio, phut, giay);
	return 0;
}