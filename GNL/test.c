//
// Created by viodid on 17/02/23.
//

#include "get_next_line.h"

int main()
{
	int fd;
	fd = open("/home/viodid/Documents/42-cursus/GNL/test1.txt", O_RDONLY);

    char *output = get_next_line(fd);
    //printf("%s\n", output);
    output = get_next_line(fd);
    //printf("%s\n", output);
    /*
    while (output)
    {
        printf("%s\n", output);
        free(output);
        output = get_next_line(fd);
    }
    */
	close(fd);
    free(output);
	system("leaks GNL");
	return (0);
}
