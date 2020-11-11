#include"Members.h"
char username[50];
char password[50];
void init_admin()
{
    FILE *fp = fopen("Admin.txt","r"); 
    int i=0;
    char ch = fgetc(fp);
    while(ch!=EOF)
    {
        if(ch==' ')
            break;
        username[i++] = ch;
        ch = fgetc(fp);
    }
    username[i] = '\0';
    i = 0;
    ch = fgetc(fp);
    while(ch!=EOF)
    {
        password[i++] = ch;
        ch = fgetc(fp);
    }
    password[i] = '\0';
}
int admin_login(char u[],char p[])
{
    if(strcmp(u,username)==0&&strcmp(p,password)==0)
    {
        return 1;
    }
    return 0;
}
void AdminControl()
{
    int choice=1;
    while(choice!=7)
    {
        printf("\nAdmin Menu\n");
        printf("1. Book Database\n");
        printf("2. Member Database\n");
        printf("3. Add a book\n");
        printf("4. Remove a book\n");
        printf("5. Add a member\n");
        printf("6. Remove a member\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: show_all();
                    break;
            case 2: show_members();
                    break;
            case 3: printf("\nEnter id: ");
                    int id,year,qty;
                    fflush(stdin);
                    scanf("%d",&id);
                    printf("Enter name: ");
                    char name[50],author[50],faction[50];
                    fflush(stdin);
                    gets(name);
                    printf("Enter author: ");
                    fflush(stdin);
                    gets(author);
                    printf("Enter faction: ");
                    fflush(stdin);
                    gets(faction);
                    printf("Enter price: ");
                    float price;
                    fflush(stdin);
                    scanf("%f",&price);
                    printf("Enter publication year: ");
                    fflush(stdin);
                    scanf("%d",&year);
                    printf("Enter quantity: ");
                    fflush(stdin);
                    scanf("%d",&qty);
                    add_book(id,name,author,faction,price,year,qty);
                    break;
            case 4: printf("\nEnter id to remove: ");
                    scanf("%d",&id);
                    remove_book(id);
                    break;
            case 5: printf("\nEnter your registration number: ");
                    long int reg;
                    unsigned long long int mob;
                    char pass[50];
                    scanf("%ld",&reg);
                    fflush(stdin);
                    printf("Enter your name: ");
                    gets(name);
                    fflush(stdin);
                    printf("Enter your password: ");
                    gets(pass);
                    fflush(stdin);
                    printf("Enter your mobile number: ");
                    scanf("%llu",&mob);
                    Signup(reg,name,pass,mob);
                    break;
            case 6: printf("Enter registration number to delete: ");
                    scanf("%ld",&reg);
                    remove_member(reg);
                    break;
        }
    } 
}
int main()
{
    initialize_books();
    initalize_members();
    init_admin();
    char x[50],y[50];
    printf("Enter username: ");
    fflush(stdin);
    gets(x);
    printf("Enter password: ");
    fflush(stdin);
    gets(y);
    int result = admin_login(x,y);
    if(result==1)
    {
        AdminControl();
    }
    else
    {
        printf("\nWrong Credentials!\n");
    }
    return 0;
}