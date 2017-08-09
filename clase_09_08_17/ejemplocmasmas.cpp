#include<iostream>

int main()
{
  double furlong_d = 0;
  double yards_d = 0;


  std::cout << "Please type the distance in Furlongs." << std::endl;
  std::cin >> furlong_d;
  
  yards_d = furlong_d * 220.0;
  
  std::cout << "Your distance in Yards is " << yards_d << ". " << std::endl; 
  
  return 0;
}
