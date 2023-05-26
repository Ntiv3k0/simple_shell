#include "main.h"
/**
 * getspecial - wrap for getspecial static variable
 * Return: Address of shellvariable special
 */

ShellVar **getspecial()
{
	static ShellVar *special;
	return (&special);
}



ShellVar **getvars()
{
	static ShellVar *vars;
	return (&vars);
}
/**
 * _getpid - find PID of the current  process
 * Return: str of PID
 */

char *_getpid()
{
	char *s, *pid, *n;
	char *file = "/proc/self/status";
	int fd;
	s = malloc(256);
	if (s == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(s);
		return (NULL);
	}
	while (_getline(&s, fd))
	{
		n = _strtok(s, ":");
		if (!_strcmp(n, "Pid"))
		{
			pid = _strdup(_strtok(NULL, "\n \t"));
			free(s);
			close(fd);
			return (pid);
		}
	}
	free(s);
	close(fd);
	return (NULL);
}
