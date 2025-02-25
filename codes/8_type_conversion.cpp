#include <iostream>

using namespace std;

class Complex {
    int c, d;
  
  public:
    Complex() {} // default constr.
    Complex (int x) { c = x, d = 0; } // 1.

    operator int() { // 2.
      return c;
    }

    // operator Real() { // 3b.
    //   Real res;
    //   res.setR(c), res.setS(d);
    //   return res;
    // }

    int getC() { return c; }
    int getD() { return d; }

    void set_data (int x, int y) { c = x, d = y; }
    void show_data() { cout << c << " + " << d << "i\n"; }
};

class Real {
  int r, s;
  
  public:
    Real() {} // default
    Real(Complex com) { r = com.getC(), s = com.getD(); } // 3a. custom funcs because vars are private

    void setR(int x) { r = x; }
    void setS(int x) { s = x; }
    void show_data() { cout << r << " + " << s << "j\n"; }
};

int main() {
  Complex p_to_c, c_to_p, c_to_c;
  int x = 7;
  /**
   * 1. primitive -> class type conversion
   *    x         -> Complex
   * soln: constr. is called when assigning value
   * on the left operand i.e. class
   * ~ > p_to_c.Complex(x)
   */
  p_to_c = x;
  p_to_c.show_data();


  c_to_p.set_data(91, 93);
  /**
   * 2. class type -> primitive
   *    Complex    -> y
   * soln: casting operator
   * on the right operand i.e. class
   * syntax in class:
   *     operator return_type() {
   *        return return_type;
   *     }
   * ~ > y = c_to_p.operator int()
   */
  int y = c_to_p;
  cout << y << "\n";


  Real real1;
  c_to_c.set_data(81, 35);
  /**
   * 3. class type -> class type
   *    Real       -> Complex
   * This can be done by 1. / 2.
   */
  real1 = c_to_c;
  real1.show_data();
}
