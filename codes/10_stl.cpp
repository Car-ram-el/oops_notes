#include <bits/stdc++.h>

using namespace std;

class Rectangle{
  int len, wid;

  public:
    Rectangle(int l, int w) { len = l, wid = w; }

    Rectangle():Rectangle(2,5) {} // constr. delegation
    
    int area() { return len*wid; }
};

int sum_with_var_params(int n, ...) {
  va_list v;
  va_start(v, n);

  int s = 0;
  for (int i = 0; i < n; i++) s += va_arg(v, int); // returns int
  
  return s;
}

int main() {
  // multiple values in pair = tuple
  tuple<string, int, float> tup = {"Cpp", 17, 19.2};
  cout << "tuple: " << get<1>(tup) << "\n";

  // vector
  vector<int> int_vec;
  for(int i = 0; i < 8; ++i) int_vec.push_back(i + 1);
  cout << "capacity of vector: " << int_vec.capacity() << "\n";
  int_vec.push_back(2);
  cout << "added 1 element and capacity doubled: " << int_vec.capacity() << "\n";
  cout << "size remained predictable: " << int_vec.size() << "\n";

  int_vec.pop_back();
  cout << "removed 1 element but capacity of vector: " << int_vec.capacity() << "\t(it doesn't reduce on pop)\n";

  // list: access sequentially. bidirectional.
  list<int> lst {18, 92, 37, 42, 12, 52};
  list<int>::iterator it_lst = lst.begin();
  
  cout << "list iteration: ";
  while (it_lst != lst.end()) cout << *it_lst++ << (it_lst == lst.end() ? "\n" : " ");
  
  // map
  map<int, string> late_init;
  late_init[67] = "gt";
  late_init[79] = "pa";
  late_init[20] = "rn";

  map<int, string> early_init {
    {28, "a"}, {67, "ty"}, {84, "dt"}
  };

  map<int, string>::iterator it;
  for(it = late_init.begin(); it != late_init.end(); ++it) cout << it->second << " ";

  // string
  string s1 = "hello", s2;
  char c_arr[] = " world";
  s2 = s1 + c_arr; // ok. mixed operands: 1 string, other- string / char[] / char
  cout << "\nstring + char[] = " << s2 << "\n";

  // Some funcs: `append(), replace(), find(), rfind(), c_str() : convert to char[], size()`
  s2 = "bello";
  cout << "subtraction of first occurrence of different chars: " << s2.compare(s1) << "\n"; // b - h = 2 - 8
  strcpy(c_arr, s2.c_str());

  // Lambda expressions
  [](int x, int y) { cout << "lambda: " << x << y << "\n"; }(2,3);

  auto print_str = [s1, s2]() { cout << s1 << s2 << "\n"; };
  print_str();

  // ptrs
  unique_ptr<int> smart_int(new int(5));
  cout << "value at smart int ptr: " << *smart_int;

  unique_ptr<Rectangle> smart_rect(new Rectangle(7, 2)); // smart ptr
  cout << "\narea of rect: " << smart_rect->area();

  unique_ptr<Rectangle> smart_rect2 = move(smart_rect); // transfer control
  // cout << "\tafter transfer: " << smart_rect->area(); // Segmentation fault
  cout << "\tafter transfer: " << smart_rect2->area();

  shared_ptr<Rectangle> shared_rect(new Rectangle(3, 5));
  cout << "\narea of rect 2: " << shared_rect->area();

  shared_ptr<Rectangle> shared_rect2 = shared_rect;
  cout << "\tshared rect ptr: " << shared_rect->area();
  cout << "\tshared rect2 ptr: " << shared_rect2->area();
  cout << "\nRef_count: " << shared_rect.use_count();

  cout << "\nsum of 3 elements: " << sum_with_var_params(3, 5, 2, 5);
  cout << "\nsum of 5 elements: " << sum_with_var_params(5, 2, 5, 2, 5, 8, 2, 2); // ignores others => 22; but if lesser => garbage
}