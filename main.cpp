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
    printf("Enter the number of notes");
    scanf("%d", &sizeArr);
    return sizeArr;
}

int getMan()
{
    char error;
    int sizeArr = getSizeArr();
    man arrMen[sizeArr];
    for (int i = 0; i < sizeArr; i++)
    {
        printf("Press any key. ");
        gets(&error);
        fflush(stdin);

        printf("Enter Name:\n");
        gets(arrMen[i].name);
        fflush(stdin);

        printf("Enter date of birth\n");
        printf("Enter day: \n");
        scanf("%d",&arrMen[i].dd);
        fflush(stdin);
        printf("Enter mounth: \n");
        scanf("%d",&arrMen[i].mm);
        fflush(stdin);
        printf("Enter year: \n");
        scanf("%d",&arrMen[i].yy);
        fflush(stdin);

        printf("Enter Address:\n");
        gets(arrMen[i].address);
        fflush(stdin);
    }
    int linkArrMen = man arrMen[sizeArr];

}

void showNotes()
{
    for (int i=0; i<10;i++)
        printf("%s %d %d %d %s \n", arrMen[i].name, arrMen[i].dd, arrMen[i].mm, arrMen[i].yy, arrMen[i].address);
}

int main()
{
    int *Men = getMan();


}
