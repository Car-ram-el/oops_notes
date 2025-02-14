#include <iostream>

using namespace std;

int area (int, int);
float area (int);

class Integer {
  private:
    int x;
  
  public:
    void set_data (int a) { x = a; }
    void show_data () { cout << "int: " << x << "\n"; }

    // Unary operator overloading
    Integer operator++() { // 1. pre inc.
      Integer i;
      i.x = ++x;
      return i;
    }

    Integer operator++(int) { // 2. post inc. (differentiated by the param)
      Integer i;
      i.x = x++;
      return i;
    }
};

int main() {
  // // area of circle with first area function
  // int r;
  // cout << "Enter radius of circle: ";
  // cin >> r;
  // float circleArea = area(r); // early binding at compile time
  // cout << "Area = " << circleArea << endl;

  // // area of rect with second area function
  // int l, b, rectArea;
  // cout << "Enter length and breadth: ";
  // cin >> l >> b;
  // rectArea = area(l, b);
  // cout << "Area = " << rectArea << endl;
  // TODO uncomment

  Integer i1, preInc, postInc;
  i1.set_data(3);

  preInc = ++i1;
  postInc = i1++;

  preInc.show_data();
  postInc.show_data();

  i1.show_data();
}

int area (int x, int y) {
  return x * y;
}

float area (int r) {
  return 3.14 * r * r;
}