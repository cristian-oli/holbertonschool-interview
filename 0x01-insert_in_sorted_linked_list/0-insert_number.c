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
	listint_t *new_node = NULL;
	listint_t *current = *head;

	if (!head || !*head || !number)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = number;
	if (!current->next)
	{
		if (current->n > number)
			new_node->next = current;
		else
		{
			current->next = new_node;
			new_node->next = NULL;
		}
		return (new_node);
	}
	while (current)
	{
		if (!current->next)
		{
			current->next = new_node;
			new_node->next = NULL;
			return (new_node);
		}
		if (current->next->n > number)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		current = current->next;
	}
	return (NULL);
}
