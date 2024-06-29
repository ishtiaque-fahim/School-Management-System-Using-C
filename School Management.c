#include <stdio.h>
#include <conio.h>
#include <time.h>

struct student {
char name[50];
char sec[10];
int roll ;
char date[10];
}s;
FILE *fp;
long sz = sizeof(s);
int main(){
int ch ;
while(1){
    system("cls");
    printf("<---- School Management System ---->\n");
    printf("1. Take Admission\n");
    printf("2. Student Info\n");
    printf("3. Search\n");
    printf("4. Modify\n");
    printf("5. Delete\n");
    printf("6. Sort by Roll\n");
    printf("0. Exit\n\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch){
    case 0 :exit(0);
    case 1 :input();
    break ;
    case 2 :display();
    break ;
    case 3 : search();
    break ;
    case 4 : Modify ();
    break ;
    case 5 : Delete();
    break ;
    case 6 : sort();
    break ;
    }
    printf("Press any key to continue\n");
    getch();
}
return 0 ;
}
void input(){
char mydate[10];
time_t t = time(NULL);
struct tm tm =*localtime(&t);
sprintf(mydate, "%02d/%02d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
strcpy(s.date,mydate);
fp = fopen("student.txt","ab");
    printf("Enter your name\n");
    fflush(stdin);
    gets(s.name);

printf("Enter your sec\n");
    fflush(stdin);
    gets(s.sec);
    printf("Enter your roll\n");
    scanf("%d",&s.roll);
    fwrite(&s,sz,1,fp);
    printf("Record Saved Successfully...");
    fclose(fp);
}
void display(){
system("cls");
printf("<---- Student Info ---->\n\n");
printf("%-30s %-20s %-10s %s\n", "Name", "Sec","Roll", "Date");
fp = fopen("student.txt","rb");
while(fread(&s,sz,1,fp)== 1){
    printf("%-30s %-20s %-10d %s\n", s.name, s.sec, s.roll, s.date);
}
fclose(fp);
}
void search(){
int ch ;
while(1){
    system("cls");
    printf("<---- Search ---- >\n");
    printf("1. Search By Roll\n");
    printf("2. Search By Name\n");
    printf("0. Back To Main Menu\n");
    printf("\n\n Enter Your Choice : ");
    scanf("%d",&ch);
    switch(ch){
    case 0: main();
    break ;
    case 1 : searchbyRoll();
    break ;
    case 2 : searchbyname ();
    break ;
    default : printf("Invalid Choice");
    }
    getch();
 }

}
void searchbyRoll(){
int roll ,f =0;
printf("Enter Roll : \n");
scanf("%d",&roll);
printf("%-30s %-20s %-10s %s\n", "Name", "Sec","Roll", "Date");
fp = fopen("student.txt","rb");
while(fread(&s,sz,1,fp)== 1){
        if(roll == s.roll){
            f=1;
            printf("%-30s %-20s %-10d %s\n", s.name, s.sec, s.roll, s.date);
            break ;
        }

}
fclose(fp);
if(f==0){
printf("Record Not Found\n");}
else
    {printf("Record Found\n");}
}
void searchbyname(){
char name[30] ;
int f =0;
printf("Enter Name : \n");
fflush(stdin);
gets(name);
printf("%-30s %-20s %-10s %s\n", "Name", "Sec","Roll", "Date");
fp = fopen("student.txt","rb");
while(fread(&s,sz,1,fp)== 1){
        if(strcmpi(name,s.name)== 0){
            f=1;
            printf("%-30s %-20s %-10d %s\n", s.name, s.sec, s.roll, s.date);
            break ;
        }

}
fclose(fp);
if(f==0){
printf("Record Not Found\n");}
else
    {printf("Record Found\n");}
}
void Modify(){

int roll ,f =0;
printf("Enter Roll To Modify : \n");
scanf("%d",&roll);
fp = fopen("student.txt","rb+");
while(fread(&s,sz,1,fp)== 1){
        if(roll == s.roll){
            f=1;
            printf("Enter new name\n");
    fflush(stdin);
    gets(s.name);

printf("Enter new sec\n");
    fflush(stdin);
    gets(s.sec);
    printf("Enter new roll\n");
    scanf("%d",&s.roll);
    fseek(fp,-sz,1);
    fwrite(&s,sz,1,fp);
    fclose(fp);
    break ;
        }

}
if(f==0){
printf("Record Not Found\n");}
else
    {printf("Record Modified Successfully\n");}

}

void Delete(){
int roll ,f =0;
printf("Enter Roll To Delete : \n");
scanf("%d",&roll);
FILE *ft;
fp = fopen("student.txt","rb");
ft = fopen("temp.txt","ab");
while(fread(&s,sz,1,fp)== 1){
       if(roll == s.roll)
        f = 1 ;
       else
        fwrite(&s,sz,1,ft);

}
fclose(fp);
fclose(ft);
remove("student.txt");
rename("temp.txt","student.txt");
if(f==0){
printf("Record Not Found\n");}
else
    {printf("Record Deleted Successfully\n");}

}
void sort(){
    int c = 0 , i ,j ;
    struct student s1[50],t;
system("cls");
printf("<---- Student Info ---->\n\n");
printf("%-30s %-20s %-10s %s\n", "Name", "Sec","Roll", "Date");
fp = fopen("student.txt","rb");
while(fread(&s,sz,1,fp)== 1){
    s1[c++]= s;
}
for (i = 0 ; i< c-1; i++){
    for(j = i+1 ; j<c; j++){
        if(s1[i].roll > s1[j].roll){
            t = s1[i];
            s1[i]= s1[j];
            s1[j]= t;
        }
    }
}
for(i = 0 ; i<c ; i++)
      printf("%-30s %-20s %-10d %s\n", s1[i].name, s1[i].sec, s1[i].roll, s1[i].date);
fclose(fp);

}


























