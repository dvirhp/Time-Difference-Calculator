# Time Difference Calculator 🕒

A utility for calculating and managing time differences between time points.

## 🔍 Overview

This program allows users to:
- Calculate time differences between two time points
- Support various time formats
- Process time data in multiple configurations
- Compare time periods and determine relationships

## ⚙️ Features

- **Time Comparison:** Calculate and display differences between two time points
- **Multiple Format Support:** Handle various time input formats
- **Relationship Analysis:** Determine if time periods overlap or are contained within one another
- **Error Handling:** Validate input and provide clear error messages for invalid time formats

## 💻 Usage

The program accepts commands to define time points and calculate differences between them:

```
# Example commands (syntax may vary based on implementation details)
time_diff time1 time2
compare_times period1_start period1_end period2_start period2_end
```

## 🛠️ Compilation & Execution

Compile the program using a standard C compiler:

```bash
gcc -Wall -ansi -pedantic *.c -o time_calculator
```

Execute the program:

```bash
# Interactive mode
./time_calculator

# With input redirection
./time_calculator < time_commands.txt

# With output redirection
./time_calculator > results.txt
```

## 📝 Input Format

Each command should be provided on a separate line. The program processes these commands sequentially and outputs the results of calculations or any error messages.

## 📚 Design

The program is designed with modularity in mind, separating the time calculation logic from the user interface. This allows for easy maintenance and potential extensions to support additional time formats or calculation methods.

## ⚠️ Error Handling

The system handles various error scenarios:
- Invalid time formats
- Logical errors in time comparisons
- Out-of-range time values

## 📋 Requirements

- C compiler compatible with ANSI C standard
- Command-line environment (terminal)
