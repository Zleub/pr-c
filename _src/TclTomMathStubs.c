#include <stdlib.h>
#include <string.h>
#include <tclTomMathDecls.h>

enum e_macro
{
	NEW,
	GET
};

struct TclTomMathStubs	*new_TclTomMathStubs(void)
{
	struct TclTomMathStubs	*new;

	if (!(new = (struct TclTomMathStubs*)malloc(sizeof(struct TclTomMathStubs))))
		return (NULL);
	new->magic = 0;
	new->hooks = NULL;
	new->tclBN_epoch = NULL;
	new->tclBN_revision = NULL;
	new->tclBN_mp_add = NULL;
	new->tclBN_mp_add_d = NULL;
	new->tclBN_mp_and = NULL;
	new->tclBN_mp_clamp = NULL;
	new->tclBN_mp_clear = NULL;
	new->tclBN_mp_clear_multi = NULL;
	new->tclBN_mp_cmp = NULL;
	new->tclBN_mp_cmp_d = NULL;
	new->tclBN_mp_cmp_mag = NULL;
	new->tclBN_mp_copy = NULL;
	new->tclBN_mp_count_bits = NULL;
	new->tclBN_mp_div = NULL;
	new->tclBN_mp_div_d = NULL;
	new->tclBN_mp_div_2 = NULL;
	new->tclBN_mp_div_2d = NULL;
	new->tclBN_mp_div_3 = NULL;
	new->tclBN_mp_exch = NULL;
	new->tclBN_mp_expt_d = NULL;
	new->tclBN_mp_grow = NULL;
	new->tclBN_mp_init = NULL;
	new->tclBN_mp_init_copy = NULL;
	new->tclBN_mp_init_multi = NULL;
	new->tclBN_mp_init_set = NULL;
	new->tclBN_mp_init_size = NULL;
	new->tclBN_mp_lshd = NULL;
	new->tclBN_mp_mod = NULL;
	new->tclBN_mp_mod_2d = NULL;
	new->tclBN_mp_mul = NULL;
	new->tclBN_mp_mul_d = NULL;
	new->tclBN_mp_mul_2 = NULL;
	new->tclBN_mp_mul_2d = NULL;
	new->tclBN_mp_neg = NULL;
	new->tclBN_mp_or = NULL;
	new->tclBN_mp_radix_size = NULL;
	new->tclBN_mp_read_radix = NULL;
	new->tclBN_mp_rshd = NULL;
	new->tclBN_mp_shrink = NULL;
	new->tclBN_mp_set = NULL;
	new->tclBN_mp_sqr = NULL;
	new->tclBN_mp_sqrt = NULL;
	new->tclBN_mp_sub = NULL;
	new->tclBN_mp_sub_d = NULL;
	new->tclBN_mp_to_unsigned_bin = NULL;
	new->tclBN_mp_to_unsigned_bin_n = NULL;
	new->tclBN_mp_toradix_n = NULL;
	new->tclBN_mp_unsigned_bin_size = NULL;
	new->tclBN_mp_xor = NULL;
	new->tclBN_mp_zero = NULL;
	new->tclBN_reverse = NULL;
	new->tclBN_fast_s_mp_mul_digs = NULL;
	new->tclBN_fast_s_mp_sqr = NULL;
	new->tclBN_mp_karatsuba_mul = NULL;
	new->tclBN_mp_karatsuba_sqr = NULL;
	new->tclBN_mp_toom_mul = NULL;
	new->tclBN_mp_toom_sqr = NULL;
	new->tclBN_s_mp_add = NULL;
	new->tclBN_s_mp_mul_digs = NULL;
	new->tclBN_s_mp_sqr = NULL;
	new->tclBN_s_mp_sub = NULL;
	return (new);
}

struct TclTomMathStubs	*manage_TclTomMathStubs(int macro)
{
	static struct TclTomMathStubs	*current;

	if (macro == NEW)
		current = new_TclTomMathStubs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_TclTomMathStubs: no decent macro\n", 40);
	return (NULL);
}
