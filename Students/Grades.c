#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 100

typedef struct{
    char firstname[15];
    char lastname[25];
    float grades[6];
    char sex;
    float average;
}studentT;

void readInput(FILE* infile,studentT students[],int *psuccessMales,int *psuccessFemales,float *perMales,float *perFemales);
void writeOutput(FILE* outfile,studentT students[],int successMales,float perMales,int successFemales,float perFemales);

int main(){
    char inputFilename[30];
    char outputFilename[30];
    FILE* infile;
    FILE* outfile;
    studentT students[100];
    int successMales,successFemales;
    float males,females;

    while(true){
        printf("Give name of input file:");
        gets(inputFilename);
        infile = fopen(inputFilename,"r");
        if(infile!=NULL)break;
        printf("Cannot open input file %s. Try again. \n");
    }
    printf("Give name of output file:");
    gets(outputFilename);
    outfile = fopen(outputFilename,"w");

    readInput(infile,students,&successMales,&successFemales,&males,&females);
    writeOutput(outfile,students,successMales,males,successFemales,females);

    fclose(infile);
    fclose(outfile);

    return 0;
}
void readInput(FILE* infile,studentT students[],int *psuccessMales,int *psuccessFemales,float *perMales,float *perFemales){
    char firstname[15],lastname[25],sex,termch;
    float grades[6],average;
    int nscan,i,index;
    *psuccessMales=0;
    *psuccessFemales=0;
    int sumMales = 0;
    int sumFemales = 0;

    while(true){
        nscan = fscanf(infile,"%15[^,], %25[^,], %f, %f, %f, %f, %f, %f, %c%c",firstname,lastname,&grades[0],&grades[1],&grades[2],&grades[3],&grades[4],&grades[5],&sex,&termch);
        if(nscan == EOF)break;
        if(nscan !=10 || termch != '\n'){
            printf("ERROR");
            exit(1);
        }
        average = 0;
        for(i=0; i<6; i++){
            average += grades[i];
        }
        average /= 6;

        if(average >= 10){
            index = *psuccessMales + *psuccessFemales;
            strcpy(students[index].firstname,firstname);
            strcpy(students[index].lastname,lastname);
            students[index].sex = sex;
            students[index].average = average;
            students[index].grades[0] = grades[0];
            students[index].grades[1] = grades[1];
            students[index].grades[2] = grades[2];
            students[index].grades[3] = grades[3];
            students[index].grades[4] = grades[4];
            students[index].grades[5] = grades[5];
            if(sex == 'A')(*psuccessMales)++;
            else (*psuccessFemales)++;
        }
        if(sex == 'A')sumMales++;
        else sumFemales++;

    }
    *perMales = ((float)(*psuccessMales) / sumMales) * 100;
    *perFemales = ((float)(*psuccessFemales) / sumFemales) * 100;
}

void writeOutput(FILE* outfile,studentT students[],int successMales,float perMales,int successFemales,float perFemales){
    int i;
    fprintf(outfile,"%-22s %-12s %-22s %-12s\n","Female succeeded","percentage","male succeeded","percentage");
    fprintf(outfile,"%-22d %-12.1f %-12d %-12.1f\n",successFemales,perFemales,successMales,perMales);
    for(i=0; i<=75; i++)fputc('-',outfile);
    fputc('\n',outfile);
    for(i=0; i<((successMales)+(successFemales));i++){
        fprintf(outfile,"%-15s %-15s %4.1f %4.1f %4.1f %4.1f %4.1f %4.1f %4.1f %c\n",students[i].firstname,students[i].lastname,students[i].grades[0],students[i].grades[1],students[i].grades[2],students[i].grades[3],students[i].grades[4],students[i].grades[5],students[i].average,students[i].sex);
    }

}

