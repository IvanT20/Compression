# Compression Project

## Overview

This project contains some file compressors that I have or will make.

## Installation

### Linux/MacOS

To compile the code, make sure you have the gcc compiler and Make utility tool. Afterwards, run the command:

```
make
```

You should now have an executable named `compressor`.

# Usage

To use the compressor run this command:

```
./compressor [flags] [file]
```

> By default the program will try to compress the file when no flag is provided.

## Flags

Currently, there is only one flag but I may add more in the future.

* **-d**: This flag tells the program to decompress whatever file you give it

# Current Plans

- Working on Huffman Compression
    - ~~Work on decompression~~ Finished
    - Refactor compression logic at some point
    - Optimize how the codes are stored
    - Possibly swap to Canonical Huffman Compression

