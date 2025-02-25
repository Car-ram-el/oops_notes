## 3 components:
### 1. Containers

Manage collection of objects of a type

*Container* lib provides containers to implement and replicate data structures (ds) like array, stack, linked list (ll), trees...

Implemented as generic class templates: can hold elements of any data type

E.g.- vector, queue, stack, priority_queue, list (replicates ll), set (replicates trees), map (associative arrays)

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

### Misc.
`auto` lets you declare a variable with a particular type whereas `decltype` lets you extract the type from the variable so `decltype` is sort of an operator that evaluates the type of passed expression.