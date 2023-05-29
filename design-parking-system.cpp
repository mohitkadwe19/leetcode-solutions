#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
public:
  int big;
  int medium;
  int small;

  ParkingSystem(int big, int medium, int small)
  {
    this->big = big;
    this->medium = medium;
    this->small = small;
  }

  bool addCar(int carType)
  {

    if (carType == 1 && big == 0 || carType == 2 && medium == 0 || carType == 3 && small == 0)
    {
      return false;
    }

    if (carType == 1)
    {
      big--;
    }
    if (carType == 2)
    {
      medium--;
    }
    if (carType == 3)
    {
      small--;
    }

    return true;
  }
};

int main()
{
  ParkingSystem *obj = new ParkingSystem(1, 1, 0);
  cout << obj->addCar(1) << endl;
  cout << obj->addCar(2) << endl;
  cout << obj->addCar(3) << endl;
  cout << obj->addCar(1) << endl;
  return 0;
}