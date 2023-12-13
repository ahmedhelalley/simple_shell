#include "shell.h"

/**
<<<<<<< HEAD
 * get_node_index - gets the index of a node
 * @h: pointer to list head
 * @n: pointer to the node
=======
 * list_len - determines length of linked list
 * @h: pointer to the first node
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
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
		h = head->next;
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
		head = h->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - returns an array of strings of the list->str
<<<<<<< HEAD
 * @h: pointer to first node
=======
 * @head: pointer to the first node
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *h)
{
	list_t *n = h;
	size_t k = list_len(head), j;
	char **strs;
	char *s;

	if (!h || !k)
		return (NULL);
	strs = malloc(sizeof(char *) * (k + 1));
	if (!strs)
		return (NULL);
	for (k = 0; n; n = node->next, k++)
	{
		s = malloc(_strlen(node->str) + 1);
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
<<<<<<< HEAD
 * @head: pointer to first node
=======
 * @h: pointer to the first node
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
 *
 * Return: size of list
 */
size_t print_list(const list_t *head)
{
	size_t j = 0;

	while (head)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		head = h->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - returns node whose string starts with prefix
<<<<<<< HEAD
 * @n: pointer to list head
 * @prex: string to match
 * @ch: the next character after prefix to match
=======
 * @node: pointer to the list head
 * @prefix: array of strings to match
 * @c: the next character after prefix to match
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *n, char *prex, char ch)
{
	char *pt = NULL;

	while (n)
	{
		pt = starts_with(node->str, prex);
		if (pt && ((ch == -1) || (*pt == ch)))
			return (n);
		n = node->next;
	}
	return (NULL);
}
<<<<<<< HEAD
=======

/**
 * get_node_index - gets the index of a node
 * @head: pointer to the list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
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
>>>>>>> be657a8607240020cc7d7a1416bf60e849c043bd
