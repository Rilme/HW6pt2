/*
 * studentGrades.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_student_grade();

int main(int argc, char *argv[]) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	if (argc != 2) {
		printf("No grades to input.\n");
		return (-1);
	}

	int *student_grades;
	unsigned int num_items = atoi(argv[1]);

	student_grades = (int *) malloc(num_items * sizeof(int));

	if (NULL == student_grades) {
		printf("Could not allocate memory.\n");
		return -1;
	}

	for (unsigned int ctr = 0; ctr < num_items; ctr++) {
		printf("\nPlease input student %u's grade: ", ctr);
		student_grades[ctr] = get_student_grade();
	}

	for (unsigned int ctr = 0; ctr < num_items; ctr++) {
		printf("Student %u grade: %d.\n", ctr, student_grades[ctr]);
	}

	free(student_grades);

	return 0;

}

int get_student_grade() {
	int grade;
	int result = scanf("%d", &grade);

	if (result == EOF) {
		return 0;
	}

	if (result == 0) {
		while (fgetc(stdin) != '\n')
			;
	}
	return grade;
}

