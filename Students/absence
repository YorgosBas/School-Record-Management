#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define M 100

typedef struct{
    char name[30];
    int apousies;
}studentT;

void readInput(FILE* infile,studentT students[],int * pApousies,int *pStudents);
void writeOutput(FILE* outfile,int size,studentT students[],int total);

int main(){
    char inputFilename[30];
    char outputFilename[30];
    FILE* infile;
    FILE* outfile;
    studentT students[M];
    int numberOfStudents,numberOfApousies;

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

    readInput(infile,students,&numberOfApousies,&numberOfStudents);
    writeOutput(outfile,numberOfApousies,students,numberOfStudents);
    fclose(infile);
    fclose(outfile);
    return 0;
}

void readInput(FILE* infile,studentT students[],int * pApousies,int *pStudents){
    char name[30],comments[68],termch;
    int apousies,nscan,line;
    line = 0;
    *pApousies = 0;
    *pStudents = 0;

    while(true){
        nscan = fscanf(infile,"%30[^,], %d, %68[^\n]%c",name,&apousies,comments,&termch);
        if(nscan == EOF)break;
        line++;
        if(nscan != 4 || termch != '\n'){
            printf("Error in line %d.Program termination.\n",line);
            exit(1);
        }
        if(apousies > 100){
            strcpy(students[*pApousies].name,name);
            students[*pApousies].apousies = apousies;
            (*pApousies)++;
        }
        (*pStudents)++;
    }
}

void writeOutput(FILE* outfile,int size,studentT students[],int total){
    int i;
    fprintf(outfile,"%-30s%-9s\n","NAME","ABSENCE");
    for(i=1; i<=39; i++)fputc('-',outfile);
    fputc('\n',outfile);
    for(i=0; i<size; i++)fprintf(outfile,"%-30s%9d\n",students[i].name,students[i].apousies);
    for(i=1; i<size; i++)fputc('-',outfile);
    fputc('\n',outfile);
    fprintf(outfile,"%-30s%9d\n","STUDENTS:",total);
    fprintf(outfile,"%-30s%9d\n","FAILED:",size);
}
