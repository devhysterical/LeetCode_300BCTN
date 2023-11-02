// https://leetcode.com/problems/design-parking-system/

class ParkingSystem
{
private:
  int bigSLots;
  int mediumSlots;
  int smallSlots;

public:
  /**
   * The function initializes the number of available parking slots for different sizes of vehicles.
   * 
   * @param big The number of available parking slots for big cars.
   * @param medium The parameter "medium" in the constructor function "ParkingSystem" represents the
   * number of parking slots available for medium-sized vehicles in the parking system.
   * @param small The number of available parking slots for small cars in the parking system.
   */
  ParkingSystem(int big, int medium, int small)
  {
    bigSLots = big;
    mediumSlots = medium;
    smallSlots = small;
  }
  /**
   * The function checks if there is available parking space for a given car type and returns true if
   * there is, otherwise false.
   * 
   * @param carType an integer representing the type of car being added to a parking lot.
   * 
   * @return a boolean value. It returns true if a car of the specified type can be parked in the
   * parking lot (i.e. there is an available slot of the appropriate size), and false otherwise.
   */
  bool addCar(int carType)
  {
    if (carType == 1 && bigSLots > 0)
    {
      bigSLots--;
      return true;
    }
    else if (carType == 2 && mediumSlots > 0)
    {
      mediumSlots--;
      return true;
    }
    else if (carType == 3 && smallSlots > 0)
    {
      smallSlots--;
      return true;
    }
    return false;
  }
};

/*
- Time complexity: O(1)
- Space complexity: O(1)
===========================
(English version)
** Problem explanation and problem solving method **
- Problem explanation:
+ Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.
+ Implement the ParkingSystem class:
  + ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
  + bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
- Problem solving method:
+ We can use the greedy algorithm to solve this problem.
+ We will keep track of the number of slots for each size.
+ We will iterate through the array and update the number of slots for each size.
+ The maximum profit will be the answer.
===========================
*/