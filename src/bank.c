#include "bank.h"

int	start(bank_t *bank, int persons)
{
	int			i;
	int			cost_rate;
	person_t	*person;

	person = malloc(sizeof(person_t) * persons);
	if (person == NULL)
		return (1);
	i = -1;
	while (++i < persons)
	{
		person[i].id = i;
		person[i].loan_cost = (bank->cash * 0.2) + (rand() % (int)(bank->cash * 0.8));
		cost_rate = person[i].loan_cost * 0.05;
		person[i].loan_rate = (cost_rate * 0.5) + (rand() % (int)(cost_rate * 0.5));
		person[i].entry_value = (person[i].loan_cost * 0.4) + (rand() % (int)(person[i].loan_cost * 0.4));
		person[i].bank = bank;
	}
	return (0);
}

int	bank_simulation(int cash, int subsidy, int interest_rate, int persons)
{
	bank_t	bank;

	bank.cash = cash;
	bank.subsidy = subsidy;
	bank.interest_rate = interest_rate;
	pthread_mutex_init(&bank.lock_account, NULL);
	if (start(&bank, persons))
		return (1);
	return (0);
}