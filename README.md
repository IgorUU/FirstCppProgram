# C++ Tutorial

## Getting started

We will use VScode as our code editor of choice.

### Compilers

They transform our code into a format that can run directly on the hardware we will need compilers.
**Which compiler are we going to use depends on the operating system we are working in**.
As we our working in Ubuntu (Linux), we are going to use these 2 compilers:
- gcc / g++
- Clang llvm

It's best to install both compilers so we can test our code with multiple compilers.


Install **gcc**.

```
sudo apt-get install gcc-11
```

We also want to install **g++**.

While gcc is capable of compiling C++ programs with help of special flags, we should use g++ instead. The g++ compiler links to standard C++ libraries by default. GCC can also do that but not by default. To summarize, use GCC is for compiling C programs and g++ for C++.

```
sudo apt-get install g++-11
```

We will also need a **gdb** - debugger tool.

Gdb is a debugger for C (and C++). It allows you to do things like run the program up to a certain point then stop and print out the values of certain variables at that point, or step through the program one line at a time and print out the values of each variable after executing each line.

```
sudo apt-get install gdb
```

Install **clang** compiler.

```
sudo apt-get install clang-12
```

All this compilers/packages are installed in the */usr/bin* directory.

### Setup VScode for C++

Install extensions:
- C/C++ (Microsoft)

We want to configure tasks which are really a set of instructions to VSCode on how to turn our code into a binary that we can run.

**Terminal -> Configure Tasks...**

There we have a list of compilers.
We choose **g++-11** and after we click on it, it's going to create a new *tasks.json* file.

Change the **"label"** to **Build with GCC 11**.
In the **"args"** section add **"-std=c++20"** as a new argument, so that we can avoid some compiler errors for C++. Now, the argument section should look something like this:
```
"args": [
	"-fdiagnostics-color=always",
	"-g",
	"-std=c++20",
	"${workspaceFolder}/*.cpp",
	"-o",
	"${fileDirname}/rooster"
],

```
<sup>Other instructions on how to configure tasks.json can be found in C/C++ VScode extension.</sup>


**"${workspaceFolder}/*.cpp"** - compile every single .cpp file from the working directory.

**"${fileDirname}/rooster"** - the name of the binary output file.


After that, we select the file we want to compile (*main.cpp*) and click on **Terminal -> Run Task** from the toolbar and select the compiler that we want.
Then we get a message in the terminal that the build was finished successfully. We can see that we have a **new binary file** (*main*) in our folder structure.
We can run it by entering this command from the directory where the files besides.

```
./main
```

**DO THE SAME FOR CLANG!**

To enhance the developer experience even more click on the **View->Command Palette...** and type in C/C++: Edit configuration (UI).

For instance, we want to set our C++ standard to be c++20.

And that's pretty much it in terms of preparing our editor for working in C++.


### Online compilers

The most popular online compilers (at least from this tutorial) are:


- *Wandbox* - I like the most.
- *Compiler* Explorer - Transforms your code into assembly code.
- *Coliru*


## First C++ program

**#include** - includes the C++ library into our file.<br>
**\<iostream>** - C++ library for printing text in/out from the console. (std::cout, std::endl)

The **main** function is important because it's the <i>starting (entry) point</i> of our program. All the statemens in the main function are going to be executed in order.<br>
The main function usually returns 0, and that is a way that the function is sending a message to the operating system if it finished succesfully or not.

### Comments

**//** - Comments out a single line.<br>
<b>/* ... */</b> - Block comments out a block of text.<br>
Block comments can't be nested.<br>
Comments are used to document the code, but we shouldn't overdo it.

### Errors

We have 3 basic types:
- Compile time errors
- Runtime errors
- Warnings

Compile time errors, as the name says, are errors received in the compile process. If we have these kind of errors the binary file is not going to be created because the compile process is not finished succesfully.

Runtime errors are thrown after the compilation process finished succesfully and we got our binary file.
The problem is that our binary file is not working as it should.<br>
They are usually logical errors and they can crash the execution of our program.

### Statements and functions

A statement is the smallest thing a CPU can execute in our program.
Statements end with a semicolon in C++ (;).
They are executed in order from top to bottom when the program runs.
Execution keeps going until there is a statement causing the program to terminate, or run another sequence of statements.

![c++ function](/pictures/function.png)

### Input/Output

**std::cout** - Print data to the console (terminal).<br>
**std::cin** - Read data from the terminal.<br>
**std::cerr** - Print errors to the console.<br>
**std::clog** - Print log messages to the console.

One difference between printing and reading data in the terms of syntax is that **arrows are going LEFT when we want to print out (<<)** and **RIGHT when we want to read some data (>>)**.

Here are some printing out examples:
```
//Print stuff to the console.
std::cout << "Hello world" << std::endl;

std::cout << "The number is: " << 12 << std::endl;

int age {21};
std::cout << "The age is: " << age << std::endl;

//Error.
std::cerr << "std::cer output : Something went wrong" << std::endl;

//Log message.
std::clog << "std::clog output : This is a log message" << std::endl;
```


And reading data example:

```
int firstNumber;
int secondNumber;

std::cout << "Enter the first number: ";
std::cin >> firstNumber;
std::cout << "Enter the second number: ";
std::cin >> secondNumber;
std::cout << "The sum of those numbers is: " << addNumbers(firstNumber, secondNumber) << std::endl;
```

Another cool thing we can do with *std::cin* is **chaining input**.

```
int age;
std::string name;

std::cout << "Type in your last name and age, separated by spaces: " << std::endl;
std::cin >> name >> age;
std::cout << "Hello " << name << "! You are " << age << " years old." << std::endl;
```

We can have a problem with the code above if the user enters the full name, with spaces.
Like this:
- John Doe 32

Than we are going to have this printed out in the console:
```
Type in your last name and age, separated by spaces:
John Doe 32
Hello John! You are 0 years old.
```

We can solve that problem by using **getline()** function.

```
int age;
std::string full_name;

std::cout << "Type in your full name: " << std::endl;
std::getline(std::cin, full_name);

std::cout << "Type in your age: " << std::endl;
std::cin >> age;
std::cout << "Hello " << full_name << "! You are " << age << " years old." << std::endl;
```

And the output would be:

```
Type in your full name:
Igor Usumovic
Type in your age:
32
Hello Igor Usumovic! You are 32 years old.
```

## C++ Program Execution Model & Memory Model

Our binary files are being loaded in the RAM memory when we click two times on them,
or when we load them in our terminal.

 ![program execution and memory model](/pictures/memory_model.png)

## C++ core language VS Standard library VS STL

Example of **C++ core language** components are rules that we need to follow in order
for our program to be valid and compiled.
How we define variables and functions is a good example.
Those are some core features that are realy the foundation on what we build our
C++ programs.

**Standard library** is a set of ready-to-use components that we can implement in
our programs. <br>
\<iostream> (std::cout, std::cin), \<string> are some examples of standard librarie features. <br>

**STL** is a highly specialised part of a C++ Standard library.

## Variables and Data Types

Some of C++ Data Types are:
- int
- double
- float
- char
- bool
- void
- auto
- ...

### Number systems
Number systems allow us to transform the data that is in a form that is convinient
and readable for humans, to a form that is convinient for computers.
We can also use them vice versa.

We use the so called **Base 10** number system in our everday lives.
![the base 10 number system](/pictures/base_10.png)

And this is a reprsentation of **Base 2** number system which is used by the computers.

![the binary number system](/pictures/base_2.png)

 And here is an example on how we could represent the number 15 in different
 number systems in our C++ program.

 ![representation of the number 15 in different number systems in our C++ program](/pictures/different_number_representation.png)

As we can see, when we want to represent the number in the **Base 10** number system we enter the "original" value - 15.<br>
In **octal system** we use a **0** prefix and then append the octal value for that number which is 17, so at the end number 15 is represented like this 017.<br>
The **hexadecimal** representation uses the **0x** prefix.
The number 15 look like this 0x0f.<br>
And finally, the binary system uses the **0b** prefix and the binary represenation of the number 15 is this 0b00001111.

### Integers

They store WHOLE numbers (1,2, 34, 1020).<br>
Tipically, they occupy 4 bytes or more in memory, but mostly 4.<br>

<u>Types of variable initializations</u>

- Braced initialization
	- int lion_count{}; //Initializes to zero.
	- int cat_count{15}; //Initializes to 15.
	- int narrowing_conversion{2.9} // 2.9 is of type double, with a wider range than int. ERROR OR WARNING.

- Functional initialization
	- int apple_count(5);
	- int orange_count(10);
	- int fruit_count (apple_count + orange_count);
	- int narrowing_conversion_functional (2.9) // Information lost. Less safe than braced initializers.

- Assignment initialization
	- int bike_count = 2;
	- int truck_count = 7;
	- int vehicle_count = bike_count + truck_count;

	We can check the **size of a type** in the memory.
	```
	std::cout << "sizeof int: " << sizeof(int) << std::endl;
	```

### Integer modifiers

<u>Positive and negative numbers</u>

Integer variables are **signed** by default. <br>
That means that we can store positive and negative numbers in them.
```
int value1 {10};
int value1 {-300};
```

Is the same as
```
signed int value1{10};
signed int value1{-300};
```

But, if we want to put only positive numbers in our int variable then we use the **unsigned** modifier.

Something like this:
```
unsigned int value1{10};
```

If we enter a negative number in an unsigned variable we are going to get a compile error.<br>

It is interesting to show which range of numbers can we use *signed* and *unsigned* integers.
![number range in signed and unsigned integers](/pictures/number_range.png)

<u>Short or long</u>

| Data type | Size (in Bytes) | Meaning |
| :---			|	     :----:			|	 	 ---: |
| short	|	2	|	Used for small integers. Range -32768 to 32767.	|
| long | at least 4 | Used for large integers. Equivalent to long int. |
| unsigned long | 4 | Used for large positive integers or 0. Equivalent to unsigned long int. |
| long long | 8 | Used for very large integers. Equivalent to long long int. |

**Note**: These modifiers only apply to integral types: those in which you can store decimal or whole numbers.
It looks to me like it's only being used with integers. But, I am not sure, check this in future.


### Fractional numbers

Fractional numbers are also called **Floating point types** are just **Floating types**.<br>
Used to represent numbers with fractional parts in C++.<br>
There are 3 types that we can use in C++:
- float
- double
- long double

![Fractional number types in C++](/pictures/fractional_numbers.png)

The main difference between them is the size they take in the memory.

When we want initialize a variable which will be a *float* type, then we must add a suffix **f** to that number, otherwise it is going to be **double** by default.<br>
For long double its **L** suffix.<br>
And for the ordinary double, we don't need a suffix because that is the default value.

```
float number1 {1.12345678901234567890f}
double number2 {1.12345678901324567890};
long double number3 {1.12345678901324567890L};
```
In terms of the precision, as you can guess, the least precise is the float. <br>
Its precision is 7, and that means that it can show us up to 7 digits correctly. Everything else is junk. <br> Precision of double is around 15. <br> And the long double has a minimum precision of 15, 18, or 33 significant digits depending on how many bytes it occupies-

**Scientific notation** is a term used for representing realy huge numbers with this **e** sufix. <br>
For example, <br>
1.924e8 will be presented like 1.924 * 10<sup>8</sup>.

### Booleans

Not really much to say. They are true/false values. <br>
We cant find them helpfull in some conditional statements.

One boolean value occupies **one byte** of memory.

### Characters and text

```
char one_character{'i'};
```
Char occupies **one byte** in the memory. <br>
With one byte we can reperesent 256 possible values. <br>
Each value is matched to some character.

![ACII Table](/pictures/ascii_table.png)

### Auto

Auto is a keyword in C programming language. <br>
**auto** - Let the compiler deduce the type. <br>
This means that the compiler will ***automatically*** try to guess the type of the variable. For instance:<br><br>
```
auto var1 {12}; // int
auto var2 {12.0}; // double
auto var3 {12.0f}; // float
auto var4 {12.0l}; // long
auto var5 {'e'}; // char
auto var6 {123u} // unsigned
auto var7 {123ul} // unsigned long
auto var8 {123ll}	// long long
```

### Assignments

The whole point of this lesson is that we need to now what it means to **declare and initialize** a variable, and what it means to **assign** a new value to it.<br>

For example, if we don't have a variable with the name *var1* we can *declare* it and *initialize* it with some value like this:<br>

```
int var1{123}; // Declare and initialize
```

But if we already have a variable with that name, then we can assign it with a new value, like this:

```
var1 = 55; // Assign
```

We have to be carefull in situations where we declare a variable with the *auto* keyword. <br>
If we did something like this:<br>
```
auto var3 {333u};
```
Then we **CAN'T** assign that value with a negative number because we will get a **COMPILE ERROR** and we don't want that.

```
var3 = -22;
```

## Operations on data

### Basic operations

The basic opeations are
- add
- subtract
- divide
- multiply
- modulus

Everything is pretty basic here, except the part where we divide integer numbers, we have to be carefull there.<br>
If we want to divide 31 with 10, you maybe think that we will get some float number as a result, but you are not correct.<br>
We will get the number **3** as a result because that is an **integer** division and it will return an int.

### Presedence and Associativity

We need to have some set of rules on which operations are executed first if we have a situation like this:
![ACII Table](/pictures/presedence.png)

**Presedence** - which operation to do first. <br>
**Associativity** - which direction or which order.

There is a **C++ Operator Precedence** table so that we now which operators will get executed first.<br>
https://en.cppreference.com/w/cpp/language/operator_precedence

ADVICE: It is better to make the intent in your code as clear as possible by clearly using () to indicate which operations you want done first.

### Prefix and Postfix + and -

Nothing realy much to say here. It is a classic story of incrementation (value++) and decremenatation (value--).
