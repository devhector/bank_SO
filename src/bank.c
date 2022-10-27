#include "bank.h"

int	get_group(int persons)
{
	int	group;

	group = persons / 3;
	if (persons % 3 != 0)
		group++;
	return (group);
}

int	create_simu(person_t *person)
{
	int		i;
	int		group;
	bank_t	*bank;

	bank = person[0].bank;
	group = get_group(bank->persons);
	
	while (get_status(bank))
	{

	}
}

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
	i = -1;
	while (++i < persons)
	{
		printf("Pessoa %d:\n", i);
		printf("Custo do emprestimo: %d\n", person[i].loan_cost);
		printf("Valor de 5%% emprestimo: %d\n", (int) (person[i].loan_cost * 0.05));
		printf("Taxa do emprestimo: %d\n", person[i].loan_rate);
		printf("Valor de entrada: %d\n", person[i].entry_value);
	}
	return (0);
}

int	bank_simulation(int cash, int subsidy, int interest_rate, int persons)
{
	bank_t	bank;

	bank.cash = cash;
	bank.sim_ok = true;
	bank.subsidy = subsidy;
	bank.persons = persons;
	bank.interest_rate = interest_rate;
	pthread_mutex_init(&bank.status, NULL);
	pthread_mutex_init(&bank.lock_account, NULL);
	return (start(&bank, persons));
}