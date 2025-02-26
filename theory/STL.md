## 3 components:
### 1. Containers

Manage collection of objects of a type

*Container* lib provides containers to implement and replicate data structures (ds) like array, stack, linked list (ll), trees...

Implemented as generic class templates: can hold elements of any data type

E.g.- vector, queue, stack, priority_queue, list (replicates ll), set (replicates trees), map (associative arrays)

_2 types of arrays: numeric (with normal indices- 0...) and associative (with custom indices (keys) that are associated with value)_

#### Classification
1. Sequence - array, ll
2. Associative - sorted ds: map, set
3. Unordered associative - unsorted ds
4. Containers Adapters - interfaces to sequence containers

`tuple` stores multiple heterogenous values
```cpp
tuple<string, int, float> t;
t = make_tuple ("Cpp", 17, 9.1);
get<2>(t); // use index to get values
```

`vector` - dynamic array
- Begins with size 1. Fill the vector.
- Add next element and it doubles in size.
- If initialized with s size: s -> 2s -> 4s -> 8s... (when it's filled and an element is pushed back, it doubles in size)
  - Only declaration: vector is of 0 size

`string` stores a sequence of chars. Terminated by a null character (\0), like a full stop.

- > `char[]` still exists because it's quicker due to lesser number of operations to be performed. But if init with size greater than declared size, it doesn't throw error. Risky!
`string` handles this.

- `string s1 = "abc"; // constr.- string s1("abc");`

- " " is a delimiter (separator).

### 2. Algorithms

Act on containers

Provide means for performing init, sort, search, transformation of containers' contents. Abstract these.

*Algorithms* lib has built in functions to perform complex algorithms on ds

E.g. `sort()`, `binary_search()`

### 3. Iterators

Step through the elements of collection of object (like containers or their subsets)

Point to containers

Bridge between 1. and 2.

E.g. `sort(v.begin(), v.end())` takes both iterators as params. Data type of `v` doesn't matter.

### Features
`auto` lets you declare a variable with a particular type whereas `decltype` lets you extract the type from the variable so `decltype` is sort of an operator that evaluates the type of passed expression.

`final` is used to restrict
1. Class inheritance
    - When base class doesn't make any derived classes and is the final / leaf class.
2. Method overriding
    - Sometimes you don't want to allow derived class to override the base class' virtual function. 

#### Lambda expressions
- For defining unnamed functions. Use `()` after curly braces or name the function and use.
- `auto func = [capture list] (params) -> return_type { body };`
  - `[&]` to capture and modify vars in the function's scope. Even `[&x, &y]` works for specific vars.
  - `return_type` is identified by default, but write for clarity.

#### Pointer disadvantages
1. Uninitialized ptrs
    - Only declaration: stores garbage address. Don't use until initialized with some location.
    - Methods of init:
      1. `int x = 10; int* ptr = &x;` after var init
      2. `int* ptr = (int*) 0xada011;` typecast hexadecimal code - int*. Used in systems programming.
      3. `int* ptr = new int[5];` dynamic
2. Memory leak
    - If memory isn't deallocated but ptr is destroyed, var has no way of access. Leak.
    - `delete ptr` frees the var space, `ptr = nullptr;` makes it independent of the var. Freed.
3. Dangling ptrs
    - `ptr` is initialized but memory is somehow deallocated.
    - E.g. 2 pointers point to same location. ptr1 deletes the memory but ptr2 still points to that address. Dangles.


| Smart ptrs | Shared ptrs
| -- | --
Auto deallocate memory when ptr goes out of scope | =
Only 1 ptr can point to the object at a time | More than 1 can point to the object
| Control can be transferred to another | Maintains a `Ref_count` (accessed by `use_count()`)

#### Weak ptr
Like `shared`, but no `Ref_count`.

It doesn't have a strong hold on the object (else they might form deadlocks - holding the object and requesting resources).

#### Ellipsis (...)
For taking variable number of arguments.