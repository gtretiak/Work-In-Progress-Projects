#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	char	*arr[] = { "man", argv[1], NULL };
	char	*env[] = { "TEST", NULL };
	if (argc == 1)
		write(1, "Give me (an) argument(s)\n", 25);
	else
		execve("/bin/man", arr, env);
	return (0);
}

// EXEC has to be with l (list) or v (vector). P (path) and E (env) are optional.
//
// EXECL (list):
// execl("/bin/man", "/bin/man", argv[1], NULL);
//
// EXECLP (list and path):
// execlp("man", "/bin/man", argv[1], NULL);
// or just execlp("man", "man", argv[1], NULL);
//
// EXECLE (list and env):
// int	main(int argc, char **argv, char **envp)
// char	*env[] = { "TEST", NULL };
// execle("/bin/man", "man", argv[1], NULL, env);
//
// EXECV (vector):
// char	*arr[] = { "man", argv[1], NULL };
// execv("/bin/man", arr);
//
// EXECVP (vector and path):
// char	*arr[] = { "man", argv[1], NULL };
// execvp("man", arr);
//
// EXECVE (vector and env):
// int	main(int argc, char **argv, char **envp)
// char	*arr[] = { "man", argv[1], NULL };
// char	*env[] = { "TEST", NULL };
// execve("/bin/man", arr, env);
//
//
// EXECLPE and EXECVPE are NON-POSIX functions so they are not universally portable
// They might be compiled with -D_GNU_SOURCE (GNU extension), but they aren't available on all systems
