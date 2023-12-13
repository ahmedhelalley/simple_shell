#include "shell.h"

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buff: the char buffer
 * @pt: address of current position in buff
 * @j: starting position in buff
 * @len: length of buff
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buff, size_t *pt, size_t j, size_t len)
{
	size_t i = *pt;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buff[j] = 0;
			i = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buff[j] = 0;
			i = len;
		}
	}

	*pt = i;
}

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buff: the char buffer
 * @pt: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buff, size_t *pt)
{
	size_t k = *pt;

	if (buff[k] == '|' && buff[k + 1] == '|')
	{
		buff[k] = 0;
		k++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buff[k] == '&' && buff[k + 1] == '&')
	{
		buff[k] = 0;
		k++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buff[k] == ';') /* found end of this command */
	{
		buff[k] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*pt = k;
	return (1);
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int j;
	list_t *node;
	char *pt;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		pt = _strchr(node->str, '=');
		if (!pt)
			return (0);
		pt = _strdup(pt + 1);
		if (!pt)
			return (0);
		info->argv[0] = pt;
	}
	return (1);
}

/**
 * replace_string - replaces string
 * @olds: address of old string
 * @news: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **olds, char *news)
{
	free(*olds);
	*olds = news;
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int j = 0;
	list_t *node;

	for (j = 0; info->argv[j]; j++)
	{
		if (info->argv[j][0] != '$' || !info->argv[j][1])
			continue;

		if (!_strcmp(info->argv[j], "$?"))
		{
			replace_string(&(info->argv[j]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[j], "$$"))
		{
			replace_string(&(info->argv[j]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[j][1], '=');
		if (node)
		{
			replace_string(&(info->argv[j]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[j], _strdup(""));

	}
	return (0);
}
