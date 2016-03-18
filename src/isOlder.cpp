/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
#include<conio.h>
int isValid(int, int, int, int, int, int);
int check(int, int);
int isLeap(int);
int isOlder(char *dob1, char *dob2) {
	int i, count = 0, res;
	int year1 = 0, year2 = 0, day1 = 0, day2 = 0, mnth1 = 0, mnth2 = 0;
	for (i = 0; dob1[i] != '\0' && dob2[i] != '\0'; i++)
		count++;
	if (count == 10 && dob1[2] == '-' && dob2[2] == '-' && dob1[5] == '-' && dob2[5] == '-'){
		for (i = 0; dob1[i] != '\0' && dob2[i] != '\0'; i++){
			if (i < 2){
				day1 = (day1 * 10) + (dob1[i] - '0');
				day2 = (day2 * 10) + (dob2[i] - '0');
			}
			else if (i>2 && i < 5){
				mnth1 = (mnth1 * 10) + (dob1[i] - '0');
				mnth2 = (mnth2 * 10) + (dob2[i] - '0');
			}
			else if (i>5 && i < 10){
				year1 = (year1 * 10) + (dob1[i] - '0');
				year2 = (year2 * 10) + (dob2[i] - '0');
			}
		}
		if (isValid(day1, day2, mnth1, mnth2, year1, year2)){//Justifying the larger elder one
			res = check(year1, year2);
			if (res == 0){    //Checking Year
				res = check(mnth1, mnth2);
				if (res == 0){     //Checking Month
					res = check(day1, day2);
					return res;// Checking Day
				}
				return res;
			}
			else
				return res;
		}
		else
			return -1;
	}
	else
		return -1;

}


int check(int value1, int value2){
	if (value1<value2)
		return 1;
	else if (value2<value1)
		return 2;
	else
		return 0;
}

int isValid(int day1, int day2, int mnth1, int mnth2, int year1, int year2){
	if (mnth1>0 && mnth1 <= 12 && mnth2>0 && mnth2 <= 12){
		if (mnth1 == 4 || mnth2 == 4 || mnth1 == 6 || mnth2 == 6 || mnth1 == 9 || mnth2 == 9 || mnth1 == 11 || mnth2 == 11){
			if (day1>30 || day2>30)
				return 0;
			else
				return 1;
		}
		else if (mnth1 == 2 || mnth2 == 2){
			if (mnth1 == 2){
				if (isLeap(year1)){
					if (day1 > 29)
						return 0;
					else
						return 1;
				}
				else{
					if (isLeap(year2)){
						if (day1 > 28)
							return 0;
						else
							return 1;
					}

				}
			}
			else{
				if (isLeap(year1)){
					if (day1 > 29)
						return 0;
					else
						return 1;
				}
				else{
					if (isLeap(year2)){
						if (day1 > 28)
							return 0;
						else
							return 1;
					}

				}

			}
		}
		else{
			if (mnth1>31 || day2>31)
				return 0;
			else
				return 1;
		}

		}
		else
			return 0;

	}



int isLeap(int value){
	if (value % 4 == 0)
		return 1;
	else
		return 0;
}

