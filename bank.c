#include "bank.h"

int	start(bank_t *bank, int persons)
{
	int			i;
	person_t	*person;

	person = malloc(sizeof(person_t) * persons);
	if (person == NULL)
		return (1);
	i = -1;
	while (++i)
	{
		person[i].id = i;
		person[i].loan_cost = (bank->cash * 0.4) + (rand() % bank->cash);
		person[i].bank = bank;
	}
}

int	bank_simulation(int cash, int subsidy, int interest_rate, int persons)
{
	bank_t	bank;

	bank.cash = cash;
	bank.subsidy = subsidy;
	bank.interest_rate = interest_rate;
	pthread_mutex_init(&bank.lock_account, NULL);
	return (0);
}