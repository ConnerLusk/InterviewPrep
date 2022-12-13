## Arrays
One memory block is allocated for the entire array to hold the elements of the array. The array elements can be accessed in constant time by using the index of the particular element. Accesssing array elements is contant time since the address of the element is computed as an offset from the base address of the array and one multiplication is needed to compute the adress of the wanted element.

$n^{th}$ $element = array$ $memory$ $address$ $+$ $n * data$ $size$

### Advantages of Arrays
- Simple and easy to use
- Fast access to the elements $O(N)$

### Disadvantages of Arrays
- Preallocates all needed memory up front and wastes memory spaces for indices in the array that are empty
- Fixed size: The size of the array is static
- One block allocation: To allocate the array itself at the beginning, sometimes it may not be possible to get the memory for the complete array if the array is too large
- Complex position-based insertion: To insert an element at a given position, may need to shift the existing elements

### Dynamic Arrays
Dynamic arrays are a random access, variable-size list data structure that allows elements to be added or removed. An example implementation is starting with a array of some fixed size and when it becomes full, create the a new array with double the size. Similarly reduce the array size to half if the elements in the array are less than half.
