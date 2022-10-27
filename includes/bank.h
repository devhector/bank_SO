#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct bank_s {
	int				cash;
	int				subsidy;
	int				persons;
	int				interest_rate;
	bool			sim_ok;
	pthread_mutex_t	status;
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

int		get_status(bank_t *bank);

void	add_queue(stack_t **queue, person_t person);
int		bank_simulation(int cash, int subsidy, int interest_rate, int persons);
