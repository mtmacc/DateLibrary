# DateLibrary

## Overview

DateLibrary is a C++ library designed for handling and manipulating dates efficiently. It provides functionalities such as validation, leap year detection, date difference calculations, and calendar generation.

## Table of Contents

- Features
- Usage
- Installation
- Requirements
- Why Use DateLibrary?
- Contributing
- License
- Contact

## Features

- Validate if a date is correct.
- Check if a year is a leap year.
- Increment and decrement days, months, and years.
- Calculate the difference between two dates.
- Generate a full calendar for any given year.
- Display month names and weekday names.
- Optimized for efficiency and easy integration.

## Usage

Include the header file in your C++ project and start using the functions:

```cpp
#include "DateLibrary.h"
#include <iostream>
using namespace std;

int main() {
    DateLibrary date(6, 2, 2025);
    date.Print();
    date.Print("YYYY-MM-DD");

    cout << "Leap Year: " << (DateLibrary::isLeapYear(2024) ? "Yes" : "No") << endl;
    cout << "Days in February 2024: " << DateLibrary::DaysInMonth(2, 2024) << endl;

    return 0;
}
```

Expected Output:

```
06/02/2025
2025-02-06
Leap Year: Yes
Days in February 2024: 29
```

## Installation

1. Clone the repository:

```bash
git clone https://github.com/mtmacc/DateLibrary.git
```

2. Include `DateLibrary.h` in your C++ project.
3. Compile with:

```bash
g++ main.cpp DateLibrary.cpp -o my_program
```

## Requirements

- C++11 or later
- A C++ compiler (GCC, Clang, MSVC, etc.)

## Why Use DateLibrary?

- Simple and lightweight, easy to integrate into any C++ project.
- Highly optimized with efficient algorithms for date calculations.
- Modular and reusable for various applications.
- Well-documented for easy reference.
- Open-source under the MIT License.

## Contributing

Contributions are welcome. Fork the repository, improve the code, and submit pull requests.

## License

This project is open-source and available under the MIT License.

## Contact

For any inquiries or suggestions, reach out on GitHub.

