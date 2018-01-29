//Brayden Fidler
#include "GrahamScan.h"


int main () 
{
	int numPoints = 0;
	int x = 0, y = 0;
  vector<Point> pointList;

	cout << "Enter points count: ";
	cin >> numPoints;

  //Checking to make sure enough points are entered.
	while (numPoints < 3) {

		cout << endl << "You must have at least 3 points for a convex hull." << endl;
		cout << "Please enter points count: ";
		cin  >> numPoints;
	}

  cout << endl << "Enter coordinates of points:" << endl;
  
  //Reading and adding points one by one
	for (int i = 0; i < numPoints; i++) {
		cin >> x;
		cin >> y;
		Point p(x,y);
		pointList.push_back(p);
	}
 
  //Sorting points and printing them
  moveLeftmostFirst(pointList);
  sortByAngleFromFirst(pointList);
  debugDump(pointList);
  
  //Printing convex hulls
  cout << endl << endl;
  shellIt(pointList);
  cout << endl;
}
