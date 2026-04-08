
#include <stdio.h>
#include <string.h>

#define MAX 100

/* ── Data Structure ─────────────────────────────────────────────────────── */

struct Student {
    int   roll_no;
    char  name[50];
    float attendance;
} records[MAX];

int count = 0;

/* ── Helper: Print Table Header ─────────────────────────────────────────── */

void printHeader() {
    printf("\n%-10s %-25s %-15s\n", "Roll No", "Name", "Attendance(%)");
    printf("--------------------------------------------------\n");
}

/* ── 1. Insert Record ───────────────────────────────────────────────────── */

void insertData() {
    if (count >= MAX) {
        printf("[!] Database full! Cannot insert more records.\n");
        return;
    }
    printf("Enter Roll No      : ");
    scanf("%d", &records[count].roll_no);

    printf("Enter Name         : ");
    scanf(" %[^\n]", records[count].name);

    printf("Enter Attendance %%: ");
    scanf("%f", &records[count].attendance);

    count++;
    printf("[✓] Record inserted successfully!\n");
}

/* ── 2. Display All Records ─────────────────────────────────────────────── */

void display() {
    if (count == 0) {
        printf("[!] No records found.\n");
        return;
    }
    printHeader();
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %.2f%%\n",
               records[i].roll_no,
               records[i].name,
               records[i].attendance);
    }
}

/* ── 3. Bubble Sort (by Roll No, ascending) ─────────────────────────────── */
/*
 * Time Complexity  : O(n²) worst/average, O(n) best (already sorted)
 * Space Complexity : O(1) — in-place sort
 */

void sortData() {
    if (count == 0) {
        printf("[!] No records to sort.\n");
        return;
    }
    struct Student temp;
    int swapped;

    for (int i = 0; i < count - 1; i++) {
        swapped = 0;
        for (int j = 0; j < count - 1 - i; j++) {
            if (records[j].roll_no > records[j + 1].roll_no) {
                temp        = records[j];
                records[j]  = records[j + 1];
                records[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;   /* Early exit — already sorted */
    }

    printf("[✓] Records sorted by Roll No (Ascending):\n");
    display();
}

/* ── 4. Linear Search (by Roll No) ──────────────────────────────────────── */
/*
 * Time Complexity  : O(n) worst case
 * Space Complexity : O(1)
 */

void searchData() {
    if (count == 0) {
        printf("[!] No records to search.\n");
        return;
    }
    int key;
    printf("Enter Roll No to search: ");
    scanf("%d", &key);

    for (int i = 0; i < count; i++) {
        if (records[i].roll_no == key) {
            printf("[✓] Record Found!\n");
            printHeader();
            printf("%-10d %-25s %.2f%%\n",
                   records[i].roll_no,
                   records[i].name,
                   records[i].attendance);
            return;
        }
    }
    printf("[✗] Record with Roll No %d not found.\n", key);
}

/* ── 5. Delete Record ───────────────────────────────────────────────────── */

void deleteData() {
    if (count == 0) {
        printf("[!] No records to delete.\n");
        return;
    }
    int key;
    printf("Enter Roll No to delete: ");
    scanf("%d", &key);

    for (int i = 0; i < count; i++) {
        if (records[i].roll_no == key) {
            /* Shift remaining records left */
            for (int j = i; j < count - 1; j++) {
                records[j] = records[j + 1];
            }
            count--;
            printf("[✓] Record deleted successfully.\n");
            return;
        }
    }
    printf("[✗] Roll No %d not found.\n", key);
}

/* ── Main Menu ──────────────────────────────────────────────────────────── */

int main() {
    int choice;

    printf("\n========================================\n");
    printf("  Student Attendance Management System  \n");
    printf("========================================\n");

    do {
        printf("\n  MENU\n");
        printf("  ----\n");
        printf("  1. Insert Record\n");
        printf("  2. Display All Records\n");
        printf("  3. Sort Records (Bubble Sort)\n");
        printf("  4. Search Record (Linear Search)\n");
        printf("  5. Delete Record\n");
        printf("  6. Exit\n");
        printf("\n  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertData(); break;
            case 2: display();    break;
            case 3: sortData();   break;
            case 4: searchData(); break;
            case 5: deleteData(); break;
            case 6: printf("\n[✓] Exiting. Goodbye!\n\n"); break;
            default: printf("[!] Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
