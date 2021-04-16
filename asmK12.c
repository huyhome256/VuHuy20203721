// AssignmentTuyet.c
// Từ lâu
// 23 thg 11, 2019
// T
// Bạn đã tải lên một mục
// C
// AssignmentTuyet.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char ID[10];
    char nameTeam[50];
    char nameCoach[50];
    int match;
    int win;
    int lost;
    int tie;
    int point;

} team;

typedef struct
{
    char name[10];
    char ID1[10];
    char ID2[10];
    char day[10];
    char time[10];
    char place[50];
    int point1;
    int point2;

} schedule;

void PrintMainMenu();
int Choice();
void MenuListTeam();
team Input();
void PrintTeam();
void teamUpdates();
int AddTeam();
void MenuManageSchedule();
schedule InputSchedule();
int Schedule();
void PrintSchedule(schedule *str);
void MenuStatistical();
void GetString(char *str, int length);
int ReadStudentsFromFile(char *fileName, int *pCount, team *pListStudents);
int WriteStudentsToFile(team *pListStudents, int count, char *fileName);
int ReadFromFile(char *fileName, int *pCount, schedule *pListStudents);
int WriteToFile(schedule *pListStudents, int count, char *fileName);
char YorN();
int CheckCharacter(char *str);
int CheckCharacter2(char *str);
int CheckCharacter3(char *str);
int count = 0;
int count2 = 0;
int count3 = 0;
team *listTeam = NULL;
schedule *listSchedule = NULL;
void KQTD();

int main(int argc, char const *argv[])
{
    ReadStudentsFromFile("VL2018Teams.dat", &count, listTeam);
    ReadFromFile("VL2018Schedule.dat", &count2, listSchedule);
    if (listTeam == NULL)
    {
        listTeam = (team *)malloc((count + 1) * sizeof(team));
    }
    PrintMainMenu();
    // free(listTeam);
    // free(listSchedule);

    return 0;
}

void PrintMainMenu()
{
    // team *listTeam;
    // schedule *listSchedule;
    int n;
    do
    {
        system("cls");
        printf("\n--- Chao mung den voi V-League 2018 ---\n");
        printf("========================================\n");
        printf("1. Quan li danh sach doi bong \n");
        printf("2. Quan li lich thi dau.\n");
        printf("3. Quan li ket qua thi dau.\n");
        printf("4. Thong ke.\n");
        printf("0. Thoat.\n");
        printf("========================================\n");

        n = Choice();
        switch (n)
        {
        case 1:
            system("cls");
            MenuListTeam();
            break;
        case 2:
            system("cls");
            MenuManageSchedule();
            break;
        case 3:
            system("cls");
            KQTD();
            // nym();
            // MenuResult();
            break;
        case 4:
            system("cls");
            MenuStatistical();
            break;
        default:
            break;
        }

    } while (n != 0);
}

void MenuListTeam()
{

    int n1;
    do
    {
        system("cls");
        printf("\n========================================\n");
        printf("Quan li danh sach doi bong.\n");
        printf("1. Xem danh sach doi bong.\n");
        printf("2. Cap nhat thong tin doi bong.\n");
        printf("3. Them moi mot doi bong.\n");
        printf("0. Tro ve Menu chinh.\n");

        fflush(stdin);
        n1 = Choice();
        switch (n1)
        {
        case 1:

            system("cls");
            if (count == 0)
            {
                printf("Chua co doi bong nao !\nBan vui long them doi bong!");
                fflush(stdin);
                getchar();
            }
            else
            {
                printf("So luong doi: %d\n", count);
                printf("------------------------------------------------------------------------------------\n");
                printf("Danh sach doi bong.\n");
                PrintTeam();
                printf("Nhan phim bat ki de quay lai !");
                getchar();
            }
            break;
        case 2:
            system("cls");
            teamUpdates();
            break;
        case 3:
            system("cls");
            count = AddTeam();
            break;
        default:
            break;
        }
    } while (n1 != 0);
}

team Input()
{
    team newTeam;
    team listTeam2;

    while (1)
    {
        int count1 = 0;
        int temp = 0;
        printf("Nhap ma doi : ");
        GetString(newTeam.ID, 10);
        int check = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(newTeam.ID, (listTeam + i)->ID) == 0)
            {
                printf("Ma doi nay da ton tai vui long nhap lai!\n");
                check = 1;
            }
        }
        int b = CheckCharacter(newTeam.ID);
        if (b == 1 && check == 0)
        {
            strcpy(listTeam2.ID, newTeam.ID);
            break;
        }
    }

    while (1)
    {
        printf("Nhap ten doi : ");
        GetString(newTeam.nameTeam, 50);
        int check = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(newTeam.nameTeam, (listTeam + i)->nameTeam) == 0)
            {
                printf("Ten doi nay da ton tai vui long nhap lai!\n");
                check = 1;
            }
        }
        int b = CheckCharacter2(newTeam.nameTeam);
        if (b == 1 && check == 0)
        {
            strcpy(listTeam2.nameTeam, newTeam.nameTeam);
            break;
        }
    }
    while (1)
    {
        printf("Nhap huan luyen vien : ");
        GetString(newTeam.nameCoach, 50);
        int b = CheckCharacter3(newTeam.nameCoach);
        if (b == 1)
        {
            strcpy(listTeam2.nameCoach, newTeam.nameCoach);
            break;
        }
    }
    listTeam2.lost = 0;
    listTeam2.match = 0;
    listTeam2.point = 0;
    listTeam2.tie = 0;
    listTeam2.win = 0;
    return listTeam2;
}

int Choice()
{
    int ch;
    // printf("\n#Chon : ");
    // scanf("%d", &ch);
    // // fflush(stdin);
    // printf("\n");

    while (1)
    {
        printf("#Chon : ");
        int check = scanf("%d", &ch);
        if (check == 1)
        {
            return ch;
        }
        else
        {
            printf("Sai dinh dang !\nNhap 1 phim bat ki de nhap lai...");
            fflush(stdin);
            getchar();
        }
    }
}
void PrintTeam()
{
    ReadStudentsFromFile("VL2018Teams.dat", &count, listTeam);
    printf("====================================================================================\n");
    printf("|%-4s|%-15s|%-30s|%-30s|\n", "STT", "Ma doi", "Ten doi", "Ten huan luyen vien");
    printf("====================================================================================\n");
    for (int i = 0; i < count; i++)
    {
        printf("|%-4d|%-15s|%-30s|%-30s|\n", i + 1, (listTeam + i)->ID, (listTeam + i)->nameTeam, (listTeam + i)->nameCoach);
    }
    printf("====================================================================================\n");
    // WriteStudentsToFile(listTeam, count, "VL2018Teams.dat");
    fflush(stdin);
}

void teamUpdates()
{
    ReadStudentsFromFile("VL2018Teams.dat", &count, listTeam);
    if (count == 0)
    {
        printf("Chua co doi bong de cap nhat !\n");
        printf("Nhan phim bat ki de quay lai .\n");
         fflush(stdin);
        getchar();
    }
    else
    {
        team team;

        PrintTeam();

        printf("========================================\n");
        printf("====== Cap nhat thong tin doi bong ======\n");
        while (1)
        {
            int index = -1;
            int check = 0;
            while (1)
            {
                while (1)
                {

                    printf("Nhap ma doi bong ban muon cap nhap :");
                    GetString(team.ID, 10);
                    int b = CheckCharacter(team.ID);
                    if (b == 1)
                    {
                        break;
                    }
                }
                for (int i = 0; i < count; i++)
                {
                    if (strcmp(team.ID, (listTeam + i)->ID) == 0)
                    {
                        check = 1;
                        index = i;
                    }
                }
                if (check == 1)
                {
                    break;
                }
                else
                {
                    char ch;
                    printf("\nMa doi bong khong ton tai.\nNeu ban nhap lai xin vui long chon tiep tuc !\n");
                    ch = YorN();
                    if (ch == 'n' || ch == 'N')
                    {
                        return;
                    }
                }
            }
            if (check == 1)
            {
                while (1)
                {

                    printf("Sua ma doi bong : ");
                    GetString(team.ID, 50);
                    int check = 0;
                    for (int i = 0; i < count; i++)
                    {
                        if (strcmp(team.ID, listTeam[i].ID) == 0 && i != index)
                        {
                            printf("Ma doi nay da ton tai vui long nhap lai!\n");
                            check = 1;
                        }
                    }
                    int b = CheckCharacter(team.ID);
                    if (b == 1 && check == 0)
                    {
                        break;
                    }
                }
                while (1)
                {

                    printf("Sua ten doi bong : ");
                    GetString(team.nameTeam, 50);
                    int check = 0;
                    for (int i = 0; i < count; i++)
                    {
                        if (strcmp(team.nameTeam, listTeam[i].nameTeam) == 0 && i != index)
                        {
                            printf("Ten doi nay da ton tai vui long nhap lai!\n");
                            check = 1;
                        }
                    }
                    int b = CheckCharacter2(team.nameTeam);
                    if (b == 1 && check == 0)
                    {
                        break;
                    }
                }
                while (1)
                {

                    printf("Sua ten huan luyen vien : ");
                    GetString(team.nameCoach, 50);
                    int b = CheckCharacter3(team.nameCoach);
                    if (b == 1)
                    {
                        break;
                    }
                }

                printf("\n");
            }
            char choice, ch;
            do
            {
                printf("Ban co muon cap nhat thong tin doi bong ko(Y/N):");
                fflush(stdin);
                scanf("%c", &choice);

                if (choice == 'y' || choice == 'Y')
                {
                    *(listTeam + index) = team;
                    printf("Thong tin doi bong da duoc cap nhat!!\n");
                    WriteStudentsToFile(listTeam, count, "VL2018Teams.dat");
                    ch = YorN();
                    // break;
                    if (ch == 'n' || ch == 'N')
                    {
                        return;
                    }
                    getchar();
                    // return;
                }

            } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

            // choice = YorN();
            if (choice == 'N' || choice == 'n')
            {
                ch = YorN();
                // break;
                if (ch == 'n' || ch == 'N')
                {
                    return;
                }
                getchar();
            }
        }
    }
}

int AddTeam()
{
    // team *listTeam;

    char ch;

    printf("\n========================================\n");
    printf("========= Them mot doi bong moi =========\n");
    while (1)
    {

        listTeam = (team *)realloc(listTeam, (count + 1) * sizeof(team));
        // ReadStudentsFromFile("DanhSachDoiBong.dat", &count, listTeam);
        ReadStudentsFromFile("VL2018Teams.dat", &count, listTeam);
        printf("Nhap thong tin doi bong thu %d : \n", count + 1);
        *(listTeam + count) = Input();
        count++;

        printf("\n");
        ch = YorN();
        if (ch == 'n' || ch == 'N')
        {
            printf("Thong tin doi bong da duoc cap nhat.\n");
            WriteStudentsToFile(listTeam, count, "VL2018Teams.dat");
            fflush(stdin);
            getchar();
            break;
        }
    }

    return count;
}

void MenuManageSchedule()
{
    // ReadStudentsFromFile("VL2018Schedule.dat", &count, listTeam);
    if (listSchedule == NULL)
    {
        listSchedule = (schedule *)malloc((count2 + 1) * sizeof(schedule));
    }

    int n2;
    do
    {
        system("cls");
        printf("========================================\n");
        printf("Quan li lich thi dau.\n");
        printf("1. Xem lich thi dau.\n");
        printf("2. Tao lich thi dau.\n");
        printf("0. Tro ve Menu chinh.\n");
        n2 = Choice();
        switch (n2)
        {
        case 1:
            system("cls");
            if (count2 == 0)
            {
                printf("Chua co lich thi dau nao !\nBan vui long them lich thi dau!");
                fflush(stdin);
                getchar();
            }
            else
            {

                printf("So luong tran: %d\n", count2);
                printf("----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("Danh sach doi bong.\n");
                PrintSchedule(listSchedule);
                printf("Nhan phim bat ki de quay lai !");
                getchar();
            }

            break;
        case 2:
            system("cls");
            PrintTeam();
            count2 = Schedule();
            break;

        default:
            break;
        }
    } while (n2 != 0);
}

schedule InputSchedule()
{

    schedule newSchedule;
    schedule listSchedule;
    int index = -1;
    while (1)
    {
        printf("ID Tran : ");
        GetString(newSchedule.name, 10);

        int b = CheckCharacter2(newSchedule.name);
        if (b == 1)
        {
            strcpy(listSchedule.name, newSchedule.name);
            break;
        }
    }
    while (1)
    {
        int check = 0;

        printf("Ten doi bong 1 : ");
        GetString(newSchedule.ID1, 10);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(newSchedule.ID1, (listTeam + i)->nameTeam) == 0)
            {
                check = 1;
                index = i;
            }
        }
        if (check == 1)
        {
            strcpy(listSchedule.ID1, (listTeam + index)->nameTeam);
            break;
        }
        else
        {
            printf("Khong co ten doi bong nay !");
        }
    }
    while (1)
    {
        int index2 = -1;
        int check = 0;
        printf("Ten doi bong 2 : ");
        GetString(newSchedule.ID2, 10);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(newSchedule.ID2, (listTeam + i)->nameTeam) == 0 && index != i)
            {
                check = 1;
                index2 = i;
            }
        }
        if (check == 1)
        {
            strcpy(listSchedule.ID2, (listTeam + index2)->nameTeam);
            break;
        }
        else
        {
            printf("Khong co ten doi bong nay hoac trung voi ten doi bong tren !");
        }
    }

    while (1)
    {
        int count1 = 0;
        int temp = 0;
        printf("Ngay thi dau (dd/mm/yyyy): ");
        GetString(newSchedule.day, 10);
        if (strlen(newSchedule.day) > 0)
        {
            for (int i = 0; i < strlen(newSchedule.day); i++)
            {
                if (newSchedule.day[i] == ' ')
                {
                    count1++;
                }
            }
            for (int i = 0; i < strlen(newSchedule.day); i++)
            {
                if ((newSchedule.day[i] >= '0' && newSchedule.day[i] <= '9') || newSchedule.day[i] == '/')
                {
                    temp++;
                }
            }
            if (count1 != strlen(newSchedule.day) && (temp == strlen(newSchedule.day)))
            {
                strcpy(listSchedule.day, newSchedule.day);
                break;
            }
            else
            {
                printf("Khong hop le , moi nhap lai.\n");
            }
        }
    }
    while (1)
    {
        int count1 = 0;
        int temp = 0;
        printf("Gio thi dau (00h00): ");
        GetString(newSchedule.time, 10);

        if (strlen(newSchedule.time) > 0)
        {
            for (int i = 0; i < strlen(newSchedule.time); i++)
            {
                if (newSchedule.time[i] == ' ')
                {
                    count1++;
                }
            }
            for (int i = 0; i < strlen(newSchedule.time); i++)
            {
                if ((newSchedule.time[i] == 'h' || newSchedule.time[i] == 'H') || (newSchedule.time[i] >= '0' && newSchedule.time[i] <= '9'))
                {
                    temp++;
                }
            }
            if (count1 != strlen(newSchedule.time) && (temp == strlen(newSchedule.time)))
            {
                strcpy(listSchedule.time, newSchedule.time);
                break;
            }
            else
            {
                printf("Khong hop le , moi nhap lai.\n");
            }
        }
    }
    while (1)
    {
        int count1 = 0;
        int temp = 0;
        printf("Dia diem thi dau : ");
        GetString(newSchedule.place, 10);

        if (strlen(newSchedule.place) > 0)
        {
            for (int i = 0; i < strlen(newSchedule.place); i++)
            {
                if (newSchedule.place[i] == ' ')
                {
                    count1++;
                }
            }
            for (int i = 0; i < strlen(newSchedule.place); i++)
            {
                if ((newSchedule.place[i] >= 'a' && newSchedule.place[i] <= 'z') || (newSchedule.place[i] >= 'A' && newSchedule.place[i] <= 'Z') || (newSchedule.place[i] >= '0' && newSchedule.place[i] <= '9') || newSchedule.place[i] == ' ' || newSchedule.place[i] == '-')
                {
                    temp++;
                }
            }
            if (count1 != strlen(newSchedule.place) && (temp == strlen(newSchedule.place)))
            {
                strcpy(listSchedule.place, newSchedule.place);
                break;
            }
            else
            {
                printf("Khong hop le , moi ban nhap lai.\n");
            }
        }
    }

    return listSchedule;
    // }
}

int Schedule()
{
    ReadFromFile("VL2018Schedule.dat", &count2, listSchedule);
    if (count < 2)
    {
        printf("Chua co doi bong nao de tao lich !\n");
        printf("Nhan phim bat ki de quay lai !\n");
        fflush(stdin);
        getchar();
    }
    else
    {

        char ch;
        printf("========================================\n");
        printf("=========== Tao lich thi dau ===========\n");
        while (1)
        {

            listSchedule = (schedule *)realloc(listSchedule, (count2 + 1) * sizeof(schedule));
            ReadFromFile("VL2018Schedule.dat", &count2, listSchedule);

            printf("Nhap thong tin tran dau thu %d : \n", count2 + 1);
            *(listSchedule + count2) = InputSchedule();

            count2++;
            printf("\n");
            ch = YorN();
            if (ch == 'n' || ch == 'N')
            {
                printf("Thong tin tran dau da duoc cap nhat.\n");
                WriteToFile(listSchedule, count2, "VL2018Schedule.dat");
                fflush(stdin);
                getchar;
                return count2;
            }
        }
    }
}

void PrintSchedule(schedule *str)
{
    ReadFromFile("VL2018Schedule.dat", &count2, listSchedule);
    printf("=================================================================================================================================\n");
    printf("|%-4s|%-15s|%-40s|%-18s|%-15s|%-30s|\n", "STT", "ID Tran", "Tran", "Ngay thi dau", "Gio thi dau", "San thi dau");
    printf("=================================================================================================================================\n");
    for (int i = 0; i < count2; i++)
    {
        printf("|%-4d|%-15s|%-17s%-6s%-17s|%-18s|%-15s|%-30s|\n", i + 1, (str + i)->name, (str + i)->ID1, "vs", (str + i)->ID2, (str + i)->day, (str + i)->time, (str + i)->place);
    }
    printf("=================================================================================================================================\n");

    fflush(stdin);
}

void KQTD()
{
    system("cls");
    if (count2 == 0)
    {
        printf("Chua co lich thi dau !");
        fflush(stdin);
        getchar();
    }
    else
    {
        PrintSchedule(listSchedule);

        int indexTeam1 = -1, indexTeam2 = -1;
        int pointTeam1 = -1, pointTeam2 = -1;
        printf("========================================\n");
        printf("=========== Ket qua thi dau ============\n");
        int index = -1;
        while (1)
        {
            int check = 0;
            char name[50];
            printf("Nhap ID tran : ");
            GetString(name, 50);
            for (int i = 0; i < count2; i++)
            {
                if (strcmp(name, (listSchedule + i)->name) == 0)
                {
                    check = 1;
                    index = i;
                }
            }
            if (check == 1)
            {
                break;
            }
            else
            {
                printf("Khong co tran bong nay !\n");
            }
        }
        for (int i = 0; i < count; i++)
        {
            if (strcmp((listTeam + i)->nameTeam, (listSchedule + index)->ID1) == 0)
            {
                indexTeam1 = i;
            }
        }
        for (int i = 0; i < count; i++)
        {
            if (strcmp((listTeam + i)->nameTeam, (listSchedule + index)->ID2) == 0)
            {
                indexTeam2 = i;
            }
        }
        while (1)
        {
            printf("Ket qua %s : ", (listTeam + indexTeam1)->nameTeam);
            int check = scanf("%d", &pointTeam1);
            if (check == 1 && pointTeam1 >= 0)
            {
                break;
            }
            else
            {
                printf("Sai dinh dang !\nNhap 1 phim bat ki de nhap lai...");
                fflush(stdin);
                getchar();
            }
        }

        while (1)
        {
            printf("Ket qua %s : ", (listTeam + indexTeam2)->nameTeam);
            int check = scanf("%d", &pointTeam2);
            if (check == 1 && pointTeam2 >= 0)
            {
                break;
            }
            else
            {
                printf("Sai dinh dang %d !\nNhap 1 phim bat ki de nhap lai...");
                fflush(stdin);
                getchar();
            }
        }

        char choice;

        while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N')
        {

            printf("Ban co muon cap nhat(Y/N):");
            fflush(stdin);
            scanf("%c", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                // int thua = 0;
                // int thang = 0;
                // int hoa = 0;

                (listTeam + indexTeam2)->match++;
                (listTeam + indexTeam1)->match++;
                if (pointTeam1 > pointTeam2)
                {
                    // thua++;
                    // thang++;
                    (listTeam + indexTeam1)->win++;
                    (listTeam + indexTeam2)->lost++;
                }
                else if (pointTeam1 < pointTeam2)
                {
                    // thua++;
                    // thang++;
                    (listTeam + indexTeam2)->win++;
                    (listTeam + indexTeam1)->lost++;
                }
                else
                {
                    (listTeam + indexTeam2)->tie++;
                    (listTeam + indexTeam1)->tie++;
                }

                printf("Ket qua tran dau da duoc cap nhat!!\n");

                getchar();
                getchar();
                break;
            }
        }

        // choice = YorN();
        if (choice == 'N' || choice == 'n')
        {
            return;
        }
    }
}

void MenuStatistical()
{
    ReadStudentsFromFile("VL2018Log.dat", &count, listTeam);
    system("cls");
    for (int i = 0; i < count; i++)
    {
        (listTeam + i)->point = ((listTeam + i)->win) * 3 + (listTeam + i)->tie;
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {

            if (listTeam[i].point < listTeam[j].point)
            {
                team temp = listTeam[i];
                listTeam[i] = listTeam[j];
                listTeam[j] = temp;
            }
        }
    }
    WriteStudentsToFile(listTeam, count, "VL2018Log.dat");
    ReadStudentsFromFile("VL2018Log.dat", &count, listTeam);
    printf("==========================================================================================================\n");
    printf("Bang xep hang\n");
    printf("==========================================================================================================\n");
    printf("|%-5s|%-12s|%-30s|%-10s|%-10s|%-10s|%-10s|%-10s|\n", "STT", "Ma doi", "Ten doi", "Tran", "Thang", "Thua", "Hoa", "Diem");
    printf("==========================================================================================================\n");
    for (int i = 0; i < count; i++)
    {
        printf("|%-5d|%-12s|%-30s|%-10d|%-10d|%-10d|%-10d|%-10d|\n", i + 1, (listTeam + i)->ID, (listTeam + i)->nameTeam, (listTeam + i)->match, (listTeam + i)->win, (listTeam + i)->lost, (listTeam + i)->tie, (listTeam + i)->point);
    }
    printf("==========================================================================================================\n");

    printf("\nChuc cac doi thi dau giai V-League 2018 thanh cong !\n");
    fflush(stdin);
    getchar();
}

void GetString(char *str, int length)
{
    fflush(stdin);
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    fflush(stdin);
}

int ReadStudentsFromFile(char *fileName, int *pCount, team *pListStudents)
{
    FILE *pf;
    int result = 0;

    pf = fopen(fileName, "rb");
    if (pf != NULL)
    {
        //Đọc số struct Student lưu trong file
        fread(pCount, sizeof(int), 1, pf);
        if (pCount > 0)
        {
            //Đọc dữ liệu của các struct Student trong file
            //rồi lưu vào pListStudents
            fread(pListStudents, sizeof(team), *pCount, pf);
            result = 1;
        }

        //Đóng file
        fclose(pf);
    }

    return result;
}

int WriteStudentsToFile(team *pListStudents, int count, char *fileName)
{
    FILE *pf;

    int result = 0;

    pf = fopen(fileName, "wb");

    if (pf != NULL)
    {
        //Ghi số lượng struct Student vào đầu file
        fwrite(&count, sizeof(int), 1, pf);

        //Ghi mảng các struct Student vào file
        fwrite(pListStudents, sizeof(team), count, pf);
        fclose(pf);
        result = 1;
    }

    return result;
}
char YorN()
{
    char ch;
    while (1)
    {
        printf("Ban co muon tiep tuc (Y/N) : ");
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
        {
            return ch;
        }
        else
        {
            printf("Ban nhap sai !\n");
        }
    }
}

int CheckCharacter(char *str)
{
    int check = 0;
    int count = 0;
    int temp = 0;
    char *list;
    if (strlen(str) > 0)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ')
            {
                count++;
            }
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
            {
                temp++;
            }
        }
        if (count != strlen(str) && (temp == strlen(str)))
        {
            check = 1;
        }
        else
        {
            printf("Khong hop le , moi ban nhap lai.\n");
        }
    }
    return check;
}
int CheckCharacter2(char *str)
{
    int check = 0;
    int count = 0;
    int temp = 0;
    char *list;
    if (strlen(str) > 0)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ')
            {
                count++;
            }
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ' || (str[i] >= '0' && str[i] <= '9') || str[i] == '-')
            {
                temp++;
            }
        }
        if (count != strlen(str) && (temp == strlen(str)))
        {
            check = 1;
        }
        else
        {
            printf("Khong hop le , moi ban nhap lai.\n");
        }
    }
    return check;
}
int CheckCharacter3(char *str)
{
    int check = 0;
    int count = 0;
    int temp = 0;
    char *list;
    if (strlen(str) > 0)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ')
            {
                count++;
            }
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' ') || (str[i] == '.'))
            {
                temp++;
            }
        }
        if (count != strlen(str) && (temp == strlen(str)))
        {
            check = 1;
        }
        else
        {
            printf("Khong hop le , moi ban nhap lai.\n");
        }
    }
    return check;
}
int ReadFromFile(char *fileName, int *pCount, schedule *pListStudents)
{
    FILE *pf;
    int result = 0;

    pf = fopen(fileName, "rb");
    if (pf != NULL)
    {
        //Đọc số struct Student lưu trong file
        fread(pCount, sizeof(int), 1, pf);
        if (pCount > 0)
        {
            //Đọc dữ liệu của các struct Student trong file
            //rồi lưu vào pListStudents
            fread(pListStudents, sizeof(schedule), *pCount, pf);
            result = 1;
        }

        //Đóng file
        fclose(pf);
    }

    return result;
}

int WriteToFile(schedule *pListStudents, int count, char *fileName)
{
    FILE *pf;

    int result = 0;

    pf = fopen(fileName, "wb");

    if (pf != NULL)
    {
        //Ghi số lượng struct Student vào đầu file
        fwrite(&count, sizeof(int), 1, pf);

        //Ghi mảng các struct Student vào file
        fwrite(pListStudents, sizeof(schedule), count, pf);
        fclose(pf);
        result = 1;
    }

    return result;
}