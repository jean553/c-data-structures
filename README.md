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
