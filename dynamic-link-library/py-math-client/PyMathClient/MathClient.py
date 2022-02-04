#!/usr/bin/env python3
import os
import ctypes


BASE_DIR = os.path.dirname(os.path.abspath(__file__))


def LoaderDll():
    lib64 = ctypes.cdll.LoadLibrary(os.path.join(BASE_DIR, 'MathLibrary64.dll'))
    
    # Initialize a Fibonacci relation sequence.
    lib64.fibonacci_init(1, 1)
    
    # Write out the sequence values until overflow.
    while lib64.fibonacci_next():
        print("{}: {}".format(lib64.fibonacci_index(), lib64.fibonacci_current()))
    
    # Report count of values written before overflow.
    print("{} Fibonacci sequence values fit in an unsigned 64-bit integer.".format(fibonacci_index() + 1))


if __name__ == '__main__':
    LoaderDll()
