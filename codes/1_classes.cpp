#include <iostream>
#include <curses.h>
#include <string>

using namespace std;


// consumes no space for now. Like int's declaration consumes no space. Making a variable does.
struct book { 
  private: // secure data 
    int id;
    string title;
    float price;

  public:
    void input() {
      cout << "Enter book's details (id title price): ";
      cin >> id >> title >> price;
      if (id < 0) id = -id;
    }

    void display () {
      cout << "Book details: " << id << " " << title << " " << price << "\n";
    }
};

class Complex {
  // instance member variables & functions because they depend on instances to work
  private:
  int a, b;
  
  public:
  void set_data (int, int);

  void show_data () {
    cout << "Complex no. = " << a << " + " << b  << "i\n";
  }

  Complex add_complexes (Complex c) { // Complex operator+(Complex c) // Binary: Addition
    Complex temp;
    temp.a = a + c.a; // (a,b) belong to the object calling the function
    temp.b = b + c.b;

    return temp;
  }

  Complex operator+(Complex c) { // or whichever operators are defined in cpp. Binary operation here
    Complex temp;
    temp.a = a + c.a, temp.b = b + c.b;
    return temp;
  }

  Complex operator-() { // Unary: negation
    Complex temp;
    temp.a = -a, temp.b = -b;
    return temp;
  }

  friend Complex operator*(Complex, Complex);

  /**
   * Friend function for output <<
   * Return type:
   *      cout  << c1 << c2;
   *      Now cout << c1 should return cout type so that: cout << c2; remains
   *      Can't make an object of output stream. So return reference.
   */
  friend ostream& operator<<(ostream&, Complex c);
};

void Complex::set_data (int x, int y) { a = x, b = y; }

// no scope resolution because not a member
// just a normal function with access to the friend classes' vars.
Complex operator*(Complex c, Complex d) {
  Complex product;
  product.a = c.a * d.a, product.b = c.b * d.b;
  return product;
};

ostream& operator<<(ostream &op_object, Complex c) {
  op_object << c.a << c.b;
  return op_object;
}

int main(){  
  /**
   * guess what - cout is a predefined object
   * << = insertion, or put to, operator = inserts anInt in the o/p stream
   * << = extraction, or get from, operator
   */
  int x = 7; // at address let's say 1000
  int *p = &x; // 1000
  int &y = x; // y++ => x = 8


  int to_square; // data type declaration instruction
  cout << "Enter a number: "; // action
  cin >> to_square; // action

  int ans_square = to_square*to_square; // decl.
  cout << "Square of " << to_square << " is " << ans_square << "\n"; // action

  // Structs:

  book b2, inputB3; 
  // in order of (public) variables declared
  // b2.id = 102, b2.title = "A Systems Approach", b2.price = 300.5;
  inputB3.input();

  // Classes:
  // Object state: collection of values of object's properties

  Complex comp1, comp2, sum_comp3, diff_comp4, prod_comp5;
  comp1.set_data(11, 22);
  comp2.set_data(2, 3);

  sum_comp3 = comp1.add_complexes(comp2);
  // sum_comp3.show_data();

  // sum_comp3 = comp1.operator+(comp2);
  // caller obj - left operand
  sum_comp3 = comp1+comp2; 
  sum_comp3.show_data();

  // diff_comp4 = comp1.operator-();
  // caller obj - only operand
  diff_comp4 = comp1.operator-();
  diff_comp4.show_data();

  prod_comp5 = operator*(comp1, comp2);
  cout << prod_comp5;
  
  return 0;
}
