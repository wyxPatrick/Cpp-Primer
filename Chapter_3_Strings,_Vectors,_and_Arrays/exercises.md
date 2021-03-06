## 3-3. 
>Explain how whitespace characters are handled in the string input operator and in the getline function.

 * String input operator will separate the input by whitespaces.
 * `getline(is, s)` will separate input by newline `\n`. Whitespaces are ignored.

## 3-7.
>What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

If use type `char` instead of `char &`, `c` is a copy of each character of string `str`, not a reference. Thus, `str` will not change.

## 3-8.
>Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?

I prefer the range for. It is more concise.

## 3-9.
>What does the following program do? Is it valid? If not, why not?
```cpp
string s;
cout << s[0] << endl;
```

This code was dereferencing and printing the first item stored in `s`. Since `s` is empty, such operation is invalid.

## 3-10.
>Is the following range for legal? If so, what is the type of c?
```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */}
```

Depending on the code within the for loop. The type of `c` is `const char&`.

## 3-12.
>Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.
```cpp
vector<vector<int>> ivec;
vector<string> svec = ivec;
vector<string> svec(10, "null");
```

(a) It is legal. It is a vector of a vector of int.
(b) Illegal. ivec is a vector of int, not string.
(c) Legal. It is a vector of 10 "null" strings.

## 3-13.
>How many elements are there in each of the following vectors? What are the values of the elements?
```cpp
vector<int> v1;
vector<int> v2(10);
vector<int> v3(10, 42);
vector<int> v4{10};
vector<int> v5{10, 42};
vector<string> v6{10};
vector<string> v7{10, "hi"};
```

(a) size: 0, no values.
(b) size: 10, values: 0.
(c) size: 10, values: 42.
(d) size: 1, value: 10.
(e) size: 2, values: 10, 42.
(f) size: 10, values: "".
(g) size: 10, values: "hi".

## 3-18.
>Is the following program legal? If not, how might you fix it?
```cpp
vector<int> ivec;
ivec[0] = 42;
```

It is not legal.
```cpp
vector<int> ivec;
ivec.push_back(42);
```

## 3-19.
>List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

First way:
```cpp
vector<int> a = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
```

Second way:
```cpp
vector<int> b(10, 42);
```

Third way:
```cpp
vector<int> c{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
```

The second way is considered to be the best because it is the most concise solution.

## 3-26.
>In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) / 2;`?

There's no operator `+` for adding two iterators.

## 3-27.
>Assuming `txt_size` is a function that takes no arguments and returns an `int` value, which of the following definitions are illegal? Explain why.
```cpp
unsigned buf_size = 1024;
int ia[buf_size];  // Illegal. buf_size is not a constant expression
int ia[4 * 7 - 14];  // Legal.
int ia[txt_size()];  // Illegal. txt_size() is not a constant expression
char st[11] = "fundamental";  // Illegal. The size of st is 12, inluding the null.
```

## 3-28.
>What are the values in the following arrays?
```cpp
string sa[10];  // All elements are empty strings
int ia[10];  // All elements are zeors
int main() {
  string sa2[10];  // All elements are empty strings
  int ia2[10];  // All elements are undefined
}

## 3-29.
>List some of the drawbacks of using an array instead of a vector.

1. Size if fixed at compiling time.
2. No API as that of vector.
3. Bug prone.

## 3-30.
>Identify the indexing errors in the following code:
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)  // Exceed the range of the array
  ia[ix] = ix;
```

## 3-33.
>What would happen if we did not initialize the `scores` array in the program on page 116?

Values of array are undefined.

## 3-34.
>Given that `p1` and `p2` point to elements in the same array, what does the following code do? Are there values of `p1` or `p2` that make this code illegal?
```cpp
p1 += p2 - p1;
```

It moves `p1` with the offset `p2 - p1`. As long as `p1` and `p2` are legal, this operation will be legal.

## 3-37.
>What does the following program do?
```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
  cout << *cp << endl;
  ++cp;
}
```

It will print all characters in `ca`, but it will not terminate after printing the last character in `ca`. It is because there is no null character in it.

## 3-38.
>In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

Because there is no clear definition for addition of two pointers. It is not clear what the result represent for.


