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

Example of C++ core language components are rules that we need to follow in order
for our program to be valid and compiled.
How we define variables and functions is a good example.
Those are some core features that are realy the foundation on what we build our
C++ programs.

Standard library is a set of ready-to-use components that we can implement in
our programs. <br>
\<iostream> (std::cout, std::cin), \<string> are some examples of standard librarie features. <br>

STL is a highly specialised part of a C++ Standard library.
