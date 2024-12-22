#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include "Point.h"
#include "Shape.h"
#include "OneD.h"
#include "TwoD.h"
#include "ThreeD.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cone.h"

using namespace std;

// Count the number of each kind of Shape in the current list
void countShapes(const vector<Shape*>& shapes) {
 short lineCount = 0, circleCount = 0, rectangleCount = 0, 
  sphereCount = 0, cubeCount = 0, coneCount = 0;

 for (const auto& shape : shapes) {
  if (dynamic_cast<Line*>(shape)) {
	lineCount++;
	} else if (dynamic_cast<Circle*>(shape)) {
	 circleCount++;
	} else if (dynamic_cast<Rectangle*>(shape)) {
	 rectangleCount++;
	} else if (dynamic_cast<Sphere*>(shape)) {
	 sphereCount++;
	} else if (dynamic_cast<Cube*>(shape)) {
	 cubeCount++;
	} else if (dynamic_cast<Cone*>(shape)) {
	 coneCount++;
	}
}

 cout << "\nNumber of each kind of Shape in the list:\n"
	  << "Lines: " << lineCount << "\n"
      << "Circles: " << circleCount << "\n"
	  << "Rectangles: " << rectangleCount << "\n"
	  << "Spheres: " << sphereCount << "\n"
	  << "Cubes: " << cubeCount << "\n"
	  << "Cones: " << coneCount << "\n";
}

int main() {
 vector<Shape*> shapes;

 short choice;
do {
  cout << "\nMenu:\n"
   << "1. Create Shape\n"
   << "2. Print Shape Names\n"
   << "3. Print Shape Information\n"
   << "4. Remove Shape\n"
   << "5. Count Shapes\n"
   << "0. Exit\n"
   << "Enter your choice: ";
  cin >> choice;
  
switch(choice) {
 case 1: {
 // Create shape based on user input
 string name;
 short shapeType;
 double x, y, z, radius, length, width, height;
 Point point;

  cout << "Enter shape name: ";
  cin >> name;
  cout << "Enter point coordinates (x, y, z): ";
  cin >> x >> y >> z;
  point = Point(x, y, z);

	cout << "Select shape type:\n"
     << "1. Line\n"
     << "2. Circle\n"
	 << "3. Rectangle\n"
	 << "4. Sphere\n"
	 << "5. Cube\n"
	 << "6. Cone\n"
	 << "Enter choice: ";
	cin >> shapeType;

	// Create shape based on user input and add it to the container
	switch (shapeType) {
	 case 1: {
	  double x2, y2, z2;
	  cout << "Enter end point coordinates (x, y, z): ";
		cin >> x2 >> y2 >> z2;
		Point endPoint = Point(x2, y2, z2);
		shapes.push_back(new Line(name, point, endPoint));
	break;
	}
	 case 2: {
	  cout << "Enter radius: ";
	  cin >> radius;
	  shapes.push_back(new Circle(name, point, radius));
	break;
	}
     case 3: {
	  cout << "Enter length and width: ";
	  cin >> length >> width;
	  shapes.push_back(new Rectangle(name, point, length, width));
	break;
	}
	 case 4: {
	  cout << "Enter radius: ";
	  cin >> radius;
	  shapes.push_back(new Sphere(name, point, radius));
	  break;
	}
	 case 5: {
	  cout << "Enter side length: ";
	  cin >> length;
	  shapes.push_back(new Cube(name, point, length));
	break;
    }
	 case 6: {
	  cout << "Enter radius and height: ";
	  cin >> radius >> height;
	  shapes.push_back(new Cone(name, point, radius, height));
	break;
	}
	default: {
	  cout << "Invalid shape type.\n";
	break;
    }
   }
   break;
 }
 case 2: {
	// Print shape names
	cout << "\nShape Names:\n";
	  for (const auto& shape : shapes) {
		shape->print();
	  }
	break;
}
 case 3: {
	// Print shape information
	cout << "\nShape Information:\n";
	for (const auto& shape : shapes) {
	 shape->print();
	 cout << "Coordinates: (" << shape->getPoint().x << ", " 
	 << shape->getPoint().y << ", " << shape->getPoint().z << ")\n";
	}
	break;
 }
 case 4: {
 // Remove shape based on user input
   if (shapes.empty()) {
	cout << "\nNo shapes to remove.\n";
   } 
   else{
	string name;
	cout << "Enter the name of the shape to remove: ";
	cin >> name;

	auto it = shapes.begin();
	while (it != shapes.end()) {
	 if ((*it)->getName() == name) {
	  delete *it;
	  it = shapes.erase(it);
	  cout << "\nShape \"" << name << "\" removed successfully.\n";
	 } else {
	   ++it;
	 }
	}

	if (it == shapes.end()) {
	 cout << "\nShape \"" << name << "\" not found.\n";
	}
   }
 break;
 case 5: {
  countShapes(shapes);
 break;
 }
}
 case 0: {
   cout << "Exiting...\n";
   break;
 }
 default: {
   cout << "Invalid choice. Please try again.\n";
    break;
 }
 }
} while (choice != 0);

// Clean up memory
 for (auto& shape : shapes) {
	delete shape;
 }

 return 0;
}
