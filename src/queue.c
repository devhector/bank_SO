#include "bank.h"

void	add_queue(stack_t **queue, person_t person)
{
	stack_t	*new;
	stack_t	*aux;

	new = malloc(sizeof(stack_t));
	new->person = person;
	new->next = NULL;
	if (*queue == NULL)
		*queue = new;
	else
	{
		aux = *queue;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}
