#include<stdio.h>
#define tiendien 3500
int main () {
	float cong, time;
	float P, Price;
	printf("cong(jun) va thoi gian su dung(s): ");
	scanf("%f%f", &cong, &time);
	P = cong / time;
	Price =P/1000 * 30 * 24 * tiendien;
	printf("tien dien su dung hang thang la: %f", Price );
}