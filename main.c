#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct node
{
    int id,age;
    int phone_number[20];
    char name[100];
    float salary;
    struct node *next;
}*head;

void append()
{
    printf("\n\nAdd Employee Record:\n");
    printf("___________________\n\n");
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("            Enter ID:");
    scanf("%d",&temp->id);
    getchar();
    printf("            Enter Name:");
    gets(temp->name);
    printf("            Enter Age:");
    scanf("%d",&temp->age);
    printf("            Enter Basic Salary:");
    scanf("%f",&temp->salary);
    printf("            Enter Phone Number:");
    scanf("%s",&temp->phone_number);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    system("CLS");
    printf(" ***  Employee Added Successfully  *****\n");
    Sleep(2000);
    system("CLS");

}
void search()
{
    struct node *temp;
    int sid,flag=0;
    printf("            Enter Search ID:");
    scanf("%d",&sid);
    system("CLS\n");
    printf("                \n\n");
    printf("        ID      NAME        Age     Salary      Phone Number\t\n");
    temp=head;
    while(temp!=NULL)
    {
        if(temp->id==sid)
        {
            printf("%d      ",temp->id);
            printf("%s      ",temp->name);
            printf("%d      ",temp->age);
            printf("%.2f        ",temp->salary);
            printf("%s      ",temp->phone_number);
            flag=1;
            break;
        }
        temp=temp->next;

    }
    if(flag==0)
    {
        printf("Not found\n");
    }
    printf("\nPress enter go to home page:\n");
    getchar();
    getchar();
    system("CLS");


}
void delete_info()
{
    struct node *prev,*tem;
    tem = head;
    prev = head;
    int ID;
    printf("Enter Delete ID:\n");
    scanf("%d",&ID);

    while(tem->id != ID)
    {
        prev =tem;
        tem = tem->next;
    }
    if(prev==tem)
    {
        head = head->next;
        return;
    }
    prev->next = tem->next;
    free(tem);
    system("CLS");
    printf(" ***  Employee Delete Successfully  *****\n");
    Sleep(2000);
    system("CLS");
}
void modify()
{
    while(1)
    {
        printf("Please Enter The Employee ID which You want to modify: ");
        int id;
        scanf("%d",&id);
        struct node *temp;
        temp = head;
        int ck=0;
        while(temp!= NULL)
        {
            if(temp->id == id)
            {
                printf("What Do You Want To Modify?\n");
                printf("\n\tPress 1 For ID");
                printf("\n\tPress 2 For Name");
                printf("\n\tPress 3 For Age");
                printf("\n\tPress 4 For Salary");
                printf("\n\tPress 5 For Phone No");
                printf("\n\tPress 6 For All Information");
                int choice;

                printf("\n\tPlease Enter Your Choice : ");
                scanf("%d",&choice);
                printf("\n");

                if(choice==1)
                {
                    printf("Please Enter ID : ");
                    scanf("%d",&temp->id);
                }
                else if(choice==2)
                {
                    printf("\nPlease Enter Name : ");
                    gets(temp->name);
                }
                else if(choice==3)
                {
                    printf("\nPlease Enter Age : ");
                    scanf("%d",&temp->age);
                }
                else if(choice==4)
                {
                    printf("\nPlease Enter Salary : ");
                    scanf("%f",&temp->salary);
                }
                else if(choice==5)
                {
                    printf("\nPlease Enter Phone No : ");
                    scanf("%d",&temp->phone_number);
                }
                else if(choice==6)
                {
                    printf("\nPlease Enter All Informations:\n");
                    printf("Id: ");
                    scanf("%d",&temp->id);
                    getchar();
                    printf("\nName: ");
                    gets(temp->name);
                    printf("\nAge: ");
                    scanf("%d",&temp->age);
                    printf("\nNumber: ");
                    scanf("%d",&temp->phone_number);
                    printf("\nSalary: ");
                    scanf("%d",&temp->salary);
                }

                ck=1;
            }
            else
            {
                temp=temp->next;
            }
        }

        if(ck==0)
        {
            printf("Please Enter Valid ID\n");
        }
        else
        {
            break;
        }
    }
    system("CLS");
    printf("*** Employee Modify Successfully***\n");
    Sleep(2000);
    system("CLS");
    display();


}
void display()
{
    printf("\tID      \tNAME        \tAge     \tSalary      \tPhone Number\t\n");
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("\t%d      \t%s      \t%d      \t%.2f        \t%s\t\n ",p->id,p->name,p->age,p->salary,p->phone_number);
        p=p->next;
    }
    printf("Press enter go to home page:\n");
    getchar();
    getchar();
    system("CLS");

}
int main()
{
    int flag=0;
    while(1)
    {
        printf("\t\t\t***Employee Record System***\t\t\t\n ");
        printf("\t\t---------------------------------------\t\t\n\n");
        printf("         1.Add Employee Record\n");
        printf("         2.Display All Employee Record\n");
        printf("         3.Search A Employee Record\n");
        printf("         4.Delete Employee Record\n");
        printf("         5.Modify Record\n");
        printf("         6.Exits\n");

        printf("            Enter any number:");
        int n;
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            system("CLS");
            append();

            break;
        case 2:
            system("CLS");
            display();
            break;
        case 3:
            system("CLS");
            search();
            break;
        case 4:
            system("CLS");
            delete_info();
            break;
        case 5:
            system("CLS");
            modify();
            break;
        case 6:
            flag=1;
            break;
        default:
            system("CLS");
            printf("****Please Enter The Valid Input****\n");
            Sleep(2000);
            system("CLS");
        }
        if(flag==1)
            break;
    }
    return 0;
}
