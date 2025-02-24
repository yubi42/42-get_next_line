# Get Next Line

## Introduction

Get Next Line (GNL) is a 42 School project that requires implementing a function to read a line from a file descriptor efficiently. The goal is to manage memory dynamically while handling multiple file descriptors.

## Features

- Reads a line from a file descriptor, including `stdin`
- Handles multiple file descriptors simultaneously
- Uses a buffer to optimize read operations
- Properly manages memory allocations and deallocations
- Supports variable buffer sizes

## Installation

### Prerequisites

- `gcc`
- `Make`

### Build

```sh
# Clone the repository
git clone https://github.com/yubi42/get_next_line.git
cd get_next_line

# Compile the library
make
```

## Usage

Include `get_next_line.h` in your project and compile with `get_next_line.a`.

### Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Error Handling

- Returns `NULL` in case of an error or end of file
- Handles memory leaks by freeing unused memory
- Validates file descriptors before reading

## Contributors

- yubi42

