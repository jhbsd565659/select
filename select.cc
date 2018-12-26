#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>

void usage() {
	std::cout 
		<< "select version 0.1.0" << std::endl
		<< "" << std::endl
		<< "usage:" << std::endl
		<< "select [-d delimiter] number" << std::endl
		<< "number:" << std::endl
		<< "  print nth column" << std::endl
	;
}

int main(int argc, char ** argv) {
	if(argc <= 1) {
		usage();
		return EXIT_FAILURE;
	}
	char cmd[4096] = {0};
	char c = 0;
	int n = 0, p = 0;
	char d[1024] = {0};
	int e = 0;
	if(strcmp(argv[1], "-d") == 0 && argc == 4) {
		sscanf(argv[2], "%s", d);
		sscanf(argv[3], "%d", &p);
	}
	else {
		sscanf(argv[1], "%d", &p);
		d[0] = ' ';
	}
	while(scanf("%c", &c) != EOF) {
		cmd[n++] = c;
		if(c != '\n') continue;
		if(cmd[n - 1] == '\n' || cmd[n - 1] == '\r') cmd[n - 1] = 0;
		if(cmd[n - 2] == '\n' || cmd[n - 2] == '\r') cmd[n - 2] = 0;

		char * s = nullptr;
		if(p == 1) s = &cmd[0];
		else {
			for(int i = 1; i < p; ++i) {
				s = strstr(!s ? cmd : s, d);
				if(s) ++s;
			}
		}
		if(s) puts(s);
		memset(cmd, 0, 4096);
		n = 0;
	}
	return EXIT_SUCCESS;
}

