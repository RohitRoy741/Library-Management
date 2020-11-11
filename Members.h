#include "books.h"
#include<time.h>
#define hr1 for(int i=0;i<92;i++) printf("-");
typedef struct member
{
    char password[50];
    long int registration_number;
    char name[50];
    unsigned long long int mobile;
    Book book_issued[3];
    int current;
}Member;
Member m[MAX_SIZE];
int number_of_members = 0;
void add_member(char password[],long int registration_number,char name[],unsigned long long int mobile,int current,int id1,int id2,int id3)
{
    strcpy(m[number_of_members].password,password);
    m[number_of_members].registration_number = registration_number;
    m[number_of_members].mobile = mobile;
    m[number_of_members].current = current;
    strcpy(m[number_of_members].name,name);
    int member_book = 0;
    int index = search_id(id1);
    if(index!=-1)
    {
        m[number_of_members].book_issued[member_book++] = books[index];
    }
    index = search_id(id2);
    if(index!=-1)
    {
        m[number_of_members].book_issued[member_book++] = books[index];
    }
    index = search_id(id3);
    if(index!=-1)
    {
        m[number_of_members].book_issued[member_book++] = books[index];
    }
    number_of_members++;
    char filename[50];
    sprintf(filename,"%ld",registration_number);
    strcat(filename,".txt");
    FILE *fp = fopen(filename,"r");
    if(fp==NULL)
    {
        fp = fopen(filename,"w");
        fclose(fp);
    }
    else
        fclose(fp);
}
void initalize_members()
{
    FILE *fp = fopen("Members.txt","r");
    char id[50],password[50],name[50],mobile[50],current[3],id1[3],id2[3],id3[3];
    char ch = fgetc(fp);
    char line[256];
    int i=0;
    while(ch!=EOF)
    {
        if(ch!='\n')
            line[i++] = ch;
        else
        {
            line[i]='\0';
            char delim[] = ",";
            strcpy(id,strtok(line,delim));
            long int reg = atol(id);
            strcpy(password,strtok(NULL,delim));
            strcpy(name,strtok(NULL,delim));
            strcpy(mobile,strtok(NULL,delim));
            unsigned long long int mob = strtoull(mobile,NULL,10);
            strcpy(current,strtok(NULL,delim));
            int curr = atoi(current);
            int a,b,c;
            strcpy(id1,strtok(NULL,delim));
            strcpy(id2,strtok(NULL,delim));
            strcpy(id3,strtok(NULL,delim));
            a = atoi(id1);
            b = atoi(id2);
            c = atoi(id3);
            add_member(password,reg,name,mob,curr,a,b,c);
            strcpy(line,"");
            i=0;
        }
        ch = fgetc(fp); 
    }
}
void show_members()
{
    printf("\n");
    hr1
    printf("\n");
    printf("| %-30s|","Registration Number");
    printf("| %-20s|","Name");
    printf("| %-15s|","Mobile");
    printf("| %-15s|","Books Issued");
    printf("\n");
    hr1
    printf("\n");
    for(int i=0;i<number_of_members;i++)
    {
        printf("| %-30d|",m[i].registration_number);
        printf("| %-20s|",m[i].name);
        printf("| %-15llu|",m[i].mobile);
        printf("| %-15d|",m[i].current);
        printf("\n");
        hr1
        printf("\n");
    }
}
int login(long int reg,char password[])
{
    for(int i=0;i<number_of_members;i++)
    {
        if(m[i].registration_number==reg)
        {
            if(strcmp(m[i].password,password)==0)
                return i;
            else
                return -1;
            break;
        }
    }
    return -1;
}
void MemberMenu()
{
    printf("\nWelcome to Fairy Library\n");
    printf("\n1. Show Library Database");
    printf("\n2. Check your records");
    printf("\n3. Issue a book");
    printf("\n4. Return a book");
    printf("\n5. Change Password");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
}
void print_member(int i)
{
    printf("\n");
    hr1
    printf("\n");
    printf("| %-30s|","Registration Number");
    printf("| %-20s|","Name");
    printf("| %-15s|","Mobile");
    printf("| %-15s|","Books Issued");
    printf("\n");
    hr1
    printf("\n");
    printf("| %-30d|",m[i].registration_number);
    printf("| %-20s|",m[i].name);
    printf("| %-15llu|",m[i].mobile);
    printf("| %-15d|",m[i].current);
    printf("\n");
    hr1
    printf("\n");
    for(int j=0;j<m[i].current;j++)
    {
        print_book(m[i].book_issued[j].id);
    }
}
void issue_member(int index,char name[])
{
    if(m[index].current==3)
    {
        printf("\nYou already have 3 books issued!");
    }
    else
    {
        int i = issue_book(name);
        int x = m[index].current;
        m[index].book_issued[x] = books[i];
        m[index].current++;
        //printf("\n%d\n",m[i].current);
        FILE *fp;
        time_t t;
        time(&t);
        char filename[50];
        sprintf(filename,"%ld",m[index].registration_number);
        strcat(filename,".txt");
        fp = fopen(filename,"a");
        fprintf(fp,"\n**********************************\n");
        fprintf(fp,"\nBook Issued On %s\n",ctime(&t));
        fprintf(fp,"\nBook details:\n");
        fprintf(fp,"\nID: %d\n",books[i].id);
        fprintf(fp,"\nName: %s\n",books[i].name);
        fprintf(fp,"\n**********************************\n");
    }
}
void return_member(int index,char name[])
{
    for(int i=0;i<3;i++)
    {
        if(strcmp(m[index].book_issued[i].name,name)==0)
        {
            FILE *fp;
            time_t t;
            time(&t);
            char filename[50];
            sprintf(filename,"%ld",m[index].registration_number);
            strcat(filename,".txt");
            fp = fopen(filename,"a");
            fprintf(fp,"\n**********************************\n");
            fprintf(fp,"\nBook Returned On %s\n",ctime(&t));
            fprintf(fp,"\nBook details:\n");
            fprintf(fp,"\nID: %d\n",m[index].book_issued[i].id);
            fprintf(fp,"\nName: %s\n",m[index].book_issued[i].name);
            fprintf(fp,"\n**********************************\n");
            m[index].book_issued[i].id = -1;
            m[index].book_issued[i].price = -1;
            m[index].book_issued[i].publication_year = -1;
            strcpy(m[index].book_issued[i].name,"");
            strcpy(m[index].book_issued[i].faction,"");
            strcpy(m[index].book_issued[i].name,"");
            return_book(name);
            m[index].current--;
        }
    }
}
void close_member()
{
    FILE *fp = fopen("Members.txt","w");
    for(int i=0;i<number_of_members;i++)
    {
        int p[3]={-1,-1,-1};
        for(int j=0;j<m[i].current;j++)
            p[j] = m[i].book_issued[j].id;
        fprintf(fp,"%d,%s,%s,%llu,%d,%d,%d,%d\n",m[i].registration_number,m[i].password,m[i].name,m[i].mobile,m[i].current,p[0],p[1],p[2]);
    } 
    fprintf(fp,"END");
    fclose(fp);
}
void Signup(long int reg,char name[],char password[],unsigned long long mobile)
{
    m[number_of_members].registration_number = reg;
    m[number_of_members].mobile = mobile;
    strcpy(m[number_of_members].name,name);
    strcpy(m[number_of_members].password,password);
    m[number_of_members].current = 0;
    number_of_members++;
    close_member();
    printf("\nHello %s, please login to continue\n",name);
}  
void ChangePassword(int index)
{
    printf("\nEnter your old password: ");
    char password[50];
    fflush(stdin);
    gets(password);
    if(strcmp(password,m[index].password)==0)
    {
        printf("Enter new password: ");
        gets(password);
        strcpy(m[index].password,password);
        printf("\nPassword Changed\n");
    }
    printf("\nWrong Password\n");
} 
void remove_member(int reg)
{
    for(int i=0;i<number_of_members;i++)
    {
        if(m[i].registration_number==reg)
        {
            for(int j=i;j<number_of_members;j++)
            {
                m[j] = m[j+1];
            }
            number_of_members--;
            close_member();
            break;
        }
    }
}