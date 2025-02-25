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
// class A final {
  int a;

  public:
    A(int k) { a = k; }

    void same_copy() { cout << "A same_copy();\n"; }
    void same_name_diff_args() {}

    virtual void no_override() final {
      cout << "can't override after final keyword";
    }
    
    /**
     * A *ptr = new B;
     * delete ptr; should delete B and A's data. But early binding will only call A's destr. based on the ptr type.
     * Soln- Late binding (ptr's content is referenced first). ptr -> destructor call in B -> destructor call in A
     * Now both memory are released
     */
    virtual ~A() { }
};

// If class A is declared with final, error: a 'final' class type cannot be used as a base class
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

    void same_copy() { cout << "B same_copy();\n"; } // method overriding
    void same_name_diff_args(int x) {} // method hiding

    ~B() { }

    // void no_override() {} // error: cannot override 'final' function "A::no_override"
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

  b_obj.same_copy(); // compiler found in B, execute
  /**
   * b_obj.same_name_diff_args();
   * error- too few arguments in function call
   *      because compiler saw the func name in B.
   *      It searches the definition. If not found, error.
   *      It won't go to parent. That's why, this is method hiding. Parent method is hidden.
   *      Overloading is done in the same class.
   */

  A *derived_ptr; B b_obj2;
  derived_ptr = &b_obj2;
  derived_ptr->same_copy(); 
}