/*
  Project Description: This program will read in a series of (80 or less) alphanumeric characters, remove all puctutation and spaces, and check if the input if a palindrome.
  Name: Aammya Sapra
  Date: February 21, 2021
 */


#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	cout << "Input a series of 80 or less alphanumeric characters to check if it is a palindrome." << endl;
	
	//remember cstrings are null-terminated '\0'
	char raw_input[81]; //initialize char array to hold up to 80 characters of user input (including punctuation and spaces)
	cin.get(raw_input, 81); //read input into raw_input char array
	cin.get(); //kill the return
	//cout << "Raw input: " << raw_input << endl;


	char input[81]; //array to hold filtered user input (no spaces or punctuation)
	int index = 0; //user_input index counter

	//loop to remove all spaces and punctuation and make all letters the same case (lowercase)
	for (int i = 0; i < 81; i++) {
		if (raw_input[i] >= 48 && raw_input[i] <= 57) { //numerical character
			input[index] = raw_input[i];
			index++;
		} else if (raw_input[i] >= 65 && raw_input[i] <= 90) { //uppercase character
			input[index] = tolower(raw_input[i]); //make lowercase
			index++;
		} else if (raw_input[i] >= 97 && raw_input[i] <= 122) { //lowercase character
			input[index] = raw_input[i];
			index++;
		} else if (raw_input[i] == '\0') { //terminating null character
			input[index] = raw_input[i];
			index++;
		} 
	}

	// cout << "Input: " << input << endl;
	
	int length = strlen(input); //number of characters (not indcluding null terminating character)
	bool isPalindrome = true; //initialize boolean variable to hold whether or not input is palindrome
	
	//loop to check if input is a palindrome
	for (int i = 0; i < length; i++) { 
		// i = 0 is the index of the first/leftmost character
		// (length - 1) is the index of the last/rightmost character) not including null
		if (input[i] != input[length - i - 1]) { 
			isPalindrome = false;
			break;
		}
	}


	//tell user if input is a palindrome or not
	if (isPalindrome) {
		cout << raw_input << " is a palindrome." << endl;
	} else if (isPalindrome == false) {
		cout << raw_input << " is NOT a palindrome." << endl;
	}
	

	return 0;
} //end