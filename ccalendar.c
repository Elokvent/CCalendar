#include <stdio.h>

#define STOP 45 // will be changed to 'esc'
#define TRUE 1
#define FALSE 0
//write the shell for the program.

void getInput(int *year, int *month);

void exitProgram(void);

int getFirstDate(int , int );

void printCalendar(int, int, int ); 

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
    "October",
    "November",
    "December" };

char *days[] = {
    "Mo",
    "Tu",
    "We",
    "Th",
    "Fr",
    "Sa",
    "Su",
};

int days_in_each_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){

int input,year,month;
while (run)
{
    //get Input.
    getInput(&year,&month);
    printCalendar(getFirstDate(year,month),month, year);
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



void exitProgram(){
    //cleanup, exit program.
    // ? clean screen ? etc. 

    printf("thanks for using my calendar");
    run = FALSE;
}

int getFirstDate(int year, int month){ // lol ta bort dessa.
    //calculate yearcode.
    int yearCode = ((year % 100) + ((year % 100)/4)) % 7;
    // monthcode using the position later on that month to get specific numbers.
    int monthCode[] = {0,0,3,3,6,1,4,6,2,5,0,3,5}; // move out later on.
    // get century code.
    int centuryCode [] = {4,2,0,6,4,2,0}; // testing first by hardcoding. 6
    //get leap year status.
    int leapYear = ((!(year % 4) && (year % 100)) || !(year % 400)) ? TRUE : FALSE;
    int whichCentury = 3;

    //got which day the 1 is in the month -> get back to main.
    return (yearCode + monthCode[month] + 6 + 1 - leapYear) % 7; 
    

}

void printCalendar(int firstDay, int month, int year){
    int rowcounter = 0;

    //set the layout.
    printf("--------------------%d---------------------\n",year);
    printf("--------------------%s--------------------\n",months[month]);
    for(int i = 0; i<7; i++){
        printf("%6s",days[i]);
    }
    printf("\n---------------------------------------------\n");
    int j;
    if(month>1){
     j = days_in_each_month[month-1] - firstDay +2;
    }else{
     j = days_in_each_month[12] - firstDay +2 ; 
    }
   
    for(int i = 1;i < firstDay; i++){
         
         printf("%6d",j);
         j++,rowcounter++;
    }
    for(int i = 1;i<=days_in_each_month[month];i++){
        if(rowcounter == 7){
            rowcounter=0;
            printf("\n");
        }
        printf("%6d",i);
        rowcounter++;
    }
    printf("\n---------------------------------------------\n");



}

