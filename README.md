[![Build Status](https://travis-ci.org/jean553/c-data-structures.svg?branch=master)](https://travis-ci.org/jean553/c-data-structures)

Taiga project: https://tree.taiga.io/project/jean553-jean553c-data-structures

# c-data-structures

Clone of https://github.com/jean553/data-structures in C.

## Requirements

### Ubuntu/Debian

```bash
apt-get install gcc cmake check
```

### Archlinux

```bash
pacman -S gcc cmake check
```

## Compilation

```bash
mkdir build && cd build/
cmake ..
make
```

## Tests execution

```bash
ctest --output-on-failure .
```

## Create individual libraries

In the example below, we create a library for the linked list.

```bash
cd linked_list/
gcc -c -fpic linked_list.c
gcc -shared -o liblinkedlist.so linked_list.o
```

Export the path for dynamic imports:

```bash
export LD_LIBRARY_PATH={directory of your *.so file}
```

## Documentation

### Installation

#### Ubuntu/Debian

```bash
apt-get install doxygen
```

#### ArchLinux

```bash
pacman -S doxygen
```

### Documentation generation

```bash
doxygen
```

# List of data structures

Lists:
 * linked list,
 * double linked list,
 * self-organized list, 
 * unrolled linked list,
 * XOR double linked list,
 * circular linked list,
 * skip list

Others:
 * vector - dynamic array,
 * hashmap

## Lists

NOTE: the following data structures have not been created in this project:
 * `tuples`: finite ordered list of items that can have different types, accessed by index or key, they are `structures` in C,
 * `fixed array`: finite ordered list of items that have the same type, accessed by index, they are `arrays` in C.

### Linked list

Each node contains the data itself and a pointer to the next node.

```
+-----------+-----------+          +-----------+-----------+           +-----------+-----------+
|           |           |          |           |           |           |           |           |
|   Data    |  Pointer  +--------> |   Data    |  Pointer  +---------> |   Data    |  Pointer  +------>  NULL
|           |           |          |           |           |           |           |           |
+-----------+-----------+          +-----------+-----------+           +-----------+-----------+
```

The implemented methods are:
 * create
 * insertAtTheEnd
 * insertAtTheBeginning
 * at
 * size
 * all
 * insertAfter
 * dropAt
 * dropAtTheEnd

Pros:
 * The size is not fixed
 * Read/Write is fast with small lists
 * Inserting/Removing does not require to copy the data itself (advantage with big objects)

Cons:
 * Read/Write is slow with long lists ( O(n) )

### Double linked list

Each node contains the data itself and two pointers.
The first one is pointing to the previous node,
the second one is pointing to the next node.

P : Previous
D : Data
N : Next

```
    +-----------------+      +-----------------+      +-----------------+
    |     |     |     |      |     |     |     |      |     |     |     |
 <--+  P  |  D  |  N  +--->  |  P  |  D  |  N  |  <---+  P  |  D  |  N  +-->
    |     |     |     |      |     |     |     |      |     |     |     |
    +-----------------+      +-----------------+      +-----------------+
              ^                 |           |                 ^
              +-----------------+           +-----------------+
```

The implemented methods are:
 * create
 * insertAtTheEnd
 * insertAtTheBeginning
 * insertAfter
 * at
 * size
 * all

Pros:
 * the size is not fixed
 * can be browsed in both directions
 * inserting/removing does not require to copy the data

Cons:
 * take more space than a simple linked list

### Self-organizing list

A simple linked list that automatically updates its nodes order.
The order is updated according to the usage frequency of each node.

The implemented methods are:
 * atWithMTF - like at() and applies `Move To Front` method
 * atTranspose - like at() and applies `Swapping` method

#### Move To Front

Everytime a node is requested, the node is moved to the head of the list.

Pros:
 * no additional data into the linked list (standard linked list can be used)

Cons:
 * not accurate: simply moves to the top every requested node,
the algorithm does not include any average consideration of nodes usage. 

#### Swapping method

Everytime a node is requested, the selected node is swapped with the previous one.

Pros:
 * accurate compare to MTF, nodes move according to the frequency they are requested and they move progressively to the head

Cons:
 * takes many accesses to move one node to the head

## Unrolled linked list

```
        +--------------------------------+
        | +----------------------------+ |
        | |    ||    ||    ||    ||    | |
        | | 0  || 1  || 2  || 3  || 4  | +----+
        | +----------------------------+ |    |
        +--------------------------------+    |
                                              |
  +-------------------------------------------+
  |
  |     +--------------------------------+
  |     | +----------------------------+ |
  |     | |    ||    ||    ||    ||    | |
  +---> | | 5  || 6  || 7  || 8  || 9  | +-->  NULL
        | +----------------------------+ |
        +--------------------------------+
```

The unrolled linked list is a linked list that contains arrays.
All the arrays have the same size, this size is set during the list creation.

Implemented methods:
 * createULL
 * atULL
 * insertAtTheEndULL

Pros:
 * access to an item by index can be faster because the last browsing step
is performed by array indexing,

Cons:
 * inserts in the middle are expensives (every item of arrays of all of nodes have to be shifted)

### XOR Double linked list

A double linked list that only uses one pointer per node to go to the previous or next node.
A bitwise XOR operation is applied on the node address field when inserting and reading;
by this way, the list can find the next or previous node.

```
+---------+  +---------+  +---------+  +---------+
|    a    |  |    b    |  |    c    |  |    d    |
+---------+  +---------+  +---------+  +---------+
| b XOR 0 |  | a XOR c |  | b XOR d |  | c XOR 0 |
+---------+  +---------+  +---------+  +---------+

+------------------------------------------------>

<------------------------------------------------+
```

Implemented methods:
 * create
 * insert
 * at

### Circular linked list

The circular linked list is a linked list without head and tail.
The last node simply points to the first one.

```
+----+        +----+        +----+
| 10 +----->  | 20 +------> | 30 |
+-+--+        +----+        +--+-+
  ^                            |
  |                            |
  +----------------------------+
```

Implemented methods:
 * create
 * insertAtTheEnd
 * insertAtTheBeginning
 * at

NOTE: In such kind of list, at(5) in the list [1,2,3,4] returns 2.

### Skip list

```
 +------+  +-------+                                +-----+
 | head |  |level 3+------------------------------> |  7  +------------------------------>  NULL
 +------+  +-------+                                +-----+
               |                                       |
               v                                       v

           +-------+                                +-----+                   +-----+
           |level 2+------------------------------> |  7  +-----------------> |  9  +---->  NULL
           +-------+                                +-----+                   +-----+
               |                                       |                         |
               v                                       v                         v

           +-------+                   +-----+      +-----+                   +-----+
           |level 1+-----------------> |  6  +----> |  7  +-----------------> |  9  +---->  NULL
           +-------+                   +-----+      +-----+                   +-----+
               |                          |            |         
               v                          v            v                         v
               
           +-------+      +-----+      +-----+      +-----+      +-----+      +-----+
           |level 0+----> |  4  +----> |  6  +----> |  7  +----> |  8  +----> |  9  +---->  NULL
           +---+---+      +--+--+      +--+--+      +--+--+      +--+--+      +--+--+
               |             |            |            |            |            |
               v             v            v            v            v            v
             NULL           NULL         NULL         NULL         NULL  
```

The skip list provides different lanes of nodes to access data quicly.
On each lane, every nodes are ordered by key. Every node points on one data item.
The nodes with the same key point to the same data item.

Implemented methods:
 * create
 * insert
 * at
 * all

## Others

### Vector - Dynamic array

An array is a set of continuous data in memory.
A vector is a dynamic array (the allocated size can vary).

```
     +-----------------------+
     |       |       |       |
     |   A   |   B   |   C   |
     |       |       |       |
     +-----------------------+
         ^
         |
         |
         |
         +
       ARRAY
```

The implemented methods are:
 * create
 * insertAtTheEnd
 * insertAt
 * updateAt
 * at
 * size
 * resize

Pros:
 * read and write is fast, because we use a pointer to directly jumps at the expected index

Cons:
 * the size is fixed because memory has to be allocated once in order to ensure that all the nodes are contiguous;
 * "dynamic" insertion requires to reallocate the memory
 * insert into the array requires to copy (shift) many nodes

### Hashmap

A hashmap is a map that stores data with unique key/value pairs.
When inserting data into the hashmap, a hash of the key is generated;
this hash is the 'address' of the data, used for future updates and research.

```


                                                          +------------------+
                                                          | 55  |            |
                                                          +------------------+
  {'key1':'value1'}  +--->   hash('key1') = 56   +----->  | 56  |   value1   |
                                                          +------------------+
                                                          | 57  |            |
                                                          +----------------------------------+
  {'key2':'value2'}  +--->   hash('key2') = 58   +----->  | 58  |   value 2  |     value3    |
                                                    |     +----------------------------------+
                                                    |
                                                    |                   ^               ^
  {'key3':'value3'}  +--->   hash('key3') = 58   +--+                   |               |
                                                                        |               |
                                                                        +---------------+
                                                                                |
                                                                                |
                                                                               ++
                                                                           Compare keys
                                                                           if collision

```

Insertion steps:
 * data is inserted using a key/value pair,
 * a hash of the key is generated by a common hash function,
 * the value is inserted at the hash address in the array (the key is inserted with its value),
 * if many keys have the same hash (collision), the new node is inserted just after the others (linked list),
 * both of the key and the hash method are used to find data (the keys of the same linked list are browsed if many nodes have the same hash)

Implemented methods:
 * create
 * insert
 * at
