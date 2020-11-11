#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 10000
#define hr for(int x=0;x<137;x++) printf("-");
typedef struct book
{
    int id;
    char name[50];
    char author[50];
    float price;
    int publication_year;
    char faction[50];
}Book;
Book books[MAX_SIZE];
int quantity[MAX_SIZE];
int number_of_books = 0;
void show_all()
{
    printf("\n");
    hr
    printf("\n");
    printf("| %-10s|","ID");
    printf("| %-50s|","Name");
    printf("| %-20s|","Author");
    printf("| %-20s|","Faction");
    printf("| %-10s|","Year");
    printf("| %-10s|","Quantity");
    for(int i=0;i<number_of_books;i++)
    {
        printf("\n");
        hr
        printf("\n");
        printf("| %-10d|",books[i].id);
        printf("| %-50s|",books[i].name);
        printf("| %-20s|",books[i].author);
        printf("| %-20s|",books[i].faction);
        printf("| %-10d|",books[i].publication_year);
        printf("| %-10d|",quantity[i]);
    }
    printf("\n");
    hr
    printf("\n");
}
void add_book(int id, char name[50],char author[50],char faction[50],float price,int publication_year,int qty)
{
    books[number_of_books].id = id;
    strcpy(books[number_of_books].name,name);
    strcpy(books[number_of_books].author,author);
    strcpy(books[number_of_books].faction,faction);
    books[number_of_books].price = price;
    books[number_of_books].publication_year = publication_year;
    quantity[number_of_books] = qty;
    number_of_books++;
}
void initialize_books()
{
    FILE *fp = fopen("books.txt","r");
    if(fp==NULL)
    {
        printf("\nError\n");
    }
    char line[256];
    char ch = fgetc(fp);
    int i=0;
    int id,year,qty;
    char name[50],author[50],faction[50];
    float price;
    while(ch!=EOF)
    {
        if(ch!='\n')
        {
            line[i++] = ch;
        }    
        else
        {
            line[i] = '\0';
            //printf("\n%s\n",line);
            int number_of_tokens = 1;
            char delim[] = ",";
            char token[50];
            strcpy(token,strtok(line,delim));
            id = atoi(token);
            strcpy(token,strtok(NULL,delim));
            strcpy(name,token);
            strcpy(token,strtok(NULL,delim));
            strcpy(author,token);     
            strcpy(token,strtok(NULL,delim));
            strcpy(faction,token);
            strcpy(token,strtok(NULL,delim));
            price = atof(token);
            strcpy(token,strtok(NULL,delim));
            year= atoi(token);
            strcpy(token,strtok(NULL,delim));
            qty = atoi(token);
            add_book(id,name,author,faction,price,year,qty);
            strcpy(line,"");
            i=0;       
        }
        ch = fgetc(fp);
    }
    fclose(fp);
}
int search(char name[])
{
    for(int i=0;i<number_of_books;i++)
    {
        if(strcmp(books[i].name,name)==0)
        {
            return i;
        }
    }
    return -1;
}
int search_id(int id)
{
    for(int i=0;i<number_of_books;i++)
    {
        if(books[i].id==id)
            return i;
    }
    return -1;
}
int issue_book(char name[])
{
    int index = search(name);
    if(index==-1)
    {
        printf("\nBOOK IS NOT IN DATABASE!!!\n");
        return -1;
    }
    if(quantity[index]==0)
        printf("\nBook is currently out of stock.\nSorry for incovenience.\n");
    else
    {
        quantity[index]--;
        printf("\nBook issued from databse.");
        printf("\nPlease collect your book from counter\n");
        return index;
    }
    return -1;
}
void return_book(char name[])
{
    int index = search(name);
    if(index==-1)
    {
        printf("\nInvalid Name!\n");
        return;
    }
    quantity[index]++;
    printf("\nBook Successfully Returned!\n");
    printf("Thank You for using pur library.\n");
}
int get_quantity(char name[])
{
    int index = search(name);
    if(index!=-1)
        return quantity[index];
    else
        return 0;
}
void close_books()
{
    FILE *fp = fopen("books.txt","w");
    for(int i=0;i<number_of_books;i++)
    {
        fprintf(fp,"%d,%s,%s,%s,%.2f,%d,%d\n",books[i].id,books[i].name,books[i].author,books[i].faction,books[i].price,books[i].publication_year,quantity[i]);
    }
    fprintf(fp,"%s","END");
    fclose(fp);
}
void print_book(int index)
{
    index = search_id(index);
    for(int i=0;i<43;i++)
        printf("-");
    printf("\n");
    printf("|%-15s|%-30s|","Name",books[index].name);
    printf("\n");
    for(int i=0;i<43;i++)
        printf("-");
    printf("\n");
}
void remove_book(int id)
{
    int index = search_id(id);
    if(index==-1)
    {
        return;
    }
    for(int i=index;i<number_of_books;i++)
    {
        books[i] = books[i+1];
    }
    number_of_books--;
    close_books();
}