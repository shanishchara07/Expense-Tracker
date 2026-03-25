#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    int day, month, year;
    char category[20];
    float amount;
};

struct Expense list[100];
int count = 0;
float budget = 10000;

int validateMonth(int m)
{
    return (m>=1 && m<=12);
}

void addExpense()
{
    printf("\n--- Adding Expense ---\n");

    printf("Enter Day: ");
    scanf("%d",&list[count].day);
    printf("You Entered Day = %d\n", list[count].day);

    printf("Enter Month: ");
    scanf("%d",&list[count].month);
    printf("You Entered Month = %d\n", list[count].month);

    printf("Enter Year: ");
    scanf("%d",&list[count].year);
    printf("You Entered Year = %d\n", list[count].year);

    printf("Enter Category: ");
    scanf("%s",list[count].category);
    printf("You Entered Category = %s\n", list[count].category);

    printf("Enter Amount: ");
    scanf("%f",&list[count].amount);
    printf("You Entered Amount = %.2f\n", list[count].amount);

    printf("\nProcessing...\n");

    count++;

    printf("Expense Added Successfully\n");

    printf("\nCurrent Expenses:\n");

    for(int i=0;i<count;i++)
    {
        printf("%d-%d-%d | %s | %.2f\n",
        list[i].day,
        list[i].month,
        list[i].year,
        list[i].category,
        list[i].amount);
    }
}

void monthlyTotal()
{
    int m,y;
    float total=0;

    printf("Enter Month: ");
    scanf("%d",&m);

    printf("Enter Year: ");
    scanf("%d",&y);

    for(int i=0;i<count;i++)
        if(list[i].month==m && list[i].year==y)
            total+=list[i].amount;

    printf("Monthly Total = %.2f\n",total);

    if(total>budget)
        printf("WARNING Budget Exceeded\n");
}

void categoryTotal()
{
    char cat[20];
    float total=0;

    printf("Enter Category: ");
    scanf("%s",cat);

    for(int i=0;i<count;i++)
        if(strcmp(list[i].category,cat)==0)
            total+=list[i].amount;

    printf("Category Total = %.2f\n",total);
}

void searchByMonth()
{
    int m,found=0;

    printf("Enter Month: ");
    scanf("%d",&m);

    for(int i=0;i<count;i++)
        if(list[i].month==m)
        {
            printf("%d-%d-%d %s %.2f\n",
            list[i].day,
            list[i].month,
            list[i].year,
            list[i].category,
            list[i].amount);
            found=1;
        }

    if(!found)
        printf("No Records\n");
}

void showAll()
{
    if(count==0)
    {
        printf("No Expenses\n");
        return;
    }

    for(int i=0;i<count;i++)
        printf("%d-%d-%d | %s | %.2f\n",
        list[i].day,
        list[i].month,
        list[i].year,
        list[i].category,
        list[i].amount);
}
#include <stdio.h>
#include <string.h>

int main()
{
    int ch;

    printf("===== EXPENSE TRACKER =====\n");
    printf("1 Add Expense\n");
    printf("2 Show All\n");

    printf("Enter Choice: ");
    scanf("%d",&ch);

    if(ch==1)
    {
        addExpense();
        printf("\nExpense Added\n");
        showAll();
    }
    else if(ch==2)
    {
        showAll();
    }
    else
    {
        printf("Invalid Choice\n");
    }

    return 0;
}