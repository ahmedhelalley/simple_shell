#include "shell.h"
/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @vari: the string env var property
 */
int _unsetenv(info_t *info, char *vari)
{
	list_t *node = info->env;
	size_t j = 0;
	char *pt;

	if (!node || !vari)
		return (0);

	while (node)
	{
		pt = starts_with(node->str, vari);
		if (pt && *pt == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (info->env_changed);
}
/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @vari: the string env var property
 * @val: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *vari, char *val)
{
	char *buff = NULL;
	list_t *node;
	char *pt;

	if (!vari || !val)
		return (0);

	buff = malloc(_strlen(vari) + _strlen(val) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, vari);
	_strcat(buff, "=");
	_strcat(buff, val);
	node = info->env;
	while (node)
	{
		pt = starts_with(node->str, vari);
		if (pt && *pt == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
