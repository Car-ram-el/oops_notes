`const` : Initialize at the same time. Can't change.

`const int mod = 1e5 + 7;`

If it's a class member, it can't be initialized during declaration, because it doesn't have memory / space until object creation.

### Initializer list
1. `const` data member can be initialized after colon(:).
2. Same with reference variable

### Copy

1. **Shallow copy**: Make a copy `c` of an object `o` by copying all data member vars
2. **Deep copy**: Shallow + values of memory resources outside but handled by `o`. E.g.
    - `obj1_ptr` is a data member that points to a memory block out of the obj scope. It can only be accessed by the pointer.
    - When calling default assignment operator for copying, compiler makes shallow copies. So variables get same values (`obj2_ptr` gets the same reference value, hence referencing the same memory location as `obj1_ptr` and sharing the same data).
    - Also, in case of shallow copy of such cases (both pointing to same block), deleting `obj1` would delete the reference, hence making `obj2`'s `ptr` point to garbage. Crash risk.


### Type conversion

#### Primitive data type
- Predefined. `int, char, float`
- Auto convert among themselves. Data might be lost (float -> int).