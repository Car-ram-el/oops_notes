// UNCOMMENT SECTIONS TO TEST

#include <fstream>
#include <iostream>

using namespace std;

class Init_list {
  int a, b, &ref_var;
  const int mod;

  public:
    Init_list(int &var): mod(1e5 + 7), ref_var(var), b(7) {}
};

int main() {
  // // Sec 1: OP
  // ofstream fout; // created fout = o/p stream
  // fout.open("new_file.txt"); // hard disk -> RAM if exists, else new file is created and opened.
  // fout << "hello world!"; // written when file is in RAM
  // fout.close(); // saved in hard disk


  // // Sec 2: IP
  // ifstream fin; // i/p stream
  // char ch;
  // fin.open("new_file.txt");
  // /**
  //  * cin: keyboard -> char
  //  * fin: file     -> char
  //  * 
  //  * default: ' ', tab are considered data separators
  //  *      not considered characters
  //  * fin >> ch; // helloworld!
  //  * use some other function that considers data separators
  //  */
  // while (!fin.eof()) {
  //   ch = fin.get();
  //   cout << ch;
  // }


  // // Sec 3: tellg
  // cout << fin.tellg(); // get ind: 0
  // fin >> ch; // read char, auto inc. ind to 1
  // cout << fin.tellg();

  // // tellp
  // ofstream fout;
  // fout.open("new_fie.txt", ios::app);
  // cout << fout.tellp();


  // // Sec 4: seekg
  // cout << "Initially > " << fin.tellg() << ": " << (char)fin.get() << "\n"; // ind = 0 -> 1
  // fin.seekg(3); // reset to 3
  // cout << "Reset to 3 > " << fin.tellg() << ": " << (char)fin.get() << "\n"; // 3 -> 4
  // fin.seekg(4, ios_base::cur); // ind += 4
  // cout << "Set cur + 4 > " << fin.tellg() << ": " << (char)fin.get() << "\n"; // 8 -> 9
  // fin.seekg(-2, ios_base::end); // 12 - 2 = 10
  // cout << "2nd from end > " << fin.tellg() << ": " << (char)fin.get() << "\n"; // ind = 10 -> 11

  // Sec 5: init. list
  int ref = 8;
  Init_list obj(ref);
}