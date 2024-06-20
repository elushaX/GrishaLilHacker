
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidUser(char* passcode) {
	// dont allow anyone
	return strcmp(passcode, "092837450293487509802384750") == 0;
}

int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("No passcode provided\n");
		return 1;
	}

	if (!isValidUser(argv[1])) {
		printf("Passcode '%s' is invalid!\n", argv[1]);
		return 1; // exit with error
	}


	printf("Very secret information - #23&*!^@bzzzbzz&)*\n");
	return 0;
}

