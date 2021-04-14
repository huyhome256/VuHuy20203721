#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct taikhoan{
	char tendangnhap[30];
	char matkhau[100];
	
};
int menu(){
    system("cls");
    printf("Chao mung ban den voi chuong trinh cua toi \n");
    printf("1. Dang nhap \n");
    printf("2. Dang ky \n");
    printf("3. Thoat\n\n");
    printf("Chon [1-3] de tiep tuc: ");
    int cn;
    scanf("%d",&cn);
    return cn;
}
void dangnhap(){
    system("cls");
    printf("Ten dang nhap: ");
    char a[100];
    gets(a);
    char b[100];
    
    getch();

}
void dangky(){
    system("cls");
    fflush(stdin);
    int i = 1, j =0;
	printf("nhap ten dang nhap: \n");
	gets(tk[j].tenDangNhap);
	printf("nhap mat khau: \n");
	gets("tk[j].matKhau");
	tk[j].id = i;
	printf("ban da dang ki thanh cong!!! \n");
	i++;
	j++;
    getch();

}

main(){
    while(1){
        int cn = menu();
        if(cn>3 || cn <1)
            continue;
        switch(cn){
            case 1:
                chucnang1();
                break;
            case 2:
                chucnang2();
                break;
            case 3:
                exit(0);
                break;
        }

    }
}