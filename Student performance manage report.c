#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char reg_no[50]; // Increased size to store long registration numbers
    int marks[3];
    int total;
};

void calculateTotal(struct Student *s) {
    s->total = s->marks[0] + s->marks[1] + s->marks[2];
}

void sortByTotal(struct Student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j].total < arr[j + 1].total) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findTopStudent(struct Student arr[], int n) {
    int i, topIndex = 0;
    for (i = 1; i < n; i++) {
        if (arr[i].total > arr[topIndex].total) {
            topIndex = i;
        }
    }
    return topIndex;
}

void display(struct Student arr[], int n) {
    int i;
    printf("\n--- Student Performance (Sorted by Total Marks) ---\n");
    for (i = 0; i < n; i++) {
        printf("\nRank %d:\n", i + 1);
        printf("Name: %s\n", arr[i].name);
        printf("Registration Number: %s\n", arr[i].reg_no);
        printf("Marks: %d %d %d\n", arr[i].marks[0], arr[i].marks[1], arr[i].marks[2]);
        printf("Total: %d\n", arr[i].total);
    }
}

int main() {
    struct Student s[5];
    int i;
    int d1, d2, d3;
    char reg[50]; // Increased buffer size

    printf("Enter details for 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("\nStudent %d Name: ", i + 1);
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("Student %d Registration Number: ", i + 1);
        fgets(s[i].reg_no, sizeof(s[i].reg_no), stdin);
        s[i].reg_no[strcspn(s[i].reg_no, "\n")] = '\0';
    }

    /* Extract last three digits from first student's reg no */
    strcpy(reg, s[0].reg_no);
    int len = strlen(reg);
    int d[3] = {0, 0, 0};
    int count = 0;

    for (i = len - 1; i >= 0 && count < 3; i--) {
        if (reg[i] >= '0' && reg[i] <= '9') {
            d[count] = reg[i] - '0';
            count++;
        }
    }

    d1 = d[0];
    d2 = d[1];
    d3 = d[2];

    /* Generate marks based on assignment rules */

    s[0].marks[0] = (d1 * 2) + 10;
    s[0].marks[1] = (d2 * 3) + 15;
    s[0].marks[2] = (d3 * 4) + 20;

    s[1].marks[0] = d1 + 10;
    s[1].marks[1] = d2 + 20;
    s[1].marks[2] = d3 + 30;

    s[2].marks[0] = d1 + 5;
    s[2].marks[1] = d2 + 10;
    s[2].marks[2] = d3 + 15;

    s[3].marks[0] = d1 * 2;
    s[3].marks[1] = d2 * 2;
    s[3].marks[2] = d3 * 2;

    s[4].marks[0] = d1 + 15;
    s[4].marks[1] = d2 + 25;
    s[4].marks[2] = d3 + 35;

    for (i = 0; i < 5; i++) {
        calculateTotal(&s[i]);
    }

    sortByTotal(s, 5);

    display(s, 5);

    int topIndex = findTopStudent(s, 5);
    printf("\n--- Top Student ---\n");
    printf("Name: %s\n", s[topIndex].name);
    printf("Registration Number: %s\n", s[topIndex].reg_no);
    printf("Marks: %d %d %d\n", s[topIndex].marks[0], s[topIndex].marks[1], s[topIndex].marks[2]);
    printf("Total: %d\n", s[topIndex].total);

    return 0;
}
