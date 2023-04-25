#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @start: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **start, const char *str, int num)
{
	list_t *new_start;

	if (!start)
		return (NULL);
	new_start = malloc(sizeof(list_t));
	if (!new_start)
		return (NULL);
	_memset((void *)new_start, 0, sizeof(list_t));
	new_start->num = num;
	if (str)
	{
		new_start->str = _strdup(str);
		if (!new_start->str)
		{
			free(new_start);
			return (NULL);
		}
	}
	new_start->next = *start;
	*start = new_start;
	return (new_start);
}

/**
 * add_node_end - adds a node to the end of the list
 * @start: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **start, const char *str, int num)
{
	list_t *new_node, *node;

	if (!start)
		return (NULL);

	node = *start;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*start = new_node;
	return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @start: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *start)
{
	size_t i = 0;

	while (start)
	{
		_puts(start->str ? start->str : "(nil)");
		_puts("\n");
		start = start->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @start: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **start, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!start || !*start)
		return (0);

	if (!index)
	{
		node = *start;
		*start = (*start)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *start;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @start_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **start_ptr)
{
	list_t *node, *next_node, *start;

	if (!start_ptr || !*start_ptr)
		return;
	start = *start_ptr;
	node = start;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*start_ptr = NULL;
}
