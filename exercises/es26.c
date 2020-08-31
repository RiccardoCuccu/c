#include<stdio.h>
#include<stdint.h>

int main(int argc, char *argv[]) {
	printf("Size of C data types:\n\n"                               );
	printf("Type                Bytes\n"                             );
	printf("-------------------------\n");
	printf("char                 %2lu\n", sizeof(char)               );
	printf("int8_t               %2lu\n", sizeof(int8_t)             );
	printf("unsigned char        %2lu\n", sizeof(unsigned char)      );
	printf("uint8_t              %2lu\n", sizeof(uint8_t)            );
	printf("short                %2lu\n", sizeof(short)              );
	printf("int16_t              %2lu\n", sizeof(int16_t)            );
	printf("uint16t              %2lu\n", sizeof(uint16_t)           );
	printf("int                  %2lu\n", sizeof(int)                );
	printf("unsigned             %2lu\n", sizeof(unsigned)           );
	printf("long                 %2lu\n", sizeof(long)               );
	printf("unsigned long        %2lu\n", sizeof(unsigned long)      );
	printf("int32_t              %2lu\n", sizeof(int32_t)            );
	printf("uint32_t             %2lu\n", sizeof(uint32_t)           );
	printf("long long            %2lu\n", sizeof(long long)          );
	printf("int64_t              %2lu\n", sizeof(int64_t)            );
	printf("unsigned long long   %2lu\n", sizeof(unsigned long long) );
	printf("uint64_t             %2lu\n", sizeof(uint64_t)           );
	printf("float                %2lu\n", sizeof(float)              );
	printf("double               %2lu\n", sizeof(double)             );
	printf("long double          %2lu\n", sizeof(long double)        );
	printf("_Bool                %2lu\n", sizeof(_Bool)              );
	printf("\n" );
	return 0;
}
