#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

void nbo_add(uint16_t* a, uint16_t* b){
	uint32_t* v1 = reinterpret_cast<uint32_t*>(a);
	uint32_t* v2 = reinterpret_cast<uint32_t*>(b);	
	uint32_t h1, h2;
	h1 = ntohl(*v1);
	h2 = ntohl(*v2);
	uint32_t sum = h1 + h2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", h1, h1, h2, h2, h1+h2, h1+h2);
}


int main(int argv, char* argc[]){
	if(argv != 3){
		printf("Too Many Arguments\n");
		printf("syntax : add-nbo <file1> <file2>\n");
		return 1;
	}
	FILE* f1 = fopen(argc[1], "r");
        FILE* f2 = fopen(argc[2], "r");
	
	uint16_t n1[2];
	uint16_t n2[2];
	fread(n1, 1, 4, f1);
	fread(n2, 1, 4, f2);

	nbo_add(n1, n2);
	return 0;
}
