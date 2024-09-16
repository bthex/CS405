// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  char temp_buffer[100]; // Temporary buffer to hold the user input
  std::cout << "Enter a value: ";
  std::cin.getline(temp_buffer, 100);
  if (strlen(temp_buffer) > 19) {
      // Notify the user if they entered too much data
      temp_buffer[19] = '\0';
      std::cout << "You entered too much data. Please enter a value of 19 characters or less." << std::endl;
  }
  strcpy(user_input, temp_buffer);
  user_input[19] = '\0';


  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
