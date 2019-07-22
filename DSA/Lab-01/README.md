# Department of Computer Science and Engg.- NITK Surathkal

## CS204 Data Structures and Algorithms Lab

### Assignment sheet- 1  Due Date: 29th July 2019

#### 1. Given a set of N distinct numbers, find the length of the longest monotone increasing subsequence. Note that the sequence need not be continuous.

##### Input Specification:

Input will contain two lines. The first line contains the number of integers in the sequence, N(<=1000) and the next line contains N positive integers (each <=109). 

##### Output Specification:

Print the length of the longest increasing subsequence of the given input sequence. 

```
Sample Input and Output
Input: 10
1 2 9 4 7 3 11 8 14 6
Output:6
Input: 6 
1 3 2 10 4 5
Output: 4
```



#### 2. A whole number is said to be CIRCULAR if, when you multiply the number by its units decimal digit, the result is the number with its decimal digits rotated to the right, where the units digit becoming its high-order digit.

 For example, 102564 is a circular number because of the multiplication:

102564*4 = 410256

##### Input Specification:

Input contains a single positive integer N(< 10). 

##### Output Specification:

Output must contain a smallest circular positive number whose units digit must be N. 

```
Sample Input and Output
Input: 2 
Output:105263157894736842
Input: 4
Output: 102564
```

Please note that result may not fit even in long long(64 bit integer). 

Please note that result may not fit even in long long(64 bit integer). 

#### 3. Find the square root of a positive integer using binary search. 

##### Input Specification:

Input will contain a single positive integer N input from keyboard, lesser than 10^9. 

##### Output Specification:

Print the square root of the number upto 4 decimal places. A difference upto 0.001 from the the judges solution will be accepted as correct. 

```
Sample Input and Output
Input: 5
Output: 2.2361
Input: 25
Output: 5.0000
```



#### 4. The task is to accomplish addition of two large positive numbers 

##### Input Specification:

There will be two positive integers (< 10^100) separated by a space. 

##### Output Specification:

Output must contain a single number representing the sum of the two integers. 

```
Sample Input and Output
Input: 323289329329392893 3283928392839283928932329
Output:3283928716128613258325222
Input: 10 99
Output: 109
```



#### 5. Given N(<=26) followed by N distinct characters, we can find all possible 2N words(sequence of characters) which preserve the ordering in the input (assuming that all words are valid words in the language). For example, if N is 3 and characters are A, B and C, the words in the alphabet order are A, AB, ABC, AC, B, BC and C. Your task now, is to find the index of the word in the dictionary. i.e, if input is AC, output is 4. You may avoid generating all the words and comparing the word with every word in the dictionary. 

##### Input Specification:

Input contains a number N representing the number of alphabets(<=26) followed by a space and N characters in the dictionary listed in lexicographic order and then a valid word present in dictionary. 

##### Output Specification:

Output must be the index of the word in the dictionary. 

```
Sample Input and Output
Input: 3 A B C AC 
Output: 4
Input: 3 A B C BC
Output: 6
```



#### 4. Given a positive integer (<= 1000000), find the minimum number of bits required to represent it as a binary number. 

##### Input Specification:

Input contains a single positive integer(< 106). 

##### Output Specification:

```
Output the minimum number of bits required for the representing in binary. 
Sample Input and Output
Input: 4
Output:3
Input: 16 
Output: 5
```

