#include "shell.h"

/**
 * list_len - gives length of linked list
 * @h: pointer to first nd
 *
 * Return: list's size
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first n
 *
 * Return: string's array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - writs all elements of a list_t linked list
 * @h: pointer to first nd
 *
 * Return: string's array
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns nd's string starting with prefix
 * @node: pointer to list's head
 * @prefix: string matched
 * @c: next character after prefix matched
 *
 * Return: nd matched | NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a nd
 * @head: pointer to list's head
 * @node: pointer to nd
 *
 * Return: index of nd | -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
