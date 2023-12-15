#include "shell.h"

/**
 * _myenv - writs the current env
 * @info: struct containing potential args. Used to keep
 *          constant function prototype.
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - generate the value of an env var
 * @info: struct containing potential args. Used to keep
 *          const func prototype.
 * @name: env var name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - begins a new env var,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        const func prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argumv[1], info->argumv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an envment var
 * @info: struct containing args. Used to keep
 *          const func prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argumv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Struct containing args. Used to keep
 *          const func prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; env[i]; i++)
		add_node_end(&node, env[i], 0);
	info->env = node;
	return (0);
}
