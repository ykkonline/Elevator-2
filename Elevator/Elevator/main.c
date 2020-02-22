#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>




int ChangeFloor(int currentFloor, int floors[]) {
	printf("\nWhat floors would you like to go to? Seperate floors by a comma and a space.\n");
#define MAXFLOORS 100
	int myTargets[MAXFLOORS];
	int a = 0;

	char* token;
	char raw[MAXFLOORS];

	fgets(raw, MAXFLOORS, stdin);
	scanf("%s", &raw);
	while ((getchar()) != '\n');

	token = strtok(raw, ", ");
	while (token != NULL) {
		myTargets[a] = atoi(token);
		a++;
		token = strtok( NULL, " \n" );
	}

	int b;
	for (b = 0; myTargets[b] != NULL; b++) {
		int i;
		if (myTargets[b] > floors[15] || myTargets[b] < floors[0]) {
			printf("\nPlease enter a valid number\n");
			ChangeFloor(currentFloor, floors);
		}
		else {
			if (myTargets[b] < currentFloor) {
				for (i = currentFloor; i >= myTargets[b]; i--) {
					currentFloor = myTargets[b];

					if (i != myTargets[b]) {
						printf("%d", floors[i]);
						printf(" ");
						currentFloor = i;

					}
					else if (i == myTargets[b]) {
						printf("%d", floors[i]);
						printf(" Ding!");
						currentFloor = i;
					}
				}
				return currentFloor;
			}
			else if (currentFloor <= myTargets[b]) {
				for (i = currentFloor; i <= myTargets[b]; i++) {
					currentFloor = myTargets[b];

					if (i != myTargets[b]) {
						printf("%d", floors[i]);
						printf(" ");
						currentFloor = i;

					}
					else if (i == myTargets[b]) {
						printf("%d", floors[i]);
						printf(" Ding!");
						currentFloor = i;
					}
				}
				return currentFloor;
			}

		}
	}
	
}
void RepeatFloor(int currentFloor, int floors[]) {
	printf("\nWould you like to go to another floor?\n");
	printf("YES or NO\n");

#define MAXYESNO 4
	char str[MAXYESNO];
	fgets(str, MAXYESNO, stdin);
	while ((getchar()) != '\n');

	if (strcmp(str, "YES") == 0) {
		ChangeFloor(currentFloor, floors);
	}
	if (strcmp(str, "NO") == 0) {

	}
	else {
		printf("\nPlease enter either YES or NO");
		RepeatFloor(currentFloor, floors);
	}
}

void StartElevator() {
	int floors[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int currentFloor = 0;
	printf("You are on floor ");
	printf("%d", currentFloor);
	ChangeFloor(currentFloor, floors);
}


int main() {
	int floors[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int currentFloor = floors[0];
	//int *floorsptr;
	//floorsptr = &floors;
	printf("You are on floor ");
	printf("%d", currentFloor);
	currentFloor = ChangeFloor(currentFloor, floors);
	RepeatFloor(currentFloor, floors);
	return 0 ;
}


