#include "shell.h"

/**
 * get_env - returns the string array copy of our env
 * @info: Structure contains arguments. Used to keep
 *          csnt function prototype.
 * Return: 0
 */
char **get_env(info_t *info)
{
	if (!info->env || info->env_changed)
	{
		info->env = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->env);
}

/**
 * _unsetenv - Remove an env variable
 * @info: Structure contains arguments. Used to keep
 *        const function prototype.
 *  Return: delete->1,otherwise->0
 * @var: the string env var
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - begin a new env variable,
 *             or modifying an existing one
 * @info: Structure containing argum. Used to keep
 *        const function prototype.
 * @var: string env var
 * @value: value of the string env var
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
