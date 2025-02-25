`const` : Initialize at the same time. Can't change.

`const int mod = 1e5 + 7;`

If it's a class member, it can't be initialized during declaration, because it doesn't have memory / space until object creation.

Another way: `#define` preprocessor

`const` | `define`
| -- | --
constant identifier | preprocessor directive- symbolic constant
consumes memory acc. to data type | won't consume memory
part of language, hence part of compiler | not a part of language. It's a pre-compiler ( preprocessor directive - performed before compilation)

### Initializer list
1. `const` data member can be initialized after colon(:).
2. Same with reference variable

#### Const ptr
```cpp
int x = 11, y = 20;
const int* ptr = &x; // like const ... x; can't change x
++*ptr; // error: can't modify x value, can modify referenced var (x)
ptr = &y; // ok

int* const ptr2 = &x;
++*ptr2; // ok
ptr2 = &y; // error: ptr2 is constant this time

const int* const ptr3 = &x; // can't assign a new referenced var nor change value of x
```

#### Preprocessor directives (aka Macros)
Instructions to compiler beforehand

Most widely used - `#define`

```cpp
#define PI 3.14159
#ifndef // if not defined
    #define Stef_Boltz 5.671 * 1e-8
#endif

int main() {
    cout << PI; // compiler reads: cout << 3.14159
}
```

### Copy

1. **Shallow copy**: Make a copy `c` of an object `o` by copying all data member vars
2. **Deep copy**: Shallow + values of memory resources outside but handled by `o`. E.g.
    - `obj1_ptr` is a data member that points to a memory block out of the obj scope. It can only be accessed by the pointer.
    - When calling default assignment operator for copying, compiler makes shallow copies. So variables get same values (`obj2_ptr` gets the same reference value, hence referencing the same memory location as `obj1_ptr` and sharing the same data).
    - Also, in case of shallow copy of such cases (both pointing to same block), deleting `obj1` would delete the reference, hence making `obj2`'s `ptr` point to garbage. Crash risk.


### Type conversion

#### Primitive data type
[cppreference primitive types](https://en.cppreference.com/w/cpp/language/types)
- Auto convert among themselves. Data might be lost (float -> int).

### Exception handling
Handle unusual requests / user inputs
```cpp
try {
    ...
    throw constant_value_arg1;
    func(); // throw in its body will be caught in catch block.
    ... // won't run
}
catch (type1 any_costant_value_arg1) {...}
catch (type2 arg) {...}
...
catch (typen) {...} // arg is not useful
catch(...) { // or like _ in Haskell: catch-all
    // any throw type is caught. So use at the end.
}
```
`try` contains code that might throw exception.

<span style = "color:orange;">Use `throw` inside `try catch` (they are interdependent) block. Or within a function that's called inside the block. Not randomly outside.</span>

`throw` requires a data type (any) to throw a value. Without it, func terminates.

Compiler checks the catch with the same params. If it works, break out of the chain and move on.

`catch`: After catching exception, argument will receive `throw`'s value.

```cpp
try {
    ...
}
catch (Child_class c) {
    ...
}
catch (Parent_class p) {
    ...
}
```

#### Overriding exception class

```cpp
class My_exc : public exception {
  public:
    char* what() {
      return "Only method that can be overriden.";
    }
};

// function throws error
int Div(int a, int b) throw (int, My_exc) {
    if (!a) throw 1;
    if (!b) throw My_exc();
    return a / b;
}
```