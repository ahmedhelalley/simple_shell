#include "shell.h"

/**
 * get_node_index - gets the index of a node
 * @h: pointer to list head
 * @n: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *h, list_t *n)
{
	size_t j = 0;

	while (h)
	{
		if (h == n)
			return (j);
		h = h->next;
		j++;
	}
	return (-1);
}

/**
 * list_len - determines length of linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *head)
{
	size_t j = 0;

	while (head)
	{
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @h: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *h)
{
	list_t *n = h;
	size_t k = list_len(h), j;
	char **strs;
	char *s;

	if (!h || !k)
		return (NULL);
	strs = malloc(sizeof(char *) * (k + 1));
	if (!strs)
		return (NULL);
	for (k = 0; n; n = n->next, k++)
	{
		s = malloc(_strlen(n->str) + 1);
		if (!s)
		{
			for (j = 0; j < k; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		s = _strcpy(s, node->str);
		strs[k] = s;
	}
	strs[k] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *head)
{
	size_t j = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @n: pointer to list head
 * @prex: string to match
 * @ch: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *n, char *prex, char ch)
{
	char *pt = NULL;

	while (n)
	{
		pt = starts_with(n->str, prex);
		if (pt && ((ch == -1) || (*pt == ch)))
			return (n);
		n = n->next;
	}
	return (NULL);
}
