# Lab 2 -- Basic Assembly-Language programming

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

In this lab you will be writing the assembly code to implement two
functions:

    // Calculate the maximum of {x,y,z}
    int max(int x, int y, int z);
    // Calculate the maximum element in array x with size s
    int max_arr(int *x, unsigned int s);

In writing the first, you will need to use (potentially multiple)
branches using comparisons (such as cmpq/cmpl) and jumps
(jg/jmp/je/etc...). In writing the second, you will need to use a loop
that reads the value of each x[i] up to the final index `s-1`.

The course notes contain an example of branching (and we went over one
in class). Additionally, the course notes also contain an example of
how you can use a loop to walk over an array. The only real trickiness
(explained in the comments) is learning how to manipulate 4-byte (int)
datatypes rather than 8-byte (long) data. You do this using the "long"
instructions, movl, cmpl, etc... and also using the long registers
%eax, %ebx, %ecx, and %edx.

To implement your assignment you will edit the code in `lab2.s`. This
file contains stubs for both of the functions you are supposed to
write. As both of them return integers, your job is to put the
necessary return value in the register %rax. Remember, %eax is the
lower 32 bits of %rax.

It is possible to call assembly code from C++ (and vice-versa). The
way that the tests work is to assume there are two assembly functions
`max` and `max_arr` that work as described. They are compiled like so:

    clang++ tests/public_test0.cpp lab2.s -o out

This tells the compiler to compile `tests/public_test0.cpp` and
assemble `lab2.s`, then link them both together. You can then run the
generated executable using the normal process:

    ./a.out

And then check its exit code. In developing your solution, I
*strongly* encourage you to use the GDB debugger. The easiest way to
do this is to use the virtual machine presented at the beginning of
class. However, you can also set it up to run on Mac OSX. I will post
a guide on how to do this on either Slack or the course webpage.

This assignment is due Tuesday, February 19th. DO NOT WAIT to
start. This is your first assembly assignment. While assembly itself
is not a very complicated language, learning the ergonomics can be
quite tricky (e.g., when to use movl vs. movq). You should also
remember that there isn't lecture on Wednesday, and I will be away for
most of the week. While I will post a video lecture, to some degree
you will be on your own to figure this out. Hence, you should really
treat this lab like a project.

Completing this lab took me about 45-60 minutes. I am not an expert
assembly programmer, and haven't touched it for around 12-14 months,
but I expect it will take you on the order of 4-8 hours (including
time to figure out how to set up and use GDB, etc..).

Good luck!
Kris
