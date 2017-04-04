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

        char Arr[50] = {0}; // new array for structure

        int N = strlen(arrMen[i].name);
        int M = strlen(arrMen[i].address);

        ((int *)Arr)[0] = N; // enter length string name
        ((int *)Arr)[5] = M;// enter length string address

        char *name = &arrMen[i].name[0];
        for (int n = 0; n<=N; n++){
            Arr[1+n]=name[n];
        } // input structure name in array

        char *address = &arrMen[i].address[0];

        for (int n = 0; n<=M; n++)
        {
            Arr[21+n] = address[n];// input structure address in array
        }


        ((int *)Arr)[10] = arrMen[i].dd; // input structure day in array
        ((int *)Arr)[11] = arrMen[i].mm;// input structure month in array
        ((int *)Arr)[12] = arrMen[i].yy;// input structure year in array

        for (int y=0; y<50; y++)
            printf("%d ",Arr[y]); // print on display array byte

        printf("\n"); // print on display array byte

        for (int y=0; y<50; y++)
            if (Arr[y] != 0)
                printf("%X ", &Arr[y]);  // print on display array address in memory

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
