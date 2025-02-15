#include <iostream>

using namespace std;

class Array {
    int a[100];

  public:
    void insert (int i, int value) {
      a[i] = value;
    }
};

// Stack is-not Array => Private / protected inheritance.
class Stack: private Array {
  int top = 0;

  public:
    void push (int value) {
      insert(top, value);
      top++;
    }
};

// // ------------------------

class A {
  int a;

  public:
    A(int k) { a = k; }
    
    ~A() { }
};

class B : public A {
  int b;
  public:
    /**
     * B() : A() { }
     * error: no instance of constructor "A::A" matches the argument list
     * because it's expecting an arg since no default constr. now
     * 
     * B() { }
     * error: no default constructor exists for class "A"
     * compiler tries defaulting but can't find. Better is to code it.
     * 
     */

    B() : A(7) { }
    B(int x, int y) : A(x) { this->b = y; }

    ~B() { }
};

class Box {
  int l, b, h;

  public:
    void set_dimensions(int x, int y, int z) { this->l = x, this->b = y, this->h = z; }
    void show_dimensions() { cout << "dimensions: " << this->l << " " << this->b << " " << this->h << "\n"; }
};

int main() {
  Stack st1;
  st1.push(11);

  B b_obj(2, 3); // aim: x = 2, y = 3

  Box small, *obj_ptr, big;
  small.set_dimensions(3, 4, 5);
  big.set_dimensions(11, 12, 13); obj_ptr = &big;
  
  small.show_dimensions();
  obj_ptr->show_dimensions();
}