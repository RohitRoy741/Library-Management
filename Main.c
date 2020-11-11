#include"Members.h"
void LibraryMenu()
{
    printf("\n************************Welcome to Fairy Library*****************\n");
    printf("1. Login\n");
    printf("2. Signup\n");
    printf("3. Exit\n");
}
int main()
{
    initialize_books();
    initalize_members();
    int option = 1;
    do
    {
        LibraryMenu();
        printf("Enter your option: ");
        fflush(stdin);
        scanf("%d",&option);
        fflush(stdin);
        if(option==1)
        {
            long int reg;
            char password[50];
            printf("Enter your Registration Number: ");
            scanf("%ld",&reg);
            fflush(stdin);
            printf("Enter your password: ");
            scanf("%s",password);
            fflush(stdin);
            int index = login(reg,password);
            if(index==-1)
            {
                printf("\nWrong Credentials\n");
            }
            else
            {
                printf("\nHello %s, Fairy Library welcomes you!\n",m[index].name);
                int op;
                do
                {
                    MemberMenu();
                    scanf("%d",&op);
                    fflush(stdin);
                    switch(op)
                    {
                        case 1: show_all();
                                break;
                        case 2: print_member(index);
                                break;
                        case 3: printf("\nEnter the name of book: ");
                                char name[50];
                                gets(name);
                                issue_member(index,name);
                                break;
                        case 4: printf("\nEnter the name of the book: ");
                                gets(name);
                                return_member(index,name);
                                break;
                        case 5: ChangePassword(index);
                                break;
                    }
                
                } while (op!=6);
                
            }
        }
        else if(option==2)
        {
            long int reg;
            unsigned long long int mob;
            char name[50],password[50];
            printf("\nEnter your registration number: ");
            scanf("%ld",&reg);
            fflush(stdin);
            printf("Enter your name: ");
            gets(name);
            fflush(stdin);
            printf("Enter your password: ");
            gets(password);
            fflush(stdin);
            printf("Enter your mobile number: ");
            scanf("%llu",&mob);
            Signup(reg,name,password,mob);
            initalize_members();

        }
    }while(option!=3);
    close_books();
    close_member();
}