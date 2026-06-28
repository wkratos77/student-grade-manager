# Student Grade Manager

![status](https://img.shields.io/badge/Status-In%20Progress-yellow)

⚠️ **Note:** This project is still under development and not yet finished.  
Features may change and improvements are ongoing.
---

A simple C program to manage students and their grades.  
You can add students, assign grades, list all students, and calculate averages.  
Built as a practice project for handling structs, arrays, and basic I/O in C.

## Quick Overview

- **Built with:** C
- **Focus:** Managing student grades, calculating averages, and displaying basic class statistics.
- **What I learned:** Structuring small programs, handling data, using arrays/structures, and organizing simple logic.
---

## Features
- Add new students (unique names, up to 100).
- List all students.
- Add grades (0–100) for a student (up to 20 per student).
- Show a student's average grade.
- Input handling with a simple text-based menu.

---

## Project Structure
```text
├── grade_manager.h   # Header file (structs + function prototypes) 
├── student.c         # Student-related functions (add/list/find/grades/average)
├── io.c              # Utility functions (strlen, putstr, putnbr, readline, atoi, etc.)
├── main.c            # Program entry point + menu
└── Makefile          # Build automation
```


---

## Build & Run

### Compile

```bash
make
```

### Run

```bash
./grade_manager
```

### Clean (remove .o files & binary)

```bash
make clean
```

---

## Example Usage
```bash
=== Student Grade Manager ===
1) Add student
2) List students
3) Add grade
4) Show student average
0) Quit

> 1

Student name: Walid
Added.

> 3

Student name: Walid
Grade (0-100): 40
Grade added.

> 3

Student name: Walid
Grade (0-100): 60
Grade added.

> 3

Student name: Walid
Grade (0-100): 80
Grade added.

> 4

Student name: Walid
Average of Walid: 60

> 0

y3awnrebi


```

---

## Notes

- Names must be unique and non-empty.

- Grades must be between 0 and 100.

- Each student can store up to 20 grades.

- The class can have up to 100 students.

---
