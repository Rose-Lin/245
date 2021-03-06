# Project 1 -- Interfaces, Abstract Classes, and Reallocating Arrays

This project will develop your skills on structuring object-oriented
software via class hierarchies. 

This project has you build an array implementation that gains
efficiency by doubling the array size (rather than just extending by
1) when the array needs to be extended. This will give you
implementation [constant amortized insertion
time](https://stackoverflow.com/questions/200384/constant-amortized-time)
time. I.e., if you perform `n` insertions, the runtime will be of
O(n), rather than O(n^2).

This project contains a few files, each implementing classes in a
class hierarchy you will flesh out:

- `IArray.h` -- This is an interface. Although C++ does not
  technically have an `interface` keyword (as in Java), the term
  "interface" refers to a class which has no concrete method
  implementations (i.e., every method is pure virtual) and contains no
  data members. You do not need to modify this file, but you should
  read it to get an idea of how the rest of the project works.

- `AArray.h` -- An abstract class (one which contains a mix of
  unimplemented and concrete methods) that implements a few methods
  using other methods (some of which are undefined). TODO: Extend
  `AArray.h`.

- `CArray.h` -- A slow (i.e., not-doubling-size) implementation of
  resizing arrays that will give O(n^2) time for `n` insertions. TODO:
  Extend `CArray.h`.

- `SArray.h` -- A faster (doubling-size) implementation of resizing
  arrays that will give O(n) time for `n` insertions.

Your job is to implement these last three classes.

You will need to read about:
- Exceptions and try
- Abstract classes
- Virtual methods
