#include <stdio.h>

#define STOP 45 // will be changed to 'esc'
#define TRUE 1
#define FALSE 0
//write the shell for the program.

void getInput(int *year, int *month);

void computeInput(int);

void exitProgram(void);


int run = TRUE;

char *months[] = {
    "Null",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June", 
    "July",
    "August",
    "September",
    "October"
    "November",
    "December" };

int days_in_each_month[] = {0,31,28,30,31,30,31,31,30,31,30,31};

int main(){

int input,year,month;
while (run)
{
    //get Input.
    getInput(&year,&month);
    printf("the numbers you entered %d - %d\n",year,month);
    //computeInput();

}
 

    return 0;
}

void getInput(int *year, int *month){
    // print statement and return input.
    // f: check for valid input.
    int temp_year;
    int temp_month;

   do
   {
           printf("please enter the year and the month in the format yyyy-mm \n");
           scanf(" %d-%d",&temp_year,&temp_month);
           while(getchar() !='\n');
   } 
   while ((temp_year<0) || temp_month>12 || temp_month<1 );
    
    *year = temp_year;
    *month = temp_month; 
        


}

void computeInput(int userInput){
//
if(userInput == STOP){
    exitProgram();
    }
}

void calculateInput(int userInput){
    
} 
void exitProgram(){
    //cleanup, exit program.
    // ? clean screen ? etc. 

    printf("thanks for using my calendar");
    run = FALSE;
}

