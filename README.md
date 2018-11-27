# fixed_size_ptr
Simple pointer wrapper to keep its size equals to 8 bytes (architecture-dependency free)



## Main uses

This wrapper is useful when two or more processes are communicating. If the transfered data struct contains some pointers (to shared memory, for example) is required the struct to have the same size in all applications (processes). This can be a problem if the applications weren't compiled in the same archecture.


## How to use
You just need replace your pointer of type `T` to: `fixed_size_ptr<T>`.

Examples:
`int* a = nullptr;` -> `fixed_size_ptr<int> a = nullptr;`

`void my_function(int* my_array, int length);` -> `void my_function(fixed_size_ptr<int> my_array, int length);`

