#include <iostream>

using namespace std;

class Student{
  // these 2 initially since Addr is just a blueprint
  int roll_no;
  string name;

  // same access rights as other members of Student
  // Student has no special access to Address.
  class Address {
    // not accessible outside
    int house_no;
    string street, city, state, pin_code;

    // can be accessed by Student
    public:
      void set_addr(int h, string &str, string &c, string &stt, string &p) {
        house_no = h;
        street = str, city = c, state = stt, pin_code = p;
      }

      void show_addr() {
        cout << "Address: " << house_no << ", " << street << ", " << city << ", " << state << " (" << pin_code << ")\n";
      };
  };

  Address addr; // now obj is created

  public:
  void set_roll_no(int r) { roll_no = r; }
  void set_name(string n) { name = n; }
  void set_address(int h, string str, string c, string stt, string p) { addr.set_addr(h, str, c, stt, p); }

  void show_student() {
    cout << "Student: " << roll_no << ", " << name << "\n\t";
    addr.show_addr();
  };

};

int main() {
  Student st1;
  st1.set_roll_no(11);
  st1.set_name("Foo");
  st1.set_address(72, "Street 2", "Blr", "Kar", "234567");

  st1.show_student();

  /**
   * If Address object is to be created, it has to be public: 
   *    Student::Address addr1;
   */
}