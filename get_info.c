#include "shell.h"

/**
 * clear_info - begin info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argumv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - begin info_t struct
 * @info: struct address
 * @av: argument vec
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argumv = strtow(info->arg, " \t");
		if (!info->argumv)
		{

			info->argumv = malloc(sizeof(char *) * 2);
			if (info->argumv)
			{
				info->argumv[0] = _strdup(info->arg);
				info->argumv[1] = NULL;
			}
		}
		for (i = 0; info->argumv && info->argumv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: if freeing all fields->true
 */
void free_info(info_t *info, int all)
{
	ffree(info->argumv);
	info->argumv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->env);
			info->env = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
