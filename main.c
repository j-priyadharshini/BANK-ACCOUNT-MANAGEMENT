#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>



struct accountDetails
    {
      int accountNumber;
      char fname[15];
      char lname[15];
      int amount;
      int pin;
    }reg,r;

void titleScreen();
int menu();
void open();
int dwt();
int transfer();
void details();
void close();
void closeScreen();



int main()
{
    titleScreen();
    menu();
    return 0;
}

void titleScreen(void)
{
    system("cls");
    //title
    printf("\n\n\t\t\t\t\t\t\t\t\t\t");
    for(int i=0;i<25;i++)
    {
        printf("[]");
    }
     printf("\n\t\t\t\t\t\t\t\t\t\t");
    for(int i=0;i<50;i++)
    {
        printf("*");
    }
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t   BANK   SYSTEM                ");

    printf("\n\t\t\t\t\t\t\t\t\t\t");

    for(int i=0;i<50;i++)
    {
        printf("*");
    }
    printf("\n\t\t\t\t\t\t\t\t\t\t");
    for(int i=0;i<25;i++)
    {
        printf("[]");
    }
printf("\n\n\n\n");
getch();
}


int menu()
{
    system("cls");
    int option;
    printf("the folowing are the options you can perform\n");
    printf("1)open an account\n2)deposite money into your account\n3)withdraw money from your account\n4)transfer money from one account to another\n5)get account details\n6)close an account\n7)exit");
    printf("\nenter a valid option:  ");
    scanf("%d",&option);
    if(option==1)
    {
        open();
        getch();
        menu();
    }
    else if(option==2)
    {
        dwt(option,0);
        getch();
        menu();
    }
    else if(option==3)
    {

        dwt(option,0);
        getch();
        menu();
    }
    else if(option==4)
    {
          transfer();
          getch();
          menu();
    }
    else if(option==5)
    {
        details();
        getch();
        menu();
    }
    else if (option==6)
    {
         close();
         getch();
         closeScreen();
    }
    else if(option==7)
    {
        closeScreen();
    }

}


void closeScreen()
{
    system("cls");
    //title
    printf("\n\n\t\t\t\t\t\t\t\t\t\t<");
    for(int i=0;i<50;i++)
    {
        printf("^");
    }
     printf(">\n\t\t\t\t\t\t\t\t\t\t<");
    for(int i=0;i<50;i++)
    {
        printf("*");
    }
    printf(">\n\t\t\t\t\t\t\t\t\t\t<\t\t  BANK     SYSTEM   \t\t   >\n\t\t\t\t\t\t\t\t\t\t<");
    for(int i=0;i<50;i++)
    {
        printf("*");
    }
    printf(">\n\t\t\t\t\t\t\t\t\t\t<");
    for(int i=0;i<50;i++)
    {
        printf("v");
    }
printf(">\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   SEE YOU SOON...\n\n\n\n\n\n\n");
}

void open()
{
    FILE* fp;
    fp=fopen("Record.txt","a+");
    //first name
    printf("Enter your first name :  \n>");
    scanf("%s",reg.fname);
    while(strlen(reg.fname)<3)
    {
        printf("INVALID : Please enter data of minimum 2 characters .\n>");
        scanf("%s",reg.fname);
    }

    reg.fname[0]=toupper(reg.fname[0]);

    //last name
    printf("Enter your last name :  \n>");
    scanf("%s",reg.lname);
    while(strlen(reg.lname)<3)
    {
        printf("INVALID : Please enter data with more than 2 characters .\n>");
        scanf("%s",reg.lname);
    }
    reg.lname[0]=toupper(reg.lname[0]);

    //amount to be deposited
    printf("NOTE:the minimum amount to be deposited is Rs.500\n ");
    printf("Enter the amount to be deposited : ");
    scanf("%d",&reg.amount);
    while(reg.amount<500)
    {
        printf("\nINVALID : Enter a valid amount(use digits from 0-9)\n>");
        scanf("%d",&reg.amount);
    }
    printf("Enter the pin : \n>");
    scanf("%d",&reg.pin);
    while(reg.pin<1000)
    {
        printf("INVALID : Please enter pin with more than 4 digits .\n>");
        scanf("%d",&reg.pin);
    }

    //account number
    FILE* idf,* temp;
    int id;
    idf=fopen("idfile.txt","r");
    fscanf(idf,"%d",&id);
    ++id;
    temp=fopen("temp.txt","w+");
    fprintf(temp,"%d",id);
    reg.accountNumber=id;
    fprintf(fp,"%d %s %s %d %d\n",reg.accountNumber,reg.fname,reg.lname,reg.amount,reg.pin);
    fclose(idf);
    fclose(temp);
    fclose(fp);
    remove("idfile.txt");
    rename("temp.txt","idfile.txt");
    printf("Your account number is %d\n",id);
    printf("NOTE:please record the account number will not be provided again");
}


int dwt(option,amt)
{
    int num;
    FILE *fid;
    fid=fopen("idfile.txt","r");
    fscanf(fid,"%d",&num);
    fclose(fid);
    int accNum,pin,count=0,deposit,withdraw;
    FILE* fp,*temp;
    temp=fopen("temp.txt","a");
    fp=fopen("Record.txt","r");
    system("cls");
    printf("AMOUNT ALTERATIONS\n\n\n\n");
    printf("Enter the account number (use digits form0-9)\n");
    scanf("%d",&accNum);
    while(accNum>num)
{
    printf("\naccount number does not exist\n\n");
    printf("Enter the account number (use digits form0-9)\n");
    scanf("%d",&accNum);
}
    while(fscanf(fp,"%d %s %s %d %d\n", &reg.accountNumber, reg.fname,reg.lname,&reg.amount,&reg.pin)!=EOF)
        {
            if(reg.accountNumber==accNum)
            {
                break;
            }
           else if(reg.accountNumber!=accNum)
            {
                 fprintf(temp,"%d %s %s %d %d\n",reg.accountNumber,reg.fname,reg.lname,reg.amount,reg.pin);
                 continue;
            }
        }
    printf("\n\nNAME:  %s %s",reg.fname,reg.lname);
    if (option==2||option==3||option==4)
    {
        printf("\nenter the pin to access your account: ");
       scanf("%d",&pin);
       while(pin!=reg.pin && count<3)
      {
        ++count;
        printf("\nINVALID PIN ENTER AGAIN:\n");
        scanf("%d",&pin);
       }
    if (count==3)
    {
       printf("you have tried too many times\n access denied\ntry again later\n");
       getch();
        closeScreen();
        return 0;
    }

    printf("\nACCESS GRANTED\n");
    printf("your balance: %d",reg.amount);
   }

    switch(option)
    {
    case 0:
        reg.amount=reg.amount+amt;
        break;
    case 2:
         printf("\nenter the amount to be deposited: ");
         scanf("%d",&deposit);
         reg.amount=reg.amount+deposit;
         printf("\nthe current amount in your account: %d",reg.amount);
         break;
    case 3:
         printf("\nenter the amount to be withdrawn: ");
         scanf("%d",&withdraw);
         while((reg.amount-withdraw)<500 || withdraw>10000)
         {
             printf("\nyou cant withdraw this amount \ntry again\nNOTE:the amount withdrawn must not be greater than Rs.10,000 and the accounts balance cannot go below Rs.500");
             printf("\nenter the amount to be withdrawn: ");
             scanf("%d",&withdraw);
         }
         reg.amount=reg.amount-withdraw;
         printf("\nthe current amount in your account: %d",reg.amount);
         break;
    case 4:
         printf("\nenter transfer amount:");
         scanf("%d",&amt);
         while((reg.amount-amt)<500 || amt>10000)
         {
             printf("\nyou cant transfer this amount \ntry again\nNOTE:the amount transfered must not be greater than Rs.10,000 and the accounts balance cannot go below Rs.500");
             printf("\nenter the amount to be withdrawn: ");
             scanf("%d",&amt);
         }
        reg.amount=reg.amount-amt;
        printf("\nthe current amount in your account: %d",reg.amount);

        break;

    }

    fprintf(temp,"%d %s %s %d %d\n",reg.accountNumber,reg.fname,reg.lname,reg.amount,reg.pin);
    while(fscanf(fp,"%d %s %s %d %d\n", &r.accountNumber, r.fname,r.lname,&r.amount,&r.pin)!=EOF)
        {
            if(r.accountNumber!=accNum)
            {
                 fprintf(temp,"%d %s %s %d %d\n",r.accountNumber,r.fname,r.lname,r.amount,r.pin);
            }
        }

     fclose(temp);
     fclose(fp);
     remove("Record.txt");
     rename("temp.txt","Record.txt");
     if(option==4)
     {
          return amt;
     }



}

int transfer()
{
    system("cls");
    int amt;
    printf("TRANSFER FROM SENDER TO RECIEVER\n\n");
    printf("SENDER INFO:\n\n");
    getch();
    amt=dwt(4,0);
    getch();
    system("cls");
    printf("RECEIVER INFO:\n\n");
    getch();
    dwt(0,amt);
    getch();
    printf("\nTRANSFER SUCCESSFUL");

}


void details()
{
    int num;
    FILE *fid;
    fid=fopen("idfile.txt","r");
    fscanf(fid,"%d",&num);
    fclose(fid);
    system("cls");
    FILE*fp;
    int accNum,pin,count=0;
    fp=fopen("Record.txt","r");
    printf("Enter the account number (use digits from 0-9)\n");
    scanf("%d",&accNum);
    while(accNum>num)
{
    printf("\naccount number does not exist\n");
    printf("Enter the account number (use digits form0-9)\n");
    scanf("%d",&accNum);
}
    while(fscanf(fp,"%d %s %s %d %d\n", &reg.accountNumber, reg.fname,reg.lname,&reg.amount,&reg.pin)!=EOF)
        {
            if(reg.accountNumber==accNum)
            {
                break;
            }
        }
    printf("\nenter the pin to access your account: ");
    scanf("%d",&pin);
    while(pin!=reg.pin && count<3)
    {
        ++count;
        printf("\nINVALID PIN ENTER AGAIN:\n");
        scanf("%d",&pin);
    }
    if (count==3)
    {
       printf("you have tried too many times\n access denied\ntry again later\n");
       getch();
        closeScreen();
        return 0;
    }
    printf("\nACCESS GRANTED\n");
    printf("\n\nNAME:  %s %s\n\n",reg.fname,reg.lname);
    printf("your balance:  %d",reg.amount);
    fclose(fp);
}

void close()
{
    int num;
    FILE *fid;
    fid=fopen("idfile.txt","r");
    fscanf(fid,"%d",&num);
    fclose(fid);
    system("cls");
    int accNum,pin,count=0,deposit,withdraw;
    FILE* fp,*temp;
    temp=fopen("temp.txt","a");
    fp=fopen("Record.txt","r");
    printf("Enter the account number\n");
    scanf("%d",&accNum);
    while(accNum>num)
{
    printf("\naccount number does not exist\n");
    printf("Enter the account number\n");
    scanf("%d",&accNum);
}
    while(fscanf(fp,"%d %s %s %d %d\n", &reg.accountNumber, reg.fname,reg.lname,&reg.amount,&reg.pin)!=EOF)
        {
            if(reg.accountNumber==accNum)
            {
                r.accountNumber=reg.accountNumber;
                r.amount=reg.amount;
                strcpy(r.fname,reg.fname);
                strcpy(r.lname,reg.lname);
                r.pin=reg.pin;
                continue;
            }
           else if(reg.accountNumber!=accNum)
            {
                 fprintf(temp,"%d %s %s %d %d\n",reg.accountNumber,reg.fname,reg.lname,reg.amount,reg.pin);
            }
        }
    printf("\n\nNAME:  %s %s",r.fname,r.lname);
    printf("\nenter the pin to access your account: ");
    scanf("%d",&pin);
    while(pin!=r.pin && count<3)
    {
        ++count;
        printf("\nINVALID PIN ENTER AGAIN:\n");
    }
    if (count==3)
    {
       printf("you have tried too many times\n access denied\ntry again later\n");
        closeScreen();
        return 0;
    }
    printf("\nACCESS GRANTED\n");
    printf("your balance: %d",r.amount);
    fclose(temp);
     fclose(fp);
     remove("Record.txt");
     rename("temp.txt","Record.txt");
     printf("\n\nACCOUNT SUCCESSFULLY DELETED");
}

