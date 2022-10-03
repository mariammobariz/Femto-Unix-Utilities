#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buf[100];
    for (int i = 0; i < argc; i++) {
	printf("%s\n", argv[i]);
    }
    int fd_dest = open(argv[2], O_CREAT | O_WRONLY, 0644);
    int fd_src = open(argv[1], O_RDONLY);

    int read_count;

    while ((read_count = read(fd_src, buf, 100)) > 0) {
	write(fd_dest, buf, read_count);
    }

    remove(argv[1]);
    close(fd_dest);

    return 0;
}
