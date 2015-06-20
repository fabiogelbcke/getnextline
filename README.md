# getnextline

Project get_next_line from 42

The goal was to create a function get_next_line with the following declaration:

int get_next_line(int const fd, char **str);

which takes a file descriptor and a pointer to a string, and stores the next line in the file pointed to by fd in the string, returning 1 for success, 0 for EOF, and -1 for error, so you could use it like

int fd = open(file_name, O_RDONLY);
char *str = NULL;

while (get_next_line(fd, str) > 0)
{
  printf("%s", str);
}

Functions allowed:

read, malloc and free ( no realloc :'( )
