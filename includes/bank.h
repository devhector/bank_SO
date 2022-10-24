#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct bank_s {
	int				cash;
	int				subsidy;
	int				interest_rate;
	pthread_mutex_t	lock_account;
} bank_t;

typedef struct person_s {
	int			id;
	int			loan_cost;
	int			loan_rate;
	int			entry_value;
	bank_t		*bank;
	pthread_t	thread;
} person_t;

typedef struct stack_s {
	person_t		person;
	struct stack_s	*next;
} stack_t;

void	add_queue(stack_t **queue, person_t person);
int		bank_simulation(int cash, int subsidy, int interest_rate, int persons);
