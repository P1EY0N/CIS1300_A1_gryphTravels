/************************quachGiaA1.c**************
Student Name: Gia Bao Quach               Email Id: gquach
Due Date: October 4th, 2024               Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.
********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall -lm
"Reason why to use -lm because we need to make a linker between <math.h> library and default configuration compiler.
(https://stackoverflow.com/questions/3209721/gcc-gives-error-while-using-fmod)"
compiling:
gcc quachGiaA1.c -std=c99 -Wall -lm
OR
gcc quachGiaA1.c -std=c99 -Wall -lm -o firstAssn
Running the Program
Running: ./a.out
OR
Running: ./firstAssn
*********************************************************/

#include <stdio.h>
#include <math.h>

int main() {
/***************************************
Task1: Customer’s choice of time format
****************************************/
    int formatTime;
    int hours24, hours12, minutes;
    char timeDetect;

    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");
    scanf("%d", &formatTime);
    printf("\n");

    if (formatTime == 1) {
        printf("Enter time in 12 hour format\n");
        printf("\n");
        printf("Enter a value between 0 and 12 for hour: ");
        scanf("%d", &hours12);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &minutes);
        printf("Enter a for am or p for pm: ");
        getchar();
        scanf("%c", &timeDetect);
        printf("---------------------------\n");
        printf("You entered %02d:%02d %cm\n", hours12, minutes, timeDetect);
        if ((hours12 == 12) & (timeDetect == 'a')) {
          printf("In 24-hour format - you entered 00:%02d\n", minutes);
        }
        if ((hours12 != 12) & (timeDetect == 'a')) {
          printf("In 24-hour format - you entered %02d:%02d\n", hours12, minutes);
        } 
        if ((hours12 != 12) & (timeDetect == 'p')) {
          printf("In 24-hour format - you entered %02d:%02d\n", hours12 + 12, minutes);
        }
        if ((hours12 == 12) & (timeDetect == 'p')){
          printf("In 24-hour format - you entered 12:%02d\n", minutes);
        }
        printf("---------------------------\n");
    } else if (formatTime == 2) {
        printf("Enter time in 24 hour format\n");
        printf("\n");
        printf("Enter a value between 0 and 24 for hour: ");
        scanf("%d", &hours24);
        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &minutes);
        printf("---------------------------\n");
        printf("You entered %02d:%02d\n", hours24, minutes);
        if ((hours24 > 12) & (hours24 <= 23)) {
          printf("In 12-hour format - you entered %02d:%02d pm\n", hours24 - 12, minutes);
        } else if (hours24 == 24) {
          printf("In 12-hour format - you entered 00:%02d am\n", minutes);
        } else if (hours24 == 12) {
          printf("In 12-hour format - you entered 12:%02d pm\n", minutes);
        } else {
          printf("In 12-hour format - you entered %02d:%02d am\n", hours24, minutes);
        }
        printf("---------------------------\n");
    }
/* Use 24h-format as main code for both scenarios
   Output will be in 12-h format for Task2 */
    if (formatTime == 1) {
      if ((timeDetect == 'p') & (hours12 != 12)) {
        hours24 = hours12 + 12;
      } else if ((timeDetect == 'a') & (hours12 == 12)) {
        hours24 = 0;
      } else {
        hours24 = hours12;
      }
    }
/*****************************
Task2: Closest departure time
******************************/
    float costFlight;

    switch (hours24) {
      case(0):case(1):case(2):case(3):case(4):case(5):case(6):
      case(18):case(19):case(20):case(21):case(22):case(23):case(24):
        printf("Closet departure time is 7:15 a.m., arriving at 8:25 a.m.\n");
        costFlight = 231;
        break;
      case 7:
        if ((minutes >= 0) & (minutes <= 14)) {
          printf("Closet departure time is 7:15 a.m., arriving at 8:25 a.m.\n");
          costFlight = 231;
        }
        if ((minutes >= 16) & (minutes <= 59)) {
          printf("Closet departure time is 8:15 a.m., arriving at 9:25 a.m.\n");
          costFlight = 226;
        }
        break;
      case 8:
        if ((minutes >= 0) & (minutes <= 14)) {
          printf("Closet departure time is 8:15 a.m., arriving at 9:25 a.m.\n");
          costFlight = 226;
        }
        if ((minutes >= 16) & (minutes <= 59)) {
          printf("Closet departure time is 9:15 a.m., arriving at 10:25 a.m.\n");
          costFlight = 226;
        }
        break;
      case 9:
        if ((minutes >= 0) & (minutes <= 14)) {
          printf("Closet departure time is 9:15 a.m., arriving at 10:25 a.m.\n");
          costFlight = 226;
        }
        if ((minutes >= 16) & (minutes <= 59)) {
          printf("Closet departure time is 10:15 a.m., arriving at 11:25 a.m.\n");
          costFlight = 283;
        }
        break;
      case 10: 
        if ((minutes >= 0) & (minutes <=14)) {
          printf("Closet departure time is 10:15 a.m., arriving at 11:25 a.m.\n");
          costFlight = 283;
        }
        if ((minutes >= 16) & (minutes <= 59 )) {
          printf("Closet departure time is 11:15 a.m., arriving at 12:25 a.m.\n");
          costFlight = 283;
        }
        break;
      case 11:
        if ((minutes >= 0) & (minutes <= 14)) {
          printf("Closet departure time is 11:15 a.m., arriving at 12:25 a.m.\n");
          costFlight = 283;
        }
        if ((minutes >= 16) & (minutes <= 59)) {
          printf("Closet departure time is 3:15 p.m., arriving at 4:25 p.m.\n");
          costFlight = 226;
        }
        break;
      case (12):case (13):case (14):
          printf("Closet departure time is 3:15 p.m., arriving at 4:25 p.m.\n");
          costFlight = 226;
        break;
      case (15):
        if ((minutes >= 0) & (minutes <= 14)) {
          printf("Closet departure time is 3:15 a.m., arriving at 4:25 p.m.\n");
          costFlight = 226;
        }
        if ((minutes >= 16) & (minutes <= 59)) {
          printf("Closet departure time is 4:15 a.m., arriving at 5:25 p.m.\n");
          costFlight = 226;
        }
        break;
      case (16):
        if ((minutes >= 0) & (minutes <= 14)) {
          printf("Closet departure time is 4:15 a.m., arriving at 5:25 p.m.\n");
          costFlight = 226;
        }
        if ((minutes >= 16) & (minutes <= 59)) {
          printf("Closet departure time is 5:15 a.m., arriving at 6:25 p.m.\n");
          costFlight = 241;
        }
        break;
      case (17):
        if ((minutes >= 0) & (minutes <= 14)) {
          printf("Closet departure time is 5:15 a.m., arriving at 6:25 p.m.\n");
          costFlight = 401;
        }
        if ((minutes >= 16) & (minutes <= 59)) {
          printf("Closet departure time is 07:15 a.m., arriving at 08:25 a.m.\n");
          costFlight = 231;
        }
        break;
    }
    printf("\n");
/***********************************************************************
Taks 3: Do you need a hotel? + Task 4: Do you need a ride to the hotel?
************************************************************************/
    int formatHotel, dayBirth;
    int chooseHotel, numberDays, chooseRide;
// Option for hotel or not?
    printf("Would you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
    scanf("%d", &formatHotel);
    printf("\n");
// If formatHotel == 1, display hotel available
    switch (formatHotel) {
      case (1):
      printf("There are 3 hotels:\n");
      printf("1. Marriott: $248 per night\n");
      printf("2. Sheraton: $90 per night\n");
      printf("3. Double Tree: $128 per night\n");
      printf("\n");
      //Choose Hotel to stay
      printf("Your choice? ");
      scanf("%d", &chooseHotel);
      //Number of days in Montreal
      printf("How many days in Montreal? ");
      scanf("%d", &numberDays);
      printf("\n");
      //Ride to hotel?
      printf("Would you like a ride from airport to hotel? - enter 0 for no; 1 for yes: ");
      scanf("%d", &chooseRide);
      printf("\n");
      break;
    }
// Input dayBirth for qualify Dicount2
    printf("Now enter your day of birth to qualify for discount2: ");
    scanf("%d", &dayBirth);
    printf("\n");
/*******************
Task 5: Total cost
********************/
    float costHotel, costRide, totalCost;
//Determine Cost of Hotel + Cost of Ride
    switch (chooseRide) {
      case (1):
        switch (chooseHotel) {
          case 1:
            costHotel = 248;
            costRide = 0;
            break;
          case 2:
            costHotel = 90;
            costRide = 25;
            break;
          case 3:
            costHotel = 128;
            costRide = 20;
            break;
        }
      case (0):
        switch (chooseHotel) {
          case 1:
            costHotel = 248;
            costRide = 0;
            break;
          case 2:
            costHotel = 90;
            costRide = 0;
            break;
          case 3:
            costHotel = 128;
            costRide = 0;
            break;
        }
      break;
    }
//Display Cost of (flight, hotel, ride); and Total cost before tax
    printf("Your total cost comes to:\n");
    printf("\n");
    printf("Cost of closet departure flight: $ %.2f\n", costFlight);
    printf("Cost of Hotel for %d days: $ %.2f\n", numberDays, costHotel * numberDays);
    printf("Cost of ride: $ %.2f\n", costRide);
    printf("\n");
    totalCost = costFlight + costRide + costHotel * numberDays;
    printf("Total cost before tax: $ %.2f\n", totalCost);
    printf("\n");
/*******************
 Task 6: Freebees
********************/
/*Using fmodf for finding mod in float by using <math.h> library
  https://pubs.opengroup.org/onlinepubs/9699919799/functions/fmod.html */
//Eligible for discount1 (5%) or not?
    if (fmodf (totalCost, 11) == 0 ) {
      printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
      totalCost = totalCost * 0.95; //Discount1 if pass
    } else {
      printf("Sorry - you missed out on 5%% discount because the total cost was not a multiple of 11\n");
    }
//Eligible for discount2 (5%) or not?
    if (fmodf(totalCost, ((dayBirth / 10) + (dayBirth % 10))) == 0) {
      printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
      totalCost = totalCost * 0.95; //Discount 2 if pass
    } else {
      printf("Sorry - you missed out on the additional 5%% discount because the total cost after discount1 was not a multiple of the sum of digits in your day of birth\n");
    }
    printf("\n");
//Total cost after Discount 1 & 2
    printf("Total cost after discounts 1 and 2: $ %.2f\n", totalCost);
    printf("\n");
//Total cost after tax (13% tax)
    printf("Finally, your total cost after taxes: $ %.2f\n", totalCost * 1.13);

  return 0;
}