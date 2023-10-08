# Exercise 27: display_file

- Create a program called `ft_display_file` that display, on the standar output, only the content of the file given as argument.
- The submission directory should have a `Makefile` with the following rules: `all`, `clean`, `fclean`. The binary will be called `ft_display_file`.
- The `malloc` function is forbidden. You can only do this exercise by declaring a fixed-sized array.
- All files given as arguments will be valid.
- Error messages have to be displayed on their reserved output.

```text
$> ./ft_display_file
File name missing.
$> ./ft_display_file Makefile
*content of file Makefile*
$> ./ft_display_file Makefile display_file.c
Too many arguments.
$>
```

<br>

**Files to turn in:** Makefile, and files needed for your program<br>
**Allowed functions:** close, open, read, write

---
<br>

## ft_putchar.c

First of all, we will create the famous `ft_putchar.c` that will display only one character in the terminal. We will include the header `unistd.h` to have access to the function `write`.

```c
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
```
<br>

## ft_putstr.c

Now, we will create the function `ft_putstr.c` that will display all the `strings` messages of the program on the terminal. This function will call the function `ft_putchar()` to print all characters of the `string` and in the end will display a new line.

```c
void    ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}
ft_putchar('\n');
```
<br>

## ft_display_file.c

Then, we will create the principal function of the program: `ft_display_file`, it will have the `open` `read` and `close` functions, and it will `write` with the `ft_putchar()` function. We will include the header `unistd.h` to have acess to the functions `read` and `close`, and the header `fcntl.h` to have access to the function `open` and the file access mode `O_RDONLY`.

The `open` function will recive the name of the file and will try to open the file and return in the variable `filepos` the position of the file in the file descriptor. If it fails, the function will return 1 informing that something goes wrong.

<br>

- **ft_open()**

```c
int	ft_open(char *filename, int *filepos)
{
	if (open(filename, O_RDONLY) < 0)
		return (1);
	else
		*filepos = open(filename, O_RDONLY);
	return (0);
}
```

<br>

- **ft_read()**

The `read` function will read the file informed in the file descriptor and will read every byte and display each one. If the `read` function return something different from 1 it will break the will and stop displaying anything.


```c
void	ft_read(int filepos)
{
	char	c;

	c = '0';
	while ((read(filepos, &c, sizeof(char)) == 1))
		ft_putchar(c);
}
```

<br>

- **ft_close()**

The `close` function will close the file informed in the file descriptor.

```c
void	ft_close(int filepos)
{
	close(filepos);
}
```

We will define now the function that you be called by the main function. It will call the function `ft_open()`, `ft_read()` and `ft_close()`. If something goes right it will return 0 to the `main` function, if something goes wrong it will return 1.

<br>

- **ft_display_file()**

```c
int	ft_display_file(char *str)
{
	int	filepos;
	int	status;

	filepos = 0;
	status = ft_open(str, &filepos);
	if (filepos > 0)
	{
		ft_read(filepos);
		ft_close(filepos);
	}
	return (st name conventionatus);
}
```
<br>

## main.c

In the end, we will create the main function, that will manage all the rules. If args are equals 2 it calls the function `ft_display_file()` passing the path and the name of the file; if args are equals 1 it will return 1 and display the message "File name missing."; if the args are greater than 2 it will return 1 and display the message "Too many arguments.".

```c
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		return (ft_display_file(argv[1]));
	}
	if (argc < 2)
		ft_putstr("File name missing.");
	if (argc > 2)
		ft_putstr("Too many arguments.");
	return (1);
}
```
<br>

## Makefile

For now, we just need to create the `Makefile` that will compile all the program.

<br>

**The Variables:**
- Variable `NAME` constains the name of the program;
- Variable `SRCSDIR` constains the path of the sources;
- Variable `OBJSDIR` constains the path of the objects;
- Variable `FILES` constanis all the `.c` files of the project;
- Variable `CC` defines the compiler that will be used;
- Variable `CFLAGS` defines all the flags that will be used by the compiler;
- Variable `SRCS` includes the path of the sources to all the `.c` files;
- Variable `OBJS` includes the path of the objects and translate all the `.c` to `.o` files.

<br>

**The Targets:**
- Target `all` calls for the program `$(NAME)`;
- Target `$(NAME)` calls for the `$(OBJS)`, compile the program with the `$(CFLAGS)` and all `$(OBJS)` defining the program with the name `$(NAME)`;
- Target `$(OBJSDIR)/%.o` calls for each `$(SRCSDIR)/%.c` files, compile each one with the `$(CFLAGS)` and `-c` and define the name of each `.o` file with the `-o` flag;
- Target `clean` remove the `$(OBJSDIR)` and all the `.o` files;
- Targer `fclean` do the same as the `clean` and remove the program binary;
- Target `re` do the same as the `fclean` and remake the project with the target `all`.

<br>

**The .PHONY:**
- The target `.PHONY` defines all the targets that exists in the `Makefile`. If there are a program with the same name as the target in the directory the `make` could execute something wrongly. So defining the `.PHONY` we are saying that we want to execute the command, even if there are a file with the same name in the directory.

```makefile
NAME = ft_display_file
SRCSDIR = srcs
OBJSDIR = objs

FILES = main.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_display_file.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(FILES:%.c=$(SRCSDIR)/%.c)
OBJS = $(FILES:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@echo "Compiling $@"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
```
