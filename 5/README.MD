# Section 5

## Linked lists

Linked lists are a datatype, which consists of **nodes** that are linked together. In C, the linking is achieved using pointers.

Linked lists come in two main types: Singly linked lists and Doubly linked lists.

A node in a singly linked list contains some value and a pointer to the next node.

A node in a doubly linked list contains some value and pointers to both the previous and the next node.

Typical node structure:

```
typedef struct node
{
    // just some form of data; could be a char* or whatever
    int i;

    // pointer to next node; have to include `struct` since this is a recursive definition
    struct node *next;

    // for a doubly linked list you would also have to have a pointer to the previous node.
}
node;
```

When inserting and deleting into a linked list, you have to keep track of the nodes around you.

example code: `linked.c`

## Hash tables

A hash table is essentially a collection of **buckets**, where you can store values.

Every hash table has to have a **hash function** associated with it. When you want to insert an element in to your hash table, you calculate a **key** using the hash function and the value of the element as the input for the function. You then insert the element to the **bucket** corresponding to the calculated key.

If you want to check if something is in your hash table you can calculate the key for that value and then look in the corresponding bucket.

A simple example of a hash table is a dictionary, where the letters of the alphabet are the keys for the buckets and the hash function returns the first letter of a word.

### What if a bucket is full?

If a bucket already has an element in it, then you have 2 options:

    1. Linear probing: Keep looking at the next bucket until you find an empty bucket

    2. Chain items: Instead of keeping an element in a bucket, each bucket instead holds a linked list of elements.


Hash tables don't improve the asymptotic runtime for looking up, deleting and inserting elements, but they do improve the actual runtime. A lookup time of 10s might not be asymptotically faster than a lookup time of 70s, but it's still a good speed improvement.


## Trees

A tree is a hierarchical data structure, consisting of nodes, that can themselves point to other nodes.

Ex:

```
        ( 55 )
        /    \
       /      \
     (33)     (77)
     / \       / \
    /   \     /   \
  (22) (44) (66)  (88)
```

In the above example, the node with value 55 is the **root** node. The root node has 2 **children nodes**. They are the nodes with values 33 and 77. The nodes on the bottom most level (with values 22, 44, 66, 88) are called **leaves**.

The above example is a special kind of tree: **Binary tree**. In a binary tree, every node has 0, 1 or 2 child nodes. The child node on the left must have a value less than the value of the parent node and the node on the right must have a value greater than the parent node. A binary tree is very useful for searching numbers, because if done correctly, it will give you a O(log n) lookup time.

The structure for a node in a binary tree would be:

```
typedef struct node
{
    // value of the node
    int value

    // left child
    struct node* left;

    // right child
    struct node* right;

} node;
```

## Tries

Tries are a special kind of trees, that are typically used to store strings. In a trie, each element represents a letter and whether the current path is a word or not. For example, let's say we have an alphabet with only the letters a, b and c. And we want to represent a dictionary with the words 'a', 'ab', 'ac' and 'aab'.

We could represent this with the 3 tries, each with the following structure (except the value of the root node would change to represent b and c):

```
                    (T) A
                   / |\
                  /  | \
                 /   |  \
                /    |   \
               /     |    \
              /      |     \
             /       |      \
            /        |       \
           /         |        \
          /          |         \
         /           |          \
        /            |           \
       /             |            \
      /              |             \
     (F)A           (T)B           (T)C
    / | \          / | \          / | \
   /  |  \        /  |  \        /  |  \
  /   |   \      /   |   \      /   |   \
 /    |    \    /    |    \    /    |    \
(F)A (T)B (F)C (F)A (F)B (F)C (F)A (F)B (F)C
```

The values in the other two tries would all be False, because no word in the dictionary begins with either b or c.

In general if you want to insert a string into a trie, you traverse the trie, taking the path that corresponds to the string and once you reach the end, you mark the corresponding node as true.

To lookup if a word is in a trie, you traverse the trie taking the corresponding path and finally check the value of the last node.


## Stacks and Queues:

Stacks are a datatype where the element that was added first gets removed last (FILO - First in, last out). Imagine a stack of dining hall trays. The bottom most tray got added in the first, but gets removed the last.

Queues are a datatype where the the element that was added first, gets removed first (FIFO - first in, first out). Imagine a line at the grocery store. The first person to get to the line also gets serviced first.

Both stacks and queues can be implemented using either arrays or linked lists. If using an array, you have to keep track of the current size of the stack/queue and its capacity in order to avoid overflowing.

Both stacks and queues have 2 main actions associated with them: pop and push. Pop removes an element from the stack/queue and returns it to the user. Push adds and element to the stack/queue.

## Huffman coding

All chars usually take 8 bits. We can make chars on average take less space, if we know how frequently they appear in the file.

General idea: If the letter 'c' appears very often, replace it with a shorter representation. To do this, we build a frequency tree to find encodings for each character. We start building the tree by choosing the letter with the smallest frequency and add it in to the tree. The value of the node is going to be the frequency of the letter.

EX: Let the following table represent the frequencies of all the letters that appear in a file:


| Letter        | A   | B   | C    | D    | E   |
| ------------- |:---:| ---:| ----:| ----:| ---:|
| Frequency     | 0.1 | 0.1 | 0.35 | 0.15 | 0.3 |

First we would add in A and B and would get:

```
         (0,2)
        0/  \1
        /    \
    (A, 0,1) (B, 0,1)

```

Notice that the letters can only be the leaves of the tree and all the other nodes in the tree have a frequency value equal to the sum of the frequency values of all of its children.

Now we would add in D:

```
              (0.45)
            0/     \1
            /       \
         (0,2)       \
        0/  \1        \
        /    \         \
   (A, 0,1) (B, 0,1)  (D, 0.15)

```

Finally we would add in E and then C and arrive at the following tree:

```
                           (  1  )
                         0/      \1
                         /        \
                    (0.65)         \
                   0/    \1         \
                   /      \          \
              (0.35)       \          \
            0/     \1       \          \
            /       \        \          \
         (0,2)       \        \          \
        0/  \1        \        \          \
        /    \         \        \          \
   (A, 0,1) (B, 0,1)  (D, 0.15) (E, 0.3)   (C, 0.35)

```

Now we can get the encoding for every character by following the tree. The encodings we get from this tree are the following:

| Letter        | A    | B    | C  | D    | E   |
| ------------- |:----:| ----:| --:| ----:| ---:|
| Encoding      | 0000 | 0001 | 1  | 001  | 01  |

Prefix property - No encoding is the prefix for another encoding. Thanks to this, we know that Huffman coding is deterministic. Notice that this holds for our tree.

In order to compress a file, you would replace the 8 bit representations of each character with their encoding. You would also have to store the encoding tree or table at the beginning of the file. Otherwise you won't be able to decode the file.
