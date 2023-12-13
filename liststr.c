#include "shell.h"

/**
 * free_list - frees all nodes of a list
 * @h_pt: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **h_pt)
{
	list_t *n, *n_node, *h;

	if (!h_pt || !*h_pt)
		return;
	h = *h_pt;
	n = h;
	while (n)
	{
		n_node = node->next;
		free(node->str);
		free(n);
		n = n_node;
	}
	*h_pt = NULL;
}

/**
 * add_node - adds a node to the start of the list
 * @h: address of pointer to head node
 * @s: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **h, const char *s, int num)
{
	list_t *n_head;

	if (!h)
		return (NULL);
	n_head = malloc(sizeof(list_t));
	if (!n_head)
		return (NULL);
	_memset((void *)n_head, 0, sizeof(list_t));
	n_head->num = num;
	if (s)
	{
		new_head->str = _strdup(s);
		if (!new_head->str)
		{
			free(n_head);
			return (NULL);
		}
	}
	new_head->next = *h;
	*h = n_head;
	return (n_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @h: address of pointer to head node
 * @s: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **h, const char *s, int num)
{
	list_t *n_node, *n;

	if (!h)
		return (NULL);

	n = *h;
	n_node = malloc(sizeof(list_t));
	if (!n_node)
		return (NULL);
	_memset((void *)n_node, 0, sizeof(list_t));
	n_node->num = num;
	if (s)
	{
		n_node->str = _strdup(s);
		if (!n_node->str)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (n)
	{
		while (node->next)
			n = node->next;
		n->next = n_node;
	}
	else
		*h = n_node;
	return (n_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *head)
{
	size_t j = 0;

	while (p)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * delete_node_at_index - deletes node at given index
 * @h: address of pointer to first node
 * @i: index of node to delete
 *
 * Return: 1 on success and 0 on failure
 */
int delete_node_at_index(list_t **h, unsigned int i)
{
	list_t *n, *p_node;
	unsigned int j = 0;

	if (!h || !*h)
		return (0);

	if (!i)
	{
		n = *h;
		*h = (*h)->next;
		free(n->str);
		free(n);
		return (1);
	}
	n = *h;
	while (n)
	{
		if (j == i)
		{
			p_node->next = n->next;
			free(n->str);
			free(n);
			return (1);
		}
		j++;
		p_node = n;
		n = n->next;
	}
	return (0);
}
