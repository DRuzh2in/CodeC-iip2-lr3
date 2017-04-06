#include <stdio.h>
#include <cstdlib>

struct man {
    char name[11];
    int dd;
    int mm;
    int yy;
    char address[11];
};

struct newMan {
    char name[11];
    int dd;
    int mm;
    int yy;
    char address[11];
};

int getSizeArr() {
    int sizeArr;
    printf("How many structures to add: ");
    scanf("%d", &sizeArr);
    return sizeArr;
}

void getMan(struct man *arrMenSrtuct, int sizeArr) {
    char error;

    for (int i = 0; i < sizeArr; i++) {
        printf("\nStructure: %d", i);

        printf("\n");
        gets(&error);
        fflush(stdin);

        printf("\nName:\n");
        gets(arrMenSrtuct[i].name);
        fflush(stdin);

        printf("\nEnter date of birth in format DD MM YY\n");
        printf("Day: \n");
        scanf("%d", &arrMenSrtuct[i].dd);

        printf("Month: \n");
        scanf("%d", &arrMenSrtuct[i].mm);

        printf("Year: \n");
        scanf("%d", &arrMenSrtuct[i].yy);

        printf("\n");
        gets(&error);
        fflush(stdin);

        printf("Address: \n");
        gets(arrMenSrtuct[i].address);
        fflush(stdin);
    }
}

void shouHeader() {
    printf("\n|----------------------------------------------------------|\n");
    printf("|%3s| %15s| %5s| %5s| %5s| %15s|\n", "id", "Name", "Day", "Month", "Year", "Address");
    printf("|---+----------------+------+------+------+----------------|\n");
}

void showNotes(struct man *arrMenSrtuct, struct newMan *arrNewMenStruct, int sizeArr, int key) {
    for (int j = 0; j < sizeArr; j++) {
        if (key == 0) {
            printf("|%3d| %15s| %5d| %5d| %5d| %15s|\n",
                   j,
                   arrMenSrtuct[j].name,
                   arrMenSrtuct[j].dd,
                   arrMenSrtuct[j].mm,
                   arrMenSrtuct[j].yy,
                   arrMenSrtuct[j].address);
        } else {
            printf("|%3d| %15s| %5d| %5d| %5d| %15s|\n",
                   j,
                   arrNewMenStruct[j].name,
                   arrNewMenStruct[j].dd,
                   arrNewMenStruct[j].mm,
                   arrNewMenStruct[j].yy,
                   arrNewMenStruct[j].address);
        }
        printf("|----------------------------------------------------------|\n");
    }
}

void showArrMenByte(char *arrMenByte, int maxArr, int maxByteStruct, int sizeArr) {
    int key = 0;
    printf("\n");
    for (int i = 0; i < maxArr; key++, i++) {
        printf("%x ", arrMenByte[i]); // print on display array byte
        if (key == maxByteStruct - 1) {
            printf("\n");
            key = -1;
        }
    }
}

void packByte(struct man *arrMenSrtuct, int sizeArr, int maxByteStruct, int maxArr, char *arrMenByte) {

    int maxInt = 9; // flag for size array
    int name = 0; // flag to mane in arr
    int dd = 3; // flag to day in arr
    int address = 24; // flag to address in arr

    for (int i = 0; i < maxArr; i++) {
        arrMenByte[i] = '\0';
    }

    for (int i = 0; i < sizeArr; i++) {
        int cycleName = name; // flag for one cycle
        for (int j = 0; arrMenSrtuct[i].name[j] != '\0'; cycleName++, j++) {
            arrMenByte[cycleName] = arrMenSrtuct[i].name[j]; // input structure name in array
        }
        arrMenByte[name - 1] = '\0';


        ((int *) arrMenByte)[dd] = arrMenSrtuct[i].dd; // input structure day in array
        int mm = dd + 1; // search field month

        ((int *) arrMenByte)[mm] = arrMenSrtuct[i].mm; // input structure month in array
        int yy = mm + 1; // searh field year

        ((int *) arrMenByte)[yy] = arrMenSrtuct[i].yy; // input structure year in array

        int cycleAddress = address; // flag for one cycle
        for (int j = 0; arrMenSrtuct[i].address[j] != '\0'; cycleAddress++, j++) {
            arrMenByte[cycleAddress] = arrMenSrtuct[i].address[j];// input structure address in array
        }
        arrMenByte[address - 1] = '\0';

        name += maxByteStruct; // chang flag for next cycle
        dd += maxInt;
        address += maxByteStruct;
    }

}

void unpack(struct newMan *arrNewMenStruct, int sizeArr, int maxByteStruct, int maxArr, char *arrMenByte) {
    int maxInt = 9; // flag for size array
    int name = 0; // flag to mane in arr
    int dd = 3; // flag to day in arr
    int address = 24; // flag to address in arr

    for (int i = 0; i < sizeArr; i++) {
        arrNewMenStruct[i] = {'\0', 0, 0, 0, '\0'};
    }

    for (int i = 0; i < sizeArr; i++) {
        int cycleName = name; // flag for one cycle
        for (int j = 0; arrMenByte[cycleName] != '\0'; cycleName++, j++) {
            arrNewMenStruct[i].name[j] = arrMenByte[cycleName];
        }

        arrNewMenStruct[i].dd = ((int *) arrMenByte)[dd];
        int mm = dd + 1;

        arrNewMenStruct[i].mm = ((int *) arrMenByte)[mm];
        int yy = mm + 1;

        arrNewMenStruct[i].yy = ((int *) arrMenByte)[yy];

        int cycleAddress = address; // flag for one cycle
        for (int j = 0; arrMenByte[cycleAddress] != '\0'; cycleAddress++, j++) {
            arrNewMenStruct[i].address[j] = arrMenByte[cycleAddress];// input structure address in array
        }
        name += maxByteStruct; // chang flag for next cycle
        dd += maxInt;
        address += maxByteStruct;
    }
}

int main() {
    int sizeArr = getSizeArr(); // haw mach structures created

    man arrMenSrtuct[sizeArr]; // create structure array
    newMan arrNewMenStruct[sizeArr]; // create structure array after unpack

    getMan(arrMenSrtuct, sizeArr); // create structure
    shouHeader();
    showNotes(arrMenSrtuct, arrNewMenStruct, sizeArr, 0);

    int maxByteStruct = 36; // size sructure in byte
    int maxArr = maxByteStruct * sizeArr; // size array structure
    char arrMenByte[maxArr]; //create new arr for srtructure

    packByte(arrMenSrtuct, sizeArr, maxByteStruct, maxArr, arrMenByte); // pack array structure in array char
    showArrMenByte(arrMenByte, maxArr, maxByteStruct, sizeArr);

    unpack(arrNewMenStruct, sizeArr, maxByteStruct, maxArr, arrMenByte);
    shouHeader();
    showNotes(arrMenSrtuct, arrNewMenStruct, sizeArr, 0);

    return 0;

}
