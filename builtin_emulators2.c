#include "shell.h"

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *s)
{
	char *pt, ch;
	int back;

	pt = _strchr(s, '=');
	if (!pt)
		return (1);
	ch = *pt;
	*pt = 0;
	back = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, s, -1)));
	*pt = ch;
	return (back);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *s)
{
	char *pt;

	pt = _strchr(s, '=');
	if (!pt)
		return (1);
	if (!*++pt)
		return (unset_alias(info, s));

	unset_alias(info, s);
	return (add_node_end(&(info->alias), s, 0) == NULL);
}

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *pt = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_list(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		pt = _strchr(info->argv[i], '=');
		if (pt)
			set_alias(info, info->argv[i]);
		else
			print_list(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *pt = NULL, *a = NULL;

	if (node)
	{
		pt = _strchr(node->str, '=');
		for (a = node->str; a <= pt; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(pt + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
