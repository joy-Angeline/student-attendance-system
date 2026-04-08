# 🎓 Student Attendance Management System

A console-based **Student Attendance Management System** written in **C**, implementing core Data Structures concepts — **Bubble Sort** and **Linear Search** — on structured student records.

> **Course:** B25CSI201 – Data Structures  
> **Student:** Joy Angeline P | **Reg. No:** 711525BCS058

---

## 📋 Features

| # | Feature | Algorithm |
|---|---------|-----------|
| 1 | Insert student attendance record | — |
| 2 | Display all records in a formatted table | — |
| 3 | Sort records by Roll Number (ascending) | Bubble Sort — O(n²) |
| 4 | Search for a student by Roll Number | Linear Search — O(n) |
| 5 | Delete a record by Roll Number | Shift-left — O(n) |

---

## 🗂️ Project Structure

```
student-attendance-system/
├── attendance_management.c   # Full source code
├── Makefile                  # Build automation
├── sample_input.txt          # Sample test input
└── README.md                 # This file
```

---

## ⚙️ How to Compile & Run

### Using GCC directly
```bash
gcc attendance_management.c -o attendance_management
./attendance_management
```

### Using Make
```bash
make        # Build
make run    # Build & run
make clean  # Remove binary
```

---

## 🖥️ Sample Session

```
========================================
  Student Attendance Management System
========================================

  MENU
  ----
  1. Insert Record
  2. Display All Records
  3. Sort Records (Bubble Sort)
  4. Search Record (Linear Search)
  5. Delete Record
  6. Exit

  Enter your choice: 1
Enter Roll No      : 3
Enter Name         : Alice
Enter Attendance % : 88.5
[✓] Record inserted successfully!

  Enter your choice: 3
[✓] Records sorted by Roll No (Ascending):

Roll No    Name                      Attendance(%)
--------------------------------------------------
1          Charlie                   72.00%
2          Bob                       95.00%
3          Alice                     88.50%

  Enter your choice: 4
Enter Roll No to search: 2
[✓] Record Found!

Roll No    Name                      Attendance(%)
--------------------------------------------------
2          Bob                       95.00%
```

---

## 🔬 Algorithm Analysis

### Bubble Sort
- **Best Case:** O(n) — array already sorted (early exit with `swapped` flag)
- **Average / Worst Case:** O(n²)
- **Space:** O(1) — in-place

### Linear Search
- **Best Case:** O(1) — target is the first element
- **Worst Case:** O(n) — target is last or not present
- **Space:** O(1)

---

## 📝 Data Structure

```c
struct Student {
    int   roll_no;      // Unique identifier
    char  name[50];     // Student name
    float attendance;   // Attendance percentage (0–100)
};
```

Records are stored in a global array of size `MAX = 100`.

---

## 🧪 Test Cases

| Test | Input | Expected Output |
|------|-------|-----------------|
| Insert valid record | Roll: 1, Name: Alice, 85% | Record inserted ✓ |
| Display empty DB | (no records) | "No records found" |
| Sort 3 unsorted records | Rolls: 3, 1, 2 | Sorted: 1, 2, 3 |
| Search existing Roll No | Key = 2 | Record displayed |
| Search non-existent Roll No | Key = 99 | "Record not found" |
| Insert when DB full (MAX=100) | 101st insert | "Database full" |
| Single record sort | 1 record | No swap needed |

---

## 🚀 Future Enhancements

- Replace Bubble Sort with **Merge Sort** for O(n log n) performance
- Replace Linear Search with **Binary Search** (after sorting) for O(log n)
- Add **file persistence** to save/load records between sessions
- Build a **GUI** using GTK or a web front-end

---

## 📄 License

This project is submitted as part of academic coursework for B25CSI201 – Data Structures.
