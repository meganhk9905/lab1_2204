/* 
 * CS:APP Data Lab 
 * 
 *Name: Megan Kang
 *User ID: 107042352
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
 * Total: 25 pts
 */
/* 
 * 1-pt puzzles 
 */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
         
  return ~(~x | ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    //No two can be the same in xor
 //if we do n = x&y, from the bit ints x and y, only the 1's will remain through and when we do
 // the inverse of x and y will leave only the originally 0's as 1's. Therefore, if we inverse i and n, the bits
 //and do bit wise and, the bits that were both 1 will become 0 and the bits that had different bits will become 1 so 
 // it has the same functionality and xor
    int n = x & y;
    int i = ~x & ~y;
    int k = ~n & ~i;
    return k;
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
     // if x == 0, then !x == 1; if x != 0, then !x = 0;
  return !x;
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
    /* 
   * after left shift 16 and right shift 16, the left 16 of x is 00000..00 or 111...1111
   * so after shift, if x remains the same, then it means that x can be represent as 16-bit therefore the 
   xor will create a 0 which will then be converted to 1 by the ! operator. 
   We are looking to see if the 32 bit x can be represented as a 16 bit integer.
  */
  return !(((x << 16)>>16)^x);
}
/* 
 * 2-pt puzzles
 */
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
 //33 +~n can be written as k= 32 +(1+~n) . The (1+~n) is representing the negative value. To create 2's complement
 //we must inverse the bit integer and add 1. If we shift left then right by k,  if the value is positive, 
 // the left of the position n will be 0's and otherwise is will be 1's. Therefore, if the original x was
 //positive, the bit integer will not change after the shift which means that xor will yield a 0 and if we
 //apply !, it will return 1. This means that we can fit x in n bits as a 2's complement integer. Similarly with 
 //negative. 
    int k = 33 +~n;
  return !(x^((x<<k)>> k));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    /* shift right by the appropriate # of bytes until the desired byte is in LSB
   * then get rid of all leading bytes
   */
     //multiply n by 8 to chnage from # of bits to # of byte
    //then get rid of the leading bytes
  return (x>> (n<<3)) & 0xff;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
    //Xor already returns 0 if the two inputs are equal. Double negation
  //keeps this result and compacts all other possibilities to 1.
  
  return !(!(x^y));
}

int isequal(int x, int y) {
return !!(x&y);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */

int sign(int x) {
 //if x is a negative values, the msb is 1 so if we do an arithmatic right shift 31 times, the 1 will be copied 
 // in the place of the 32 bits. if x is negative, !!x will be 1 and if we perform or with the 32 bit integer
 // we will get a 32 bit integer that is full of 1's which will yield a -1. if x is 0, the right shift will 
 //copy all 0's and !!x will be 0 as well which will return a 0. If x is positive the right shift will yield 0's and 
 //!!x will be 1 so the or will return 1. 
    return ((!!x) | (x>> 31));
}

int isNegative(int x) {
  /*
   * simply test to see if the leading bit is 0 or 1.
   */

  // grab the leading bit
  x = (x >> 31) & 1;
  return x;
}
/* 
 * 3-pt puzzles 
 */
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
 
   int xn = ~x+1; //xn is x's negative value
   int yn = xn + y; /*negative if x > y, yn = y-x*/
   int sign = yn >> 31 & 1; /*shifts sign bit to the right. If yn is a negative value, the shifted bit 
   integer will be all 1's if yn is positive, then the integer will be full of 0's. So, if yn is negative, 
   sign will be -1, nd if yn is positive , the sign will yield 0*/
 //the next part is to handle the edge cases where x and y have different signs. If x is negative and y is 
 //positive, then the following will return 1. 
   int left = 1 << 31;
   int xl = left & x;
   int yl = left & y;
   int xor = xl ^ yl;
   xor = (xor >> 31) & 1;
 
   return (xor & (xl>>31)) | (!sign & !xor);
}

int isLess(int x, int y) {
  /*
   *11 ops
   * diff = x+(~y+1) : x-y
   * ~y&x : x<0, y>0 return 1
   * ~y|x : x>0, y<0 return 0
   * diff|(~x+y+1)) : x=y, x-y and y-x both equals 0, return 0
   * another way: 
   * int sx = x >> 31;               //sx is 1111...1 or 0000...0
   * int sy = y >> 31;               //sy is 1111...1 or 0000...0
   * int s_flag = sy ^ sx;           //s_flag = 0 when x's and y's significant bits are the same; s_flag = 1 when they are different
   * return (!(s_flag | (((~x)+ y) >> 31)) + (s_flag  & !(sy)));  //the first part !(s_flag | (((~x)+ y)>>31)) == (!s_flag & !(((~x)+y)>>31)), which is when x and y are '++' or '--'; the second part is when x and y are '+-' or '-+'. 
   *
   *
   */
  int diff = x+(~y+1);
  return (((((diff) | (~y&x)) & (~y|x))) >> 31) & 1;
}


/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
 //logical shift is when the remaining bits become 0's even though the msb is 1. so
 //if we do right shift by n, if x is a negative number, the right n bits will be filled with 1, 
 //therefore, we must do a bitwise and with (~(((1<<31)>>n)<<1)) which will mask the n bit 1's into 0's 
 //like how logical shift would operate. 
  return (x>>n)&(~(((1<<31)>>n)<<1));
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
 //
    int i = ~(~0 << n);//i is the bit integer that has 1's for n bits 
    int k = 33+~n;//k = 32 -n 
    k = (x >> k);// k becomes x after shifting k bits
    k = i&k;// if we do a bitwise and between k and i, the right n bits will be left and the rest will 
 //turn to 0's
  return k+(x<<n);// we shift x n bits and add k to finish rotating. 

}
int rotateRight(int x, int n) { 
  //shifts x by 32-n positions in order to get n bits to the front of the number.
 //Creates a mask of tmax and shifts that right by n-1 to create a mask that will remove the 
 //bits where the new bits will go. shift x by n to move the number over and and with mask to 
 //leave space for shifted 'rotated' bits. or the two together to get result
  int movingPart = x << (32 + (~n +1));
  int tmax = ~(1 << 31);
  tmax = tmax >> (n+((~1)+1));
  x = x >> n;
  x = x & tmax;
  return x | movingPart;
}
/*
 * 4-pt puzzles
 */
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value (Tmax), and when negative overflow occurs,
 *          it returns minimum negative value (Tmin)
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
 //add xor x's msb will be 0 if add and x have the same sign, and when the signs are different it will yield 1. 
 //when x and y are both positive but add is negative, or when x and y are both negative but add is positive, o will
 //yield 1. Therefore, if add xor x and add xor y's msb is 1, this means it overflowed and because o
 // copies the msb 1 when shifting, the 32 bit integer will be full of 1's. 
 //for the return statement, if o is overflowed, if add is negative then it will return the positive max value
 //and if it is positive it will return the negative min value. if o is 0,  there is no overflowing so it will
  //just return the add value. (if o is 0, o and 31 yields 0 so the original add + (o right shift 31) yield 0 vector 
 //so it returns the add value. 
    int add = x+y;
    int o=((add^x)&(add^y))>>31;
    return (add>>(o & 31)) + (o <<31);
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
 // set sign bit to 0 with mask AND uf variable
	// return argument if it is NaN, all NaN >= minimum NaN 
  unsigned m = 0x7FFFFFFF; //check NaN
  unsigned n = 0x7F800001; //set sign bit to 0
  unsigned ans = uf & m;   
  if (ans >= n)//check if Nan
    return uf;
  return ans;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    
    
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int e = uf & 0x7F800000;
  int s = uf & 0x80000000;
  int f = uf & 0x007FFFFF; 
  if (e == 0x7F800000) return uf; 
  if ((!e) || (e == 0x00800000)) {
     f = f | e;
     f = (uf & 0x00FFFFFF) >> 1;
     f += ((uf & 3) >> 1) & (uf & 1);
     return s | f;
     }
  return s | ((e - 1) & 0x7F800000) | f;
}
