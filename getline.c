#include "shell.h"

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buff; /* the ';' command chain buffer */
	static size_t k, j, len;
	ssize_t r = 0;
	char **buff_p = &(info->arg), *pt;

	_putchar(BUF_FLUSH);
	r = input_buff(info, &buff, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = k; /* init new iterator to current buf position */
		pt = buff + k; /* get pointer for return */

		check_chain(info, buff, &j, k, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buff, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (k >= len) /* reached end of buffer? */
		{
			k = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buff_p = pt; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buff_p = buff; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buff: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buff, size_t *len)
{
	ssize_t ret = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		ret = getline(buff, &len_p, stdin);
#else
		ret = _getline(info, buff, &len_p);
#endif
		if (ret > 0)
		{
			if ((*buff)[ret - 1] == '\n')
			{
				(*buff)[ret - 1] = '\0'; /* remove trailing newline */
				ret--;
			}
			info->linecount_flag = 1;
			remove_comments(*buff);
			build_history_list(info, *buff, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = ret;
				info->cmd_buf = buff;
			}
		}
	}
	return (ret);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buff; /* the ';' command chain buffer */
	static size_t k, j, len;
	ssize_t r = 0;
	char **buff_p = &(info->arg), *pt;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buff, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = k; /* init new iterator to current buf position */
		pt = buff + k; /* get pointer for return */

		check_chain(info, buff, &j, k, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buff, &j))
				break;
			j++;
		}

		j = j + 1; /* increment past nulled ';'' */
		if (k >= len) /* reached end of buffer? */
		{
			k = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buff_p = pt; /* pass back pointer to current command position */
		return (_strlen(pt)); /* return length of current command */
	}

	*buff_p = buff; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buff: buffer
 * @si: size
 *
 * Return: ret
 */
ssize_t read_buf(info_t *info, char *buff, size_t *si)
{
	ssize_t ret = 0;

	if (*si)
		return (0);
	ret = read(info->readfd, buff, READ_BUF_SIZE);
	if (ret >= 0)
		*si = ret;
	return (ret);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buff[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t ret = 0, s = 0;
	char *pt = NULL, *new_pt = NULL, *ch;

	pt = *ptr;
	if (pt && length)
		s = *length;
	if (i == len)
		i = len = 0;

	ret = read_buf(info, buff, &len);
	if (ret == -1 || (ret == 0 && len == 0))
		return (-1);

	ch = _strchr(buff + i, '\n');
	k = ch ? 1 + (unsigned int)(ch - buff) : len;
	new_pt = _realloc(pt, s, s ? s + k : k + 1);
	if (!new_pt) /* MALLOC FAILURE! */
		return (pt ? free(pt), -1 : -1);

	if (s)
		_strncat(new_pt, buff + i, k - i);
	else
		_strncpy(new_pt, buff + i, k - i + 1);

	s += k - i;
	i = k;
	pt = new_pt;

	if (length)
		*length = s;
	*ptr = pt;
	return (s);
}
