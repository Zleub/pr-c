#include <stdlib.h>
#include <string.h>
#include <_locale.h>

enum e_macro
{
	NEW,
	GET
};

struct lconv	*new_lconv(void)
{
	struct lconv	*new;

	if (!(new = (struct lconv*)malloc(sizeof(struct lconv))))
		return (NULL);
	new->decimal_point = NULL;
	new->thousands_sep = NULL;
	new->grouping = NULL;
	new->int_curr_symbol = NULL;
	new->currency_symbol = NULL;
	new->mon_decimal_point = NULL;
	new->mon_thousands_sep = NULL;
	new->mon_grouping = NULL;
	new->positive_sign = NULL;
	new->negative_sign = NULL;
	new->int_frac_digits = 0;
	new->frac_digits = 0;
	new->p_cs_precedes = 0;
	new->p_sep_by_space = 0;
	new->n_cs_precedes = 0;
	new->n_sep_by_space = 0;
	new->p_sign_posn = 0;
	new->n_sign_posn = 0;
	new->int_p_cs_precedes = 0;
	new->int_n_cs_precedes = 0;
	new->int_p_sep_by_space = 0;
	new->int_n_sep_by_space = 0;
	new->int_p_sign_posn = 0;
	new->int_n_sign_posn = 0;
	return (new);
}

struct lconv	*manage_lconv(int macro)
{
	static struct lconv	*current;

	if (macro == NEW)
		current = new_lconv();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_lconv: no decent macro\n", 30);
	return (NULL);
}
