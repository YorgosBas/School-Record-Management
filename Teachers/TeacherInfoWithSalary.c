#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    char lastName[30];
    double money;
    int hours;
    double miktes_apodoxes;//gross income
    double kratiseis;//deductions
    double tax;
    double kathares_apodoxes;//net income
}teachersT;

void get_data(int i,int n,teachersT teachers[]);
void calc_salaries(int i,teachersT teachers[]);
void print_data(int n,teachersT teachers[]);

int main(){
    int n,i;
    printf("Professors working in school number: ");
    scanf("%d",&n);
    teachersT teachers[n];
    for(i=0;i<n;i++)get_data(i,n,teachers);
    for(i=0;i<n;i++)calc_salaries(i,teachers);
    print_data(n,teachers);
    return 0;
}

void get_data(int i,int n,teachersT teachers[]){
    printf("\nInformation about Professor %d\n",i);
    printf("First name: ");
    gets(teachers[i].name);
    printf("Last name: ");
    gets(teachers[i].lastName);
    printf("Salary per hour: ");
    scanf("%g",&teachers[i].money);
    printf("Total work hour: ");
    scanf("%d",&teachers[i].hours);
}

void calc_salaries(int i,teachersT teachers[]){
    teachers[i].miktes_apodoxes=teachers[i].money*teachers[i].hours;
    teachers[i].kratiseis=teachers[i].miktes_apodoxes*15/100;
    teachers[i].tax=(teachers[i].miktes_apodoxes-teachers[i].kratiseis)*7/100;
    teachers[i].kathares_apodoxes=teachers[i].miktes_apodoxes-teachers[i].tax-teachers[i].kratiseis;
}

void print_data(int n,teachersT teachers[]){
    int i;
    printf("\n");
    printf("%-10s %-10s %-15s %-18s %-8s %-14s %-8s %-8s\n","Name","Surname","Hourly Rate","Hours worked","Gross","Deductions","Tax","Net");
    for(i=0;i<45;i++) printf("--");
    printf("\n");
    for(i=0;i<n;i++){
        printf("%-10s %-10s %-15.2f %-18d %-8.2f %-14.2f %-8.2f %-8.2f\n",teachers[i].name,teachers[i].lastName,teachers[i].money,
        teachers[i].hours,teachers[i].miktes_apodoxes,teachers[i].kratiseis,teachers[i].tax,teachers[i].kathares_apodoxes);
    }
    for(i=0;i<45;i++) printf("--");
    printf("\n");
}
