#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <netinet/in.h>

uint32_t reverse(char* argvs){
    FILE *fp;
    uint8_t buff[32];
    fp = fopen(argvs, "rb");
    fread(buff,1,32,fp);
    fclose(fp);
    uint32_t* res = (uint32_t *)buff;
    uint32_t conv = ntohl(*res);
    return conv;
}


int main(int argc, char* argv[]){
    if (argc < 3){
        printf("syntax : add-nbo <file1> <file2> \n sample : add-nbo a.bin c.bin");
    }
    else{
        uint32_t a = reverse(argv[1]);
        uint32_t b = reverse(argv[2]);
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a, a, b, b, a+b, a+b);
    }
}
