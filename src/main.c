#include "bank.h"

void	get_value(int *value)
{
	while (*value <= 0)
	{
		scanf("%d", value);
		if (*value <= 0)
			printf("Tente um valor maior que zero: ");
	}
}

int	main(void)
{
	int	cash = 0;
	int	subsidy = 0;
	int	persons = 0;
	int	interest_rate = 0;

	printf("Entre com o valor em espécie: \n");
	get_value(&cash);
	printf("Entre com o valor do subsídio: \n");
	get_value(&subsidy);
	printf("Entre com o saldo das taxas de juros: \n");
	get_value(&interest_rate);
	printf("Entre com o número de pessoas: \n");
	get_value(&persons);
	return (bank_simulation(cash, subsidy, interest_rate, persons));
}