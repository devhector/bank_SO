#include "bank.h"

void	*banker(void *arg)
{
	person_t	*person;

	person = (person_t *)arg;
	printf("Banker thread [%d] started\n", person->id);
	return (NULL);
}

int	create_simu(person_t *person)
{
	int		i;
	int		aux;
	int		count;
	int		p_aux;
	int		persons;
	bank_t	*bank;

	aux = -1;
	bank = person[0].bank;
	p_aux = bank->persons;
	persons = bank->persons;
	while (get_status(bank))
	{
		count = persons - (3 * ((p_aux - 1) / 3));
		i = aux;
		while (++i < count)
			pthread_create(&person[i].thread, NULL, &banker, &person[i]);
		i = aux;
		while (++i < count)
			pthread_join(person[i].thread, NULL);
		aux = count - 1;
		p_aux = persons - count;
		if (persons <= 0)
			break ;
	}
	return (0);
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
	bank->person = person;
	i = -1;
	while (++i < persons)
	{
		printf("Pessoa %d:\n", i);
		printf("Custo do emprestimo: %d\n", person[i].loan_cost);
		printf("Valor de 5%% emprestimo: %d\n", (int) (person[i].loan_cost * 0.05));
		printf("Taxa do emprestimo: %d\n", person[i].loan_rate);
		printf("Valor de entrada: %d\n", person[i].entry_value);
	}
	return (create_simu(bank->person));
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