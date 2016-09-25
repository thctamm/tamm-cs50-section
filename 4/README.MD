# Section 4

## Redirection

### Output
`>` - Takes the output of a program and prints it to a text file.

`>>` - Same as above, but appends to file, instead of overwriting.

`2>` - Same as above, but instead of printing STDOUT, prints STDERROR (error messages).

### Input

`<` - takes the contents of a file and uses it as input for the program.

### Pipe

`|` - Takes the output of one file and uses it as input for another one.

## Pointers

Pointers are addresses in memory.

Pointers are declared using `*`. For example, a pointer to an block of memory that stores an int would be of type `int *`. Similarly, a pointer to a block of memory that stores a char would be of type `char *`.

Arrays are actually pointers! `int[] numbers = {1, 2, 3}`, actually returns a pointer to the first element in the array.

In order to access something that a pointer points to, we use the **dereferencing** operator `*`.

Ex:
```
int *myNum = malloc(sizeof(int));
*myNum = 10;
```

In order to get the address of any variable we use the `&` operator.

Ex:
```
int a = 6;
int *b = &a;
```

Now `b` holds the address of `a` and is a pointer to `a`.

## File I/O

`fopen(filename, mode)` - used to open file with filename 'filename'. Returns a file pointer.
    Mode is:

    'r' - read

    'w' - write

    'a' - append

`fclose(filePtr)` - Closes the file pointed to by filePtr.

`fgetc(filePtr)` - Gets the next character from the file pointed to by filePtr.

`fputc(c, filePtr)` - Writes the character c to the file pointed to by filePtr. Returns c if sucessful.

`fgets(filePtr)` - Same as fgetc, but gets an entire string instead of one character.

`fputs(s, filePtr)` - Same as fputc, but writes an entire string instead of one character.

`fread(buffer, size, count, filePtr)` - Retrieves 'count' elements of size 'size' each from the file pointed to by filePtr and stores them in 'buffer'.
For reading 10 ints from file pointed to by filePtr:

```
int nums[10];
fread(nums, sizeof(int), 10, filePtr);
```

`fwrite(buffer, size, count, filePtr)` - Writes 'count' elements of size 'size' each from the 'buffer' to the file pointed to by filePtr.
For writing 10 ints to the file pointed to by filePtr:

```
int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
fwrite(nums, sizeof(int), 10, filePtr);
```

## Memory Management

### Stack
The stack is a contiguous block of memory set aside when a program starts running. Held in every stack frame is some metadata, any variables held in read-only memory, and most importantly, all local variables.

### Heap
All dynamically allocated memory (memory that is allocated at runtime) is put in the heap.

In order to get memory in the heap, we use `malloc`

Ex: `int *ptr = malloc(sizeof(int));`

This will return to us a pointer to a block of memory in the **heap** that is large enough to hold one int.

**All dynamically allocated memory must be freed before the program exits!**

In order to free dynamically allocated memory we use the `free()` function.

Ex:
```
int *ptr = malloc(sizeof(int));
free(ptr);
```


## Structs
Structs allow us to hold different kinds of variables in one package.

Ex: Let's say we want to make a variable that holds information about a Harvard student:

```
struct student
{
   char name[40];
   char house[20];
   int year;
}
```

To create a new student we would use: `struct student tim;`.

To set or get information from a struct we would use:

```
tim.name = "Timothy Tamm";
tim.house = "Currier";
tim.year = 2018;

printf("%s is in the class of %d", tim.name, tim,year);
```
