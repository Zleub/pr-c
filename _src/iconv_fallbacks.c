#include <stdlib.h>
#include <string.h>
#include <iconv.h>

enum e_macro
{
	NEW,
	GET
};

struct iconv_fallbacks	*new_iconv_fallbacks(void)
{
	struct iconv_fallbacks	*new;

	if (!(new = (struct iconv_fallbacks*)malloc(sizeof(struct iconv_fallbacks))))
		return (NULL);
	new->mb_to_uc_fallback = 0;
	new->uc_to_mb_fallback = 0;
	new->mb_to_wc_fallback = 0;
	new->wc_to_mb_fallback = 0;
	new-> data = NULL;
	return (new);
}

struct iconv_fallbacks	*manage_iconv_fallbacks(int macro)
{
	static struct iconv_fallbacks	*current;

	if (macro == NEW)
		current = new_iconv_fallbacks();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_iconv_fallbacks: no decent macro\n", 40);
	return (NULL);
}
