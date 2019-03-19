# Project 2 -- VTables and Advanced Assembly-Language Programming

This project will teach you about the manual implementation of virtual
method tables and have you implement several assembly language
functions that use more complex features of the ISA.

--

IMPORTANT: If you are on Mac OSX, you *MUST* rename the assembly
versions of `max` and `max_arr` to make your code work. This means
that you must do the following steps:

(1) When you want to edit and edit the code on your machine, you must
edit lab2.py to change `max` to `_max` (remember to change not just
the label but also the declaration after `.globl`). You must also
change `max_arr` to `_max_arr`.

(2) You should now be able to run the tests on your machine

(3) Before *submitting*, you must do the reverse: change `_max` back
to `max` and mutatis mutandis for `_max_arr`.

This is because OSX enforces that function names begin with a leading
underscore.

-- 

In the first part of the project you will be writing up an
implementation of virtual method tables ("vtables") by hand. To do
this, you will extend the implementation of `ShapesStructs.h` to
include the necessary provisions to implement virtual method tables as
described. You should look at `Shapes.h` to get an idea of how a
class-based implementation would work. However, you should never need
to call any methods (or construct any objects) from that file.

The second part has you write three functions. The first two
manipulate the string in the `str` field of the following struct:

```
struct Foo {
    char str[31];
    int  x;
    int  y;
};
```

Those functions are declared in C as follows:

```
// Assume that:
//   - foo is a valid pointer to a Foo struct
//   - `str` is a valid string
// 
// Ensure that:
//   - If the length of `str` is > 30, do nothing
//   - If length of `str` is <= 30, copy into foo.str
//   - For credit, this function must call the standard library's 
//   `strlen` function
//     (the TAs will check by  reading your code)
extern "C" void setStr(Foo *foo, char *str);

// Given a pointer to a Foo struct, find out the length of the string
// contained within it.
extern "C" int getStrLen(Foo *foo);
```

Since `strlen` is a standard C library function, you may call it using
the standard (System V ABI C linkage) calling convention: by loading a
pointer to the string into %rdi, and then performing `callq _strlen`.

Take care to write the functions correctly and obey the calling
convention: arguments are passed in the order specified, and you must
be sure to end the function with a `retq` instruction.

The third function is named `max`. Here is its declaration:

```
// Assume that:
//   - ptr is a pointer to an array of void pointers
//   - num is the number of elements in that array
//   - num >= 1
//   - cmp is a pointer to a function that returns:
//     0 if its first and second arguments are equal
//     >0 if its first argument is larger
//     <0 if its second argument is larger
// 
// Ensure that you return a pointer to the largest element in the
// array `ptr`. If the array has multiple elements that are equal, you
// may return a pointer to any of them.
extern "C" void *max(void **ptr,unsigned num, int(*cmp)(void *,void *));
```

In other words, this function takes an array of void pointers, the
number of elements in the aforementioned array, and a pointer to a
function named `cmp`. The job of your function is to return the
pointer to the largest element, as defined by the `cmp` function. For
example, consider the following test:

```
int cmp(void *x, void *y) {
    int x0 = *((int*)x);
    int y0 = *((int*)y);
    return x0 - y0;
}

int main() {
    int x = 0;
    int y = 1;
    int z = 2;
    void *arr[] = {&x,&y,&z};
    void *m = max(arr, 3, &cmp);
    if (m != &z) return 1;
    return 0;
}
```

It calls `max` to find the largest number in the array of `[&x, &y,
&z]`, and returns `&z`, since `z` is the largest number as defined by
max. Note that your `max` function *must* call its arugment `cmp` to
compare values. You should never be comparing the values directly,
only ever using the `cmp` function to do so.

To call a function through a pointer in assembly, you need to use a
special form of the `callq` instruction. For example, if `%rax` holds
a pointer to the function you want to call, and you have set up `%rdi`
and `%rsi` as the first two arguments, you can call the function
pointed to by `%rax` using the following syntax:

```
callq *%rax
```

You will have to do this to implement `max`.
