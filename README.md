[![Build Status](https://travis-ci.org/jean553/c-data-structures.svg?branch=master)](https://travis-ci.org/jean553/c-data-structures)

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

## Linked list

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

## Double linked list

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

## Vector - Dynamic array

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
 * at
 * size
 * resize

Pros:
 * read and write is fast, because we use a pointer to directly jumps at the expected index

Cons:
 * the size is fixed because memory has to be allocated once in order to ensure that all the nodes are contiguous;
 * "dynamic" insertion requires to reallocate the memory
 * insert into the array requires to copy (shift) many nodes
