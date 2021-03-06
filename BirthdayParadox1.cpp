#include <iostream>
#include <cmath>
#include <iomanip>
//As a side note, this problem is called the birthday paradox. There are
//various different ways to solve it. In this program, I will explain it using
//the pigeonhole principle.
//The reader has to know something about conditional probability, or the probability
//that an event will occur given that another event occurred.

using namespace std;


//The function prototype is here.
double calculations(int, int);


//With that computed, it is a simple matter to find out the probability
//that there are two people in the room that have the same birthday because
//the two probabilities are mutually exclusive or that they both cannot occur.

int main()
{

   cout << fixed << setprecision(2) << "The probability that two people have the same birthday in a soccer game of 22 people is " <<
      (1 - calculations(365, 22)) * 100 << "%" << endl;
   return 0;
}

double calculations(int numberOfDaysInAYear, int numberOfPeople) {
   //I declare a function to compute the probability that there are no two 
   //people in the room that have the same birthday because it is a simpler
   //calculation.
   //Here's how this derivation works. Given a group of people The probability that everyone have 
   //different birthdays is same as the probability that the first person does not have the
   //same birthday as the second person, the second person does not have the same
   //birthday as the third person, and so on. So if the first person's birthday is on, say,
   //March 1st, no other person can have that birthday, meaning that the second person's
   //birthday must be on the one of the 364 days or the days that are not March 1st. 
   //Then the third person's birthday must be on one of the remaining 363 days. This
   //repeats for everyone else. 
   //The probability that the second person's birthday fall on one of the days that is 
   //not the first person's birthday is 364/365. The demoninator tells us the number of 
   //days in a year and the numerator tells the number of days that the second person could
   //have on the assumption that he does not share a birthday with the first person. The
   //probability that the third person does not share the same birthday with the first or
   //second is 363/365. To find the probability that no one shares the same birthday with 
   //each other, we simply multiply the probability together. This is because

   double factorial = 1; //
   int i; //This is my counter variable
   for (i = numberOfDaysInAYear; i > numberOfDaysInAYear - numberOfPeople; i--)
      factorial = (factorial * i) / 365;

   return factorial;
}
