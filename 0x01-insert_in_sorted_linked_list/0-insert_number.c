#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Function that add a
 * new node in a sorted single linked list
 * @head: Pointer to the head node
 * @number: Number to add
 * Return: The new node or Null if fail
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL, *current = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head)
		return (NULL);
	new_node->n = number;
	if (!*head)
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	if (current->n > number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	while (current->next)
	{
		if (current->next->n >= new_node->n)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
	return (NULL);
}
