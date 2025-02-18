#include <iostream>

using namespace std;

template <class X> class ArrayList {

  struct ControlBlock {
    int capacity;
    X *arr_ptr;
  };

  ControlBlock *s;

  public:
    ArrayList(int capacity) {
      s = new ControlBlock;
      s->capacity = capacity;
      s->arr_ptr = new X [s->capacity];
    }

    void add_elem(int i, X data) {
      if (i >= 0 && i < s->capacity) s->arr_ptr[i] = data;
      else cout << "Invalid index.\n";
    }

    void view_elem(int i, X &data) {
      if (i >= 0 && i < s->capacity) data = s->arr_ptr[i];
      else cout << "Invalid index.\n";
    }

    void view_list() {
      for (int i = 0; i < s->capacity; i++) cout << s->arr_ptr[i] << " ";      
    }
};

int main() {
  // ArrayList list1(7); errro: no instance of constructor "ArrayList" matches the argument list
  ArrayList <string> list1(3);
  list1.add_elem(0, "pr");
  list1.add_elem(1, "ad");
  list1.add_elem(2, "ya");
  string data;
  list1.view_elem(1, data);
  // cout << "data: " << data << "\n";
  list1.view_list();
}