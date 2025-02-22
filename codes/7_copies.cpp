#include <iostream>

using namespace std;

class Copies {
  int a,b, *ptr;

  public:
    void set_data (int x, int y, int z) { a = x, b = y, *ptr = z; } // value is assigned to the memory block
    void show_data() { cout << a << " " << b << "\n"; }

    Copies() {
      ptr = new int; // ptr is assigned a memory block to point to
    }
    Copies (Copies &c) {
      this->a = c.a, this->b = c.b;
      this->ptr = new int; // asign a new memory
      *(this->ptr) = *(c.ptr); // deep copy
    }
};

int main() {
  Copies obj1, obj3;
  obj1.set_data(11, 21, 31);

  Copies obj2 = obj1; // 1. object creation + init -> compiler calls copy constr.
  obj3 = obj1; // 2. just init with = calls overloaded copy assignment operator
  obj2.show_data();
}