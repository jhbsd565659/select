#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>

void usage() {
	std::cout 
		<< "select version 0.1.1" << std::endl
		<< "" << std::endl
		<< "usage:" << std::endl
		<< "select [-a, [-d delimiter]] number" << std::endl
		<< "" << std::endl
		<< "number:" << std::endl
		<< "  print Nth column" << std::endl
		<< "-d:" << std::endl
		<< "  set delimiter character as column" << std::endl
		<< "-a:" << std::endl
		<< "  print all characters unless hit \\n" << std::endl
	;
	exit(EXIT_FAILURE);
}

int main(int argc, char ** argv) {
	if(argc <= 1) usage();
	char cmd[4096] = {0}, d[1024] = {0};
	char c = 0;
	int n = 0, p = 0, e = 0;
	bool l = false;
	d[0] = ' ';
	for(int i = 1; i < argc; ++i) {
		if(strcmp(argv[i], "-d") == 0) {
			if(argc < 4) usage();
			sscanf(argv[i + 1], "%s", &d[0]);
		}
		if(strcmp(argv[i], "-a") == 0) l = true;
	}
	sscanf(argv[argc - 1], "%d", &p);
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
		if(s) {
			auto a = strstr(s, d);
			char r[4096] = {0};
			if(a && ! l) {
				memcpy(r, s, a - s);
				puts(r);
			}
			else {
				puts(s);
			}
		}
		memset(cmd, 0, 4096);
		n = 0;
	}
	return EXIT_SUCCESS;
}

