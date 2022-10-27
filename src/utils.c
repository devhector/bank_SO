#include "bank.h"

int	get_status(bank_t *bank)
{
	bool	status;

	pthread_mutex_lock(&bank->status);
	status = bank->sim_ok;
	pthread_mutex_unlock(&bank->status);
	return (status);
}