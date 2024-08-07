#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {

    struct stat st;
    int ret = stat("FichCreux.dat", &st);

    if (ret != 0) {
        perror("stat");
        exit(1);
    }

    printf("File size: %ld bytes\n", st.st_size);
    printf("Inode number: %ld\n", st.st_ino);

    printf("i_block array:\n");
    for (int i = 0; i < 15; i++) {
        printf("i_block[%d] = %lu\n", i, st.st_blocks + i);

    }

    return 0;
}
