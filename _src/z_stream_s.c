#include <stdlib.h>
#include <string.h>
#include <zlib.h>

enum e_macro
{
	NEW,
	GET
};

struct z_stream_s	*new_z_stream_s(void)
{
	struct z_stream_s	*new;

	if (!(new = (struct z_stream_s*)malloc(sizeof(struct z_stream_s))))
		return (NULL);
	new->next_in = NULL;
	new->avail_in = 0;
	new->total_in = 0;
	new->next_out = NULL;
	new->avail_out = 0;
	new->total_out = 0;
	new->msg = NULL;
	new->state = NULL;
	new->zalloc = 0;
	new->zfree = 0;
	new->opaque = 0;
	new->data_type = 0;
	new->adler = 0;
	new->reserved = 0;
	return (new);
}

struct z_stream_s	*manage_z_stream_s(int macro)
{
	static struct z_stream_s	*current;

	if (macro == NEW)
		current = new_z_stream_s();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_z_stream_s: no decent macro\n", 35);
	return (NULL);
}
