#include"Members.h"
void LibraryMenu()
{
    printf("\n************************Welcome to Fairy Library*****************\n");
    printf("1 Login\n");
    printf("2 Exit\n");
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
                    }
                
                } while (op!=5);
                
            }
        }
    }while(option==1);
    close_books();
    close_member();
    
}