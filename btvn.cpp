#include<stdio.h>
int main () {
	float r, d, C, S;
	printf("nhap vao ban kinh: ");
	scanf("%f", &r);
	C = 2 * 3.14 * r;
	S = 3.14 * r * r;
	d = 2 * r;
	printf("duong kinh hinh tron la: %.2f \n chu vi hinh tron la: %.2f \n Dien tich hinh tron la: %.2f", d, C, S);
}