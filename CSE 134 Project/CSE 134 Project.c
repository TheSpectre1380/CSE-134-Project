#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void login()
{
    int a=0,i=0;
    char uname[10],temp=' ';
    char pass_in[10];

    do
    {
        printf("\033[1;11m");
        printf("\t\t\t\t   Login\n");
        printf("\t\t\t\t   ---------------------------------------------\n\n");

        printf("\t\t\t\t   Username:-");
        scanf("%s", &uname);
        fflush(stdin);
        printf("\n\t\t\t\t   Password:-");
        while(i<10)
        {
            pass_in[i]=getch();
            temp=pass_in[i];
            if(temp=='\r')
                break;
            else
                printf("*");
            i++;
        }
        pass_in[i]='\0';
        i=0;

        if(strcmp(uname,"user")==0 && strcmp(pass_in,"pass")==0)
        {
            system("cls");
            printf("\033[0;32m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t         LOGIN SUCCESSFUL!");
            printf("\n\n\t\t\t\t\t    Press any key to continue...\n\n\n\n");
            printf("\033[0;11m");
            getch();
            break;
        }
        else
        {
            system("cls");
            printf("\033[0;31m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       LOGIN UNSUCCESSFUL!\n\n\n\n");
            a++;
            getch();
            system("cls");
            printf("\033[0;11m");
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   ++                                         ++\n");
            printf("\t\t\t\t   ++               Star Cineplex             ++\n");
            printf("\t\t\t\t   ++                                         ++\n");
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        }
    }
    while(a<=2);
    if (a>2)
    {

        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Forgot Password? Try Again!\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
        main();

    }
    system("cls");
}



struct book
{
    char code[20];
    char name[20];
    char cost[20];
} b;
struct book2
{
    char code2[20];
    char date[20];
    char month[20];
    char time[20];
} c;

void add_cost()
{

    FILE *fp;
    struct book b;
    printf("\nEnter Movie Code :- ");
    scanf("%s",b.code);
    fflush(stdin);
    printf("Enter Movie Name :- ");
    scanf("%[^\n]s",b.name);
    printf("Enter Ticket Price:- ");
    scanf("%s",&b.cost);

    fp=fopen("cost.txt","a");

    if(fp == NULL)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       File Not Found !\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
    }
    else
    {
        fprintf(fp,"Movie Code: %s     Movie Name: %s     Ticket Price: %sTk \n",b.code,b.name,b.cost);
        system("cls");
        printf("\033[0;32m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t      Recorded Successfully!\n\n\n\n");
        printf("\033[0;11m");
    }
    fclose(fp);
    getch();
    system("cls");
}

void add_showtime()
{

    FILE *fp;
    struct book b;
    printf("\nEnter Movie Code :- ");
    scanf("%s",c.code2);
    fflush(stdin);
    printf("Enter Movie Name :- ");
    scanf("%[^\n]s",b.name);
    fflush(stdin);
    printf("Enter Release Date:- ");
    scanf("%[^\n]s",c.date);
    printf("Enter Show Time:- ");
    scanf("%s",&c.time);

    fp=fopen("time.txt","a");

    if(fp == NULL)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       File Not Found !\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
    }
    else
    {
        fprintf(fp,"Movie Code: %s     Movie Name: %s     Release Date: %s     Show Time: %s \n",c.code2,b.name,c.date,c.time);
        system("cls");
        printf("\033[0;32m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t      Recorded Successfully!\n\n\n\n");
        printf("\033[0;11m");
    }
    fclose(fp);
    getch();
    system("cls");
}

void viewCosta()
{

    char ch;
    FILE *fp;

    fp = fopen("cost.txt","r");
    if(fp == NULL)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       File Not Found !\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++               Star Cineplex             ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        admin();
    }
    else
    {
        system("cls");
        printf("\n");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);

    }

    fclose(fp);
    getch();
    system("cls");
}

void view_showtimea()
{

    char ch;
    FILE *fp;

    fp = fopen("time.txt","r");
    if(fp == NULL)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       File Not Found !\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++               Star Cineplex             ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        admin();
    }
    else
    {
        system("cls");
        printf("\n");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);
    }

    fclose(fp);
    getch();
    system("cls");

}
void delete_details()
{
    FILE *fileptr1, *fileptr2;
    char filename[40];
    char c;
    int delete_line, temp = 1;

    printf("\nEnter File Name: ");
    scanf("%s", filename);
    printf("\n");
    fileptr1 = fopen(filename, "r");
    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }
    rewind(fileptr1);
    printf(" \n Enter Movie Code To Be Deleted:  ");
    scanf("%d", &delete_line);
    fileptr2 = fopen("replica.txt", "w");
    c = 'A';
    while ((c = getc(fileptr1)) != EOF)
    {
        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        if (c == '\n')
        {
            temp++;
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    rename("replica.txt", filename);
    printf("\n Edited Movie List:\n\n");
    fileptr1 = fopen(filename, "r");
    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }
    fclose(fileptr1);
    getch();
    system("cls");
}

void admin()
{
    login();
    int ch,i;
    do
    {
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++               Star Cineplex             ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\t\t\t\t   ---------------------------------------------");
        printf("\n\t\t\t\t   Enter >1< To Add Movie and Cost");
        printf("\n\t\t\t\t   Enter >2< To Add Show Time");
        printf("\n\t\t\t\t   Enter >3< To View Movie Details");
        printf("\n\t\t\t\t   Enter >4< To View Movie Schedules");
        printf("\n\t\t\t\t   Enter >5< To Delete Movies");
        printf("\n\t\t\t\t   Enter >6< To Logout");
        printf("\n\t\t\t\t   Enter >0< To Exit");
        printf("\n\t\t\t\t   ---------------------------------------------\n\n");
        printf("\n\t\t\t\t   Enter your Choice ::  ");
        fflush(stdin);
        scanf("%d",&ch);
        system("cls");

        switch (ch)
        {
        case 1 :
            add_cost();
            break;

        case 2:
            add_showtime();
            break;

        case 3:
            viewCosta();
            break;

        case 4:
            view_showtimea();
            break;

        case 5:
            delete_details();
            break;

        case 6:
            system("cls");
            printf("\033[0;32m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t         LOGOUT SUCCESSFUL!\n\n\n\n");
            printf("\033[0;11m");
            getch();
            system("cls");
            main();
            break;

        case 0:
            system("cls");
            printf("\033[0;31m");
            for(i=0; i<4; i++)
            {
                system("cls");
                Sleep(500);
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    The Program is Closing!\n\n\n\n");
                Sleep(500);
            }
            printf("\033[0;11m");
            exit(0);
            break;

        default:
            system("cls");
            printf("\033[0;31m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       Error! Wrong Input!\n\n\n\n");
            getch();
            system("cls");
            printf("\033[0;11m");
            break;
        }
    }
    while(ch!=0);
}

void viewCostc()
{

    char ch;
    FILE *fp;

    fp = fopen("cost.txt","r");
    if(fp == NULL)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       File Not Found !\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
        menu();
    }
    else
    {
        system("cls");
        printf("\n");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);

    }

    fclose(fp);
    getch();
    system("cls");
}

void view_showtimec()
{

    char ch;
    FILE *fp;

    fp = fopen("time.txt","r");
    if(fp == NULL)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       File Not Found !\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
        menu();
    }
    else
    {
        system("cls");
        printf("\n");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);
    }

    fclose(fp);
    getch();
    system("cls");

}

struct moviedetails
{
    char name[25];
    char phone[15];
    int seat;
    int id;
};
struct moviedetails person[300];

int logIn;
char password_c[10],username_c[20],firstName[20],lastName[20];
int count=0;
int id2=1000, choice;

void ticket1(int choice,char name[10],int id2)
{
    time_t t;
    time(&t);
    printf("\n\n");
    printf("\t------------------------STAR CINEPLEX-----------------------\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d\n",id2);
    printf("\t Customer  : %s\n",name);
    printf("\t Hall      : 01\n");
    printf("\t Seats No. : %d  \n",choice);
    printf("\t Purchase Time: %s", ctime(&t));
    person[count].id=id2;
    printf("\t============================================================\n\n\n\n\n");
    return;
}

void booking(int *array,int selection)
{
    int i,j;
book:
    printf("\n                                SCREEN\n");
    printf("\nThe Booked Tickets Are Marked As Asterisks (*).\n\n\n");
    for (i=1; i<=100; i++)
    {
        if (array[i]==0)
            printf("%d\t",i);
        else
            printf("*\t",i);
        if(i%10==0)
            printf("\n\n");
    }
    printf("Please enter your name: ");
    fflush(stdin);
    scanf("%[^\n]s",&person[count].name);
    printf("Please enter your phone number: ");
    scanf("%u",&person[count].phone);
    printf("Enter your preferred seat no: ");
    scanf("%d",&j);
    if (j>100)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t       This seat number is unavailable!\n");
        printf("\033[0;11m");
        printf("\n\t\t\t\t         Please re-enter seat number. \n\n\n\n");
        getch();
        system("cls");
        goto book;
    }

    if (array[j]==1)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t       Sorry, this ticket is already booked!\n");
        printf("\033[0;11m");
        printf("\n\t\t\t\t            Please choose another seat.\n\n\n\n");
        getch();
        system("cls");
        goto book;
    }
    else
        system("cls");
    array[j]=1;
    person[count].seat=j;
    if (selection==1)
        system("cls");
    ticket1(j,person[count].name,id2);
    getch();
    id2++;
}

void cancel(int *array)
{
    int Cseat,i,stop;
    printf("\nBooking ID: ");
    scanf("%d",&Cseat);
    for (i=0; i<300; i++)
    {
        if(Cseat==person[i].id)
        {
            stop=5;
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t         %s\n\n", person[i].name);
            printf("\033[0;32m");
            printf("\n\t\t\t\t\t         Your Ticket Has Been Canceled.\n\n\n\n");
            printf("\033[0;11m");
            getch();
            array[person[i].seat]=0;
            i=100;
        }
    }
    if (stop!=5)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t          Wrong Booking ID!\n\n\n\n");
        printf("\033[0;11m");
        getch();
        system("cls");
    }
}

void signup(void)

{
    printf("\033[1;11m");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   ++                                         ++\n");
    printf("\t\t\t\t   ++               Star Cineplex             ++\n");
    printf("\t\t\t\t   ++                                         ++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("\t\t\t\t   Sign Up\n");
    printf("\t\t\t\t   ---------------------------------------------\n\n");
    printf("\t\t\t\t   First name: ");
    scanf("%s",firstName);
    printf("\n\t\t\t\t   Last name: ");
    scanf("%s",lastName);
    printf("\n\t\t\t\t   User name: ");
    scanf("%s",username_c);
    printf("\n\t\t\t\t   Password: ");
    scanf("%s",password_c);
    system("cls");
    printf("\033[0;32m");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       SIGNUP SUCCESSFUL!\n\n\n\n");
    getch();
    system("cls");
    printf("\033[0;11m");
    customer();
}

void loginc()
{
    int a=0,i=0;
    char uname[10],temp=' ';
    char pass_in[10];

    do
    {
        printf("\033[1;11m");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++               Star Cineplex             ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\t\t\t\t   Login\n");
        printf("\t\t\t\t   ---------------------------------------------\n\n");
        printf("\t\t\t\t   Username:-");
        scanf("%s", &uname);
        fflush(stdin);
        printf("\n\t\t\t\t   Password:-");
        while(i<10)
        {
            pass_in[i]=getch();
            temp=pass_in[i];
            if(temp=='\r')
                break;
            else printf("*");
            i++;
        }
        pass_in[i]='\0';
        i=0;

        if((strcmp("user",uname) == 0 && strcmp("pass",pass_in)==0)||(strcmp(username_c,uname) == 0 && strcmp(password_c,pass_in)==0))
        {
            system("cls");
            printf("\033[0;32m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t         LOGIN SUCCESSFUL!");
            printf("\n\n\t\t\t\t\t    Press any key to continue...\n\n\n\n");
            printf("\033[0;11m");
            getch();
            break;
        }
        else
        {
            system("cls");
            printf("\033[0;31m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       LOGIN UNSUCCESSFUL!\n\n\n\n");
            a++;
            getch();
            system("cls");
            printf("\033[0;11m");

        }
    }
    while(a<=2);
    if (a>2)
    {
        system("cls");
        printf("\033[0;31m");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Forgot Password? Try Again!\n\n\n\n");
        getch();
        system("cls");
        printf("\033[0;11m");
        main();

    }
    system("cls");
}

void menu()
{
    loginc();
    int **seat,choice,selection,i;
    seat=(int **)calloc(101,sizeof(int *));
    for (i=0; i<1; i++)
        *(seat+i)=(int *)calloc(101,sizeof(int ));
    int ch;
    do
    {
        system("cls");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++               Star Cineplex             ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\t\t\t\t   ---------------------------------------------");
        printf("\n\t\t\t\t   Enter >1< Show Time");
        printf("\n\t\t\t\t   Enter >2< Ticket Price");
        printf("\n\t\t\t\t   Enter >3< Book Ticket");
        printf("\n\t\t\t\t   Enter >4< Cancel Tickets");
        printf("\n\t\t\t\t   Enter >5< Logout");
        printf("\n\t\t\t\t   Enter >0< Exit");
        printf("\n\t\t\t\t   ---------------------------------------------\n");
        printf("\n\t\t\t\t   Enter your Choice ::  ");
        fflush(stdin);
        scanf("%d",&ch);
        system("cls");

        switch (ch)
        {
        case 1 :
            view_showtimec();
            break;

        case 2:
            viewCostc();
            break;

        case 3:
            selection=1;
            booking(seat[selection-1],selection);
            count++;
            break;

        case 4 :
            selection=1;
            cancel(seat[selection-1]);
            break;

        case 5:
            customer();
            break;

        case 0:
            system("cls");
            printf("\033[0;31m");
            for(i=0; i<4; i++)
            {
                system("cls");
                Sleep(500);
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    The Program is Closing!\n\n\n\n");
                Sleep(500);
            }
            printf("\033[0;11m");
            exit(0);
            break;

        default:
            system("cls");
            printf("\033[0;31m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       Error! Wrong Input!\n\n\n\n");
            getch();
            system("cls");
            printf("\033[0;11m");
            break;
        }
    }
    while(ch!=0);
}

void customer()
{
    int ch,i;
    do
    {
        system("cls");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++               Star Cineplex             ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\t\t\t\t   ---------------------------------------------");
        printf("\n\t\t\t\t   Enter >1< Login");
        printf("\n\t\t\t\t   Enter >2< Sign Up");
        printf("\n\t\t\t\t   Enter >3< Home Page");
        printf("\n\t\t\t\t   Enter >0< Exit");
        printf("\n\t\t\t\t   ---------------------------------------------\n\n");
        printf("\n\t\t\t\t   Enter your Choice ::  ");
        fflush(stdin);
        scanf("%d",&ch);
        system("cls");

        switch (ch)
        {
        case 1 :
            menu();
            break;

        case 2:
            signup();
            break;

        case 3:
            main();
            break;

        case 0:
            system("cls");
            printf("\033[0;31m");
            for(i=0; i<4; i++)
            {
                system("cls");
                Sleep(500);
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    The Program is Closing!\n\n\n\n");
                Sleep(500);
            }
            printf("\033[0;11m");
            exit(0);
            break;

        default:
            system("cls");
            printf("\033[0;31m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       Error! Wrong Input!\n\n\n\n");
            getch();
            system("cls");
            printf("\033[0;11m");
            break;
        }
    }
    while(ch!=0);
}

void main()
{
    int ch=10,i;
    do
    {
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++         Welcome to Star Cineplex        ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\n\t\t\t\t\t      Choose Your Login Option");
        printf("\n\t\t\t\t   ---------------------------------------------");
        printf("\n\t\t\t\t   Enter >1< Admin");
        printf("\n\t\t\t\t   Enter >2< Customer");
        printf("\n\t\t\t\t   Enter >0< Exit");
        printf("\n\t\t\t\t   ---------------------------------------------\n");
        printf("\n\t\t\t\t   Enter your Choice ::  ");
        fflush(stdin);
        scanf("%d",&ch);
        system("cls");

        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   ++               Star Cineplex             ++\n");
        printf("\t\t\t\t   ++                                         ++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++\n\n");

        switch (ch)
        {
        case 1 :
            admin();
            break;

        case 2:
            customer();
            break;

        case 0:
            system("cls");
            printf("\033[0;31m");
            for(i=0; i<4; i++)
            {
                system("cls");
                Sleep(500);
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    The Program is Closing!\n\n\n\n");
                Sleep(500);
            }

            exit(0);
            break;

        default:
            system("cls");
            printf("\033[0;31m");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       Error! Wrong Input!\n\n\n\n");
            getch();
            system("cls");
            printf("\033[0;11m");
            main();
            break;
        }
    }
    while(ch!=0);
}
