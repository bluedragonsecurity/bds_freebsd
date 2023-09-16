#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	
	syscall(210);
	syscall(211);

	return 0;
}
