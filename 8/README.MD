# Section 8

### Python

### Basics

Python is a much newer language than C. C was first released in 1972, Python in 1991.

Unlike a C program, which typically has to be compiled before you can run it, a Python program can be run without explicitly compiling it first.

In CS50 we use Python 3.

### Syntax basics:
Python doesn't use curly braces or semicolons. Instead scope is determined by **indentation**. More on this later.

In Python `#` is used for comments instead of `//`.

### Variables

In Python you don't have to specify a variables type and they are initialized by declaration only.

In C:
```
int a = 3;
char b = "c";
int arr[] = {1, 2, 3, 4};
char myString[] = "This is a string";
```

In Python:
```
a = 3
b = "c"
arr = [1, 2, 3, 4]
myString = "This is a string"
```

### Printing
Instead of using `printf`, you use the print function in Python.

In C:
```
int a = 7;
char b = "x";

printf("%d\n, a);
printf("%c\n, b);
```

In Python:
```
a = 7
b = "x"
print(a)
print(b)
```

The print method automatically adds a newline at the end. If you don't want that, you can use the following: `print("a string", end="")`, This wil print out "a string" without a newline at the end. This format can also be used to stick other stuff at the end of your print statement. For example `print("a string", end="c")` will print out "a stringc" without a newline in the end.

If you want to print out multiple variables at once, you can use multiple approaches:

In c:
```
int a = 7;
char c = 'x';

printf("%d, %c\n", a, c);
```

In Python:
```
a = 7
c = "x"

# Method 1
print(a, end = "")
print(", ", end = "")
print(c)

# Method 2
# Here we use the + operator to concatenate strings and the str function to convert other variables to strings.
print(str(a) + ", " + str(c))

# Method 3
print("{}, {}".format(a, c))
```

### Conditionals

`&&`, `||` are replaced with `and`, `or`. ! is replaced with `not`.

Conditions don't have to be inside parentheses, except for grouping.

Instead of using curly braces, we use a colon and indentation.


In C:
```
if (a == 7 || (b == 1 && c == 2))
{
    a = 12;
    // do something else
}

// This is no longer in the conditional
b = 1;
```

In Python:
```
if a == 7 or (b == 1 and c == 2):
    a = 12
    # do something else

# This is no longer in the conditional
b = 1
```

In Python `else if` is shortened to `elif`

In C:
```
if (a != 50)
{
    b = 1;
}
else if (b > 0)
{
    b = 0;
}
else
{
    b = -1;
}
```

In Python:
```
if a != 50:
    b = 1
elif b > 0:
    b = 0
else:
    b = -1
```

You can also use a conditional shorthand for assigning or returning values.

Ex:
```
isLetter = True if myLetter.isalpha() else False
```

### Loops

There are two main loops in Python: `while` and `for`

A while loop:
```
while a > 0:
    # Do something
```

A for loop can take on many forms. The simplest:

In C:
```
for (int i = 0; i < 50; i++)
{
    // Do something
}
```

In Python:
```
for i in range(50):
    # Do something
```
Or:
```
for i in range(0, 50):
    # Do something
```
Or:
```
for i in range(0, 50, 1):
    # Do something
```

A more complicated example...

In C:
```
for (int i = 1337; i > 50; i -= 3)
{
    // Do something
}
```

In Python:
```
for i in range(1337, 50, -3):
    # Do something

```

You can iterate over a list (The Python version of an Array) as such:

In C:
```
int vals[] = {4, 5, 6, 1, 2, 4, 2, 44, 5};
int sum = 0;
for (int i = 0; i < 9; i++)
{
    sum += vals[i];
}
```

In Python:
```
vals = [4, 5, 6, 1, 2, 4, 2, 44, 5]
sum = 0
for num in vals:
    sum += num
```

If you want to iterate over a list, but also get the current index, then you can use the `enumerate` method:
```
vals = [4, 5, 6, 1, 2, 4, 2, 44, 5]
for i, num in vals:
    print("the element at index {} is {}".format(i, num)
```

### Lists

Lists are the Python version of Arrays. They are a lot more powerful, since they can be dynamically grown or shrunk. They can also contain variables of multiple types.

#### Initialization

To initialize an array you use the square brackets:

`vals = []` - `vals` is an empty list

`vals = [1, 2, 3]` - `vals` contains the `int`s `1`, `2` and `3`.

If you want to initialize a large number of elements, then you can use a for loop inside the square brackets.

To initialize an array containing the number 1 through 100:
```
vals = [i for i in range(1, 101)]
```

To initialize an array of 1000 zeros:
```
vals = [0 for _ in range(0, 1000)]
```

Note: We use `_` in the for loop, because we don't actually need the variable.

A list can also be initialized using the `list()` function: `vals = list()`, will initialize vals as an empty list.

#### Appending, inserting and concatenating

you can add a value to the end of the list using the append method.

```
a = [1, 2, 3]
a.append(5)
# a is now equal to [1, 2, 3, 5]
```

You can insert a value at a specific place in the list using the insert method.
list.insert(i, x), will insert x before the i-th element in the list.

```
a = ["a", "b", "c", "d"]
a.insert(2, "derp")
# a is now ["a", "b", "derp", "c", "d"]
```

To stick one list to the end of another one, you can use the `+` operator:

```
a = [3, 4, 5]
b = [0, 1, 2]
c = a + b
# c is now [3, 4, 5, 0, 1, 2]

a.append(b)
# a is now [3, 4, 5, [0, 1, 2]]
```

Notice the difference between appending and adding two lists.

#### Length

To get the length of a list, you can use the len function:
```
a = [1, 2, 3, 4]
b = len(a)
# b is now 4
```
#### Sublists

In order to get a sublist of a list you can use the `:` operator inside square brackets.

In general `a[x:y]` will return the sublist of `a` starting at index `x` and ending at index `y`. If you omit `x` then you will get a sublist from the start of the list until the index `y`. If you omit `y`, then you will get the sublist that start at position x and ends at the end of the list.

For example:
```
a = [4, 5, 6, 7, 8]
b = a[1:]
# b is now [5, 6, 7, 8]

c = a[:3]
# c is now [4, 5, 6]

d = a[2:4]
# d is now [6, 7]
```

### Tuples
Tuples are a new kind of data type. They can hold multiple values, but are immutable. This means that you cannot change the values in a tuple once assigned. Tuples are declared using parentheses.

Ex:
```
a = ("meaning of life", 42)
# a[0] will return "meaning of life", a[1] will return 42
```

Note: Because tuples are immutable you can **not** do something like this: `a[1] = 43`, where a is a tuple.

Tuples can be easily unpacked when iterating over a list of tuples as follows:

```
constants = [
    ("meaning of life", 42),
    ("pi", 3.14),
    ("Tom Brady", 12)
]

for name, val in constants:
    print("the value of {} is {}".format(name, val))
```

### Dictionaries
Python has built in associative arrays called dictionaries. These allow you bind certain values to keys. Think of a dictionary as a list, where you can use any data type as the index, instead of just integers.

Dictionaries are declared using curly braces.

```
weather = {
    "England": "Rainy",
    "California": "Warm",
    "Florida": "Humid",
    "Estonia": "Cold AF"
}

# This will print out "humid"
print(weather["Florida"])

# This will change england's weather to windy
weather["England"] = "windy"
```

You can iterate over the keys of a dictionary usign a simple for loop:
```
for place in weather:
    print(place)
```

This will print out all of the places from the dictionary from the previous example. If you also want the values stored in the dictionaries, you can use the following:
```

for place, status in weather.items():
    print("The weather in {} is {}".format(place, status))
```

### Functions

Function are declared using the `def` keyword.

In C:
```
int square(int a) {
    return a*a;
}
```

In Python:
```
def square(a):
    return a**2
```

Note: In Python you can use the `**` operator to exponentiate values.

In Python functions don't have prototypes. As such, order matters. You should decalre functions higher up in your code than where you use them.

Python doesn't have a main function. You can simply start writing code in a `.py` file and it will get run. However if you still want a main function, then you can do the following:

```
def main():
    # do stuff

# this part is important to make sure main gets executed:
if __name__ == "__main__":
    main()
```

### Importing libraries

Instead of using `#include`, in Python you use the `import` keyword. There is a CS50 module (the Python term for a library) for Python, that you may or may not want to use. To include it write `import cs50` at the top of your file.

### Running

To run a Python file, write `python file.py`, where `file.py` is a placeholder for the name of your file.

### Command line arguments

In order to use command line arguments in Python, you have to import the `sys` package and then you can access the command line arguments using `sys.argv`.

For example:
```
import sys

for arg in sys.argv:
    print(arg)
```

If the following is saved in a file called `test.py` and it's run as such: `python test.py a b c`, then the program will print out:
```
test.py
a
b
c
```


### User input

You can get input from the user using the `input` method

```
a = input("input a number: ")
print("the square of your number is {}.format(a**2))
```
This will print out `input a number: ` in the console, wait for the user to input a number and then print out the square of the number (provided it's indeed a number).


## Classes and Objects

**Objects** are similar to **structs** in C, but besides holding values, they can also have methods associated with them.

**Classes** are what define what values an object will hold and what methods it will have associated with it. Think of a **class** as the recipe you use to make an **object**.

### Classes in Python

In Python, classes are declared using the `class` keyword.

Every class can have a `__init__` method, that defines how an object of this class should be initialized.

Note the `__` before and after the name of the method. In Python you surround a method name with double underscores, to indicate that it should be considered a private method (that shouldn't be called directly).

Every method in a class, must minimally take `self` as a parameter. This allows the object to manipulate values within in. When calling a method, the `self` parameter is omitted as it is assumed that it's the object itself.

Class names in Python start with an uppercase by convention.

It's good style in Python to keep class declarations in separate files.

Ex:

In `student.py`:
```
class Student():

    def __init__(self, name):
        self.name = name
        self.gradeSum = 0
        self.numGrades = 0

    def getGpa(self):
        return self.gradeSum / self.numGrades

    def addGrade(self, grade):
        if grade == "A":
            self.gradeSum += 4
            self.numGrades += 1
        elif grade == "B":
            self.gradeSum += 3
            self.numGrades += 1
        elif grade == "C":
            self.gradeSum += 2
            self.numGrades += 1
        elif grade == "D":
            self.gradeSum += 1
            self.numGrades += 1
        elif grade == "E" or grade == "F":
            self.numGrades += 1
        else:
            print("Invalid grade")

    def getName(self):
        return self.name
```

In `grades.py`:

```
from student import Student

tim = Student("Tim")
lisa = Student("Lisa")

tim.addGrade("A")
tim.addGrade("B")
tim.addGrade("B")
tim.addGrade("A")

tim.addGrade("E")
tim.addGrade("P")

lisa.addGrade("C")
lisa.addGrade("B")
lisa.addGrade("A")
lisa.addGrade("A")
lisa.addGrade("A")
lisa.addGrade("A")

print("{}'s GPA is: {}".format(tim.getName(), tim.getGpa()))
print("{}'s GPA is: {}".format(lisa.getName(), lisa.getGpa()))
```

## MVC

**MVC** or Model-View-Controller is a paradigm used in web development to separate responsibilities between different files and abstract away parts of the site that the user does not need to see.

**Model** - This is where the important data for the site lives, and it may be updated, referenced, or the like as part of the user experience. (Database)

**View** - These are the pages the user sees when they are interacting with your site, usually based on interaction with the model. (How the page looks)

**Controller** - This is where the so-called business logic of your site lives. Users may submit information to the controller, which will then decide what to present to the user. (Backend)

They interact as follows:

An **user** sends a request to the **controller**. the **controller** then queries the **model** for data. The **model** then transmits the data to the **view**, which then gets displayed to the **user**.

*These section notes are heavily based on slides by Doug Lloyd*
