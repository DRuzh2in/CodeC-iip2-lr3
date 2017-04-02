#include <stdio.h>
#include <cstring>

struct man {
    char name[20];
    int dd;
    int mm;
    int yy;
    char address[20];
};

int getSizeArr()
{
    int sizeArr;
    printf("Enter the number of notes: ");
    scanf("%d", &sizeArr);
    return sizeArr;
}

void getMan(struct man *arrMen, int sizeArr)
{
    char error;


    for (int i = 0; i < sizeArr; i++)
    {
        printf("\nNote: %d",i);

        printf("\n");
        gets(&error);
        fflush(stdin);

        printf("Name:\n");
        gets(arrMen[i].name);
        fflush(stdin);

        printf("Address: \n");
        gets(arrMen[i].address);
        fflush(stdin);

        printf("Enter date of birth\n");
        printf("Day: \n");
        scanf("%d",&arrMen[i].dd);

        printf("Month: \n");
        scanf("%d",&arrMen[i].mm);

        printf("Year: \n");
        scanf("%d",&arrMen[i].yy);
    }
}
void showNotesMen(struct man *arrMen, int sizeArr)
{
   for (int i=0; i<sizeArr; i++)
        printf("%s %s %d %d %d \n", arrMen[i].name, arrMen[i].address, arrMen[i].dd, arrMen[i].mm, arrMen[i].yy);
}

void showByte(struct man *arrMen, int sizeArr)
{
    for (int i = 0; i < sizeArr; i++)
    {
        printf("Note: %d\n", i);
        int N = strlen(arrMen[i].name);
        int M = strlen(arrMen[i].address);
        printf("Name = {");
        for (int j = 0; j<N; j++)
        {
            printf("0x%X ", &arrMen[i].name[j]);
        }
        printf("}\n");
        printf("Address = {");
        for (int k = 0; k<M; k++)
        {
            printf("0x%X ", &arrMen[i].address[k]);
        }
        printf("}\n");
        printf("Day = {0x%X}\n", &arrMen[i].dd);
        printf("Month = {0x%X}\n", &arrMen[i].mm);
        printf("Year = {0x%X}\n", &arrMen[i].yy);
    }
}

int main()
{
    int sizeArr = getSizeArr();
    man arrMen[sizeArr];
    getMan(arrMen, sizeArr);
    showNotesMen(arrMen, sizeArr);
    showByte(arrMen, sizeArr);
}
