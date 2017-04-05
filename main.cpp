#include <stdio.h>
#include <cstdlib>



struct man {
    char name[11];
    int dd;
    int mm;
    int yy;
    char address[11];
};

int getSizeArr()
{
    int sizeArr;
    printf("Enter the number of notes: ");
    scanf("%d", &sizeArr);
    return sizeArr;
}

void getMan(struct man *arrMenSrtuct, int sizeArr)
{
    char error;


    for (int i = 0; i < sizeArr; i++)
    {
        printf("\nNote: %d",i);

        printf("\n");
        gets(&error);
        fflush(stdin);

        printf("Name:\n");
        gets(arrMenSrtuct[i].name);
        fflush(stdin);

        printf("Enter date of birth\n");
        printf("Day: \n");
        scanf("%d",&arrMenSrtuct[i].dd);

        printf("Month: \n");
        scanf("%d",&arrMenSrtuct[i].mm);

        printf("Year: \n");
        scanf("%d",&arrMenSrtuct[i].yy);

        printf("\n");
        gets(&error);
        fflush(stdin);

        printf("Address: \n");
        gets(arrMenSrtuct[i].address);
        fflush(stdin);
    }
}
void showNotesMen(struct man *arrMenSrtuct, int sizeArr)
{
    for (int i=0; i<sizeArr; i++)
        printf("%s %d %d %d %s\n", arrMenSrtuct[i].name, arrMenSrtuct[i].dd, arrMenSrtuct[i].mm, arrMenSrtuct[i].yy, arrMenSrtuct[i].address);
}

int dec2dex(char *arrMenByte, int digit10, int n)
{
    int i = 0, j, temp;
    char dec[4];
    while (digit10 != 0) {
        temp = digit10 % 16; //convert int to char
        if (temp < 10) temp = temp + 48;
        else temp = temp + 55;
        dec[i++] = temp;
        digit10 = digit10 / 16;
    }
    for (j = i - 1; j > 0; n++, j--){
        arrMenByte[n] = dec[j];}
    return n;
}


void showByte(struct man *arrMenSrtuct, int sizeArr)
{
    int maxByteStruct = 36;
    int maxInt = 9;
    int maxArr = maxByteStruct * sizeArr;
    char *arrMenByte = (char*)malloc(maxArr); //create new arr for srtructure
    int name = 0; // flag to mane in arr
    int dd = 3; // flag to day in arr
    int address = 24; // flag to address in arr
    for (int i = 0; i < sizeArr; i++)
    {
        int cycleName = name; // flag for one cycle
        for (int j = 0; arrMenSrtuct[i].name[j] != '\0'; cycleName++, j++)
        {
            arrMenByte[cycleName] = arrMenSrtuct[i].name[j]; // input structure name in array
        }
        arrMenByte[name-1] = '\0';


        ((int *)arrMenByte)[dd] = arrMenSrtuct[i].dd; // input structure day in array
        int mm = dd+1; // search field month

        ((int *)arrMenByte)[mm] = arrMenSrtuct[i].mm; // input structure month in array
        int yy = mm+1; // searh field year
        ((int *)arrMenByte)[yy] = arrMenSrtuct[i].yy; // input structure year in array

        int cycleAddress = address; // flag for one cycle
        for (int j = 0; arrMenSrtuct[i].address[j] != '\0'; cycleAddress++, j++)
        {
            arrMenByte[cycleAddress]=arrMenSrtuct[i].address[j];// input structure address in array
        }
        arrMenByte[address-1] = '\0';

        name += maxByteStruct; // chang flag for next cycle
        dd += maxInt;
        address += maxByteStruct;

    }
    for (int n = 0; n < maxArr; n++)
        printf("%d %x\n",n, arrMenByte[n]); // print on display array byte

}

int main()
{
    int sizeArr = getSizeArr(); // haw mach structures created
    man arrMenSrtuct[sizeArr]; // create structure array
    getMan(arrMenSrtuct, sizeArr); // create structure
    showNotesMen(arrMenSrtuct, sizeArr); // chow array structure
    showByte(arrMenSrtuct, sizeArr); // chow array fields
}
