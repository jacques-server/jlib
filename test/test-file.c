#include <jio/jio.h>
#include <jlib/jlib.h>
#include <stdio.h>


#define TEST_FILE PACKAGE_TEST_DIR "/test-file.c"

int main(int argc, char *argv[])
{
    char *data = j_file_readall(TEST_FILE);
    printf("%s", data);
    if (data == NULL) {
        return 1;
    }
    j_free(data);

    if (!j_mkdir_with_parents("./hello-dir/world/linux", 0755)) {
        perror("");
        return 1;
    }
    return 0;
}