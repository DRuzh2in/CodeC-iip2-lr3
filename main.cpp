#include <stdio.h>

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

        printf("Enter Name:\n");
        gets(arrMen[i].name);
        fflush(stdin);

        printf("Enter Address: \n");
        gets(arrMen[i].address);
        fflush(stdin);

        printf("Enter date of birth\n");
        printf("Enter day: \n");
        scanf("%d",&arrMen[i].dd);

        printf("Enter month: \n");
        scanf("%d",&arrMen[i].mm);

        printf("Enter year: \n");
        scanf("%d",&arrMen[i].yy);
    }
}
void showNotesMen(struct man *arrMen, int sizeArr)
{
   for (int i=0; i<sizeArr; i++)
        printf("%s %s %d %d %d \n", arrMen[i].name, arrMen[i].address, arrMen[i].dd, arrMen[i].mm, arrMen[i].yy);
}

int main()
{
    int sizeArr = getSizeArr();
    man arrMen[sizeArr];
    getMan(arrMen, sizeArr);
    showNotesMen(arrMen, sizeArr);
}
