#include <iostream>

using namespace std;

int main()
{
  int myint = 9;
  float myFloat = 8.1;
  double myDouble = 9.3;
  char myChar = 'x';
  bool flag = false;

  // cout is printf cin is scanf
  cout << "Welcome to IPC144 review" << endl; // endl = "\n"
  cout << "First Session of OPP244" << endl;

  cout << "The value of my int is: " << myint << " and we are having fun" << endl;

  cout << "Please enter decimal ";
  cin >> myDouble;
  cout << "The value you entered is: " << myDouble << " and we are having fun" << endl;
  cout << flag << endl;
  cout << "Please enter a whole number between 0 and 100: ";
  cin >> myint;
  if (myint % 2 == 0)
  {
    cout << "EVEN" << endl;
  }
  else
  {
    cout << "ODD" << endl;
  }

  for (int i = 0; i <= 10; i++)
  {
    cout << i << endl;
  }
  return 0;
}