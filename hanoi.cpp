/*
  The Tower of Hanoi
  programmed by Geoff Ramler

  The Tower of Hanoi is a mathematical puzzle with three rods and ‘n’ number of discs.
  The objective of this puzzle is to transfer the entire stack of discs to another rod.
  The puzzle was invented by the French mathematician Edouard Lucas in 1883. 

  Rules:
  Only a single disc is allowed to be transferred at a time.
  Each move should consist of taking the upper disc from one stack and placing it on top of another stack.
  Only the top most disc on the stack can be moved.
  Larger discs cannot be placed on top of smaller discs.
*/

#include <iostream>
#include <string>
#include <sstream>

int MOVES;

void moveDisc(int n, char initialRod, char finalRod, char auxiliaryRod);
int getInt ( std::string message, int min);

int main()
{
  char run;
  
  // Introduction and Rules
  std::cout << "\n Welcome to the Tower of Hanoi! A mathematical puzzle                     ";
  std::cout << "\n with three rods and ‘n’ number of discs.                                 " << std::endl;

  std::cout << "\n The objective of this puzzle is to transfer the entire stack of discs    ";
  std::cout << "\n from one rod to another.                                                 " << std::endl;

  std::cout << "\n The rules are simple:                                                    ";
  std::cout << "\n - Only a single disc is allowed to be transferred at a time.             ";
  std::cout << "\n - Each move should consist of taking the upper disc from one stack       ";
  std::cout << "\n    and placing it on top of another stack.                               ";
  std::cout << "\n - Only the top most disc on the stack can be moved.                      ";
  std::cout << "\n - Larger discs cannot be placed on top of smaller discs.                 " << std::endl;

  std::cout << "\n You will be asked to provide a quantity of discs to be moved.            ";
  std::cout << "\n Once the simulation is over, the total number of moves will be displayed." << std::endl;

  std::cout << "\n Would you like to run the simulation? (y/n): ";

  std::cin >> run;

  // Simulation
  while (run == 'y')
  {
    std::cin.clear();
    std::cin.ignore(100, '\n');
    MOVES = 0;

    int n = getInt("\n How many discs? ", 1);
    moveDisc(n, 'A', 'C', 'B');
    std::cout << "\n \n Total number of moves: " << MOVES << std::endl;
    std::cout << "\n Would you like to try again? (y/n): ";
    std::cin >> run;
  }

  return 0;
}

// Move discs recursively
void moveDisc(int n, char initialRod, char finalRod, char auxiliaryRod)
{
  if (n == 1)
  {
    std::cout << "\n Move disc 1 from rod " << initialRod << " to rod " << finalRod;
    MOVES++;
    return;
  }
  moveDisc(n-1, initialRod, auxiliaryRod, finalRod);
  std::cout << "\n Move disc " << n << " from rod " << initialRod << " to rod " << finalRod;
  moveDisc(n-1, auxiliaryRod, finalRod, initialRod);
  MOVES++;
}

// Ensure the input is an integer
int getInt ( std::string message, int min)
{
  int out;
  std::string in;

  while (true)
  {
    std::cout << message;
    getline( std::cin, in );
    std::stringstream ss( in );

    if( ss >> out && !(ss >> in) && out >= min )
    return out;

    std::cin.clear();
    std::cerr << " Invalid input. Try Again. ";
  }
}