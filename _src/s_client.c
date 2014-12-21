#include <stdlib.h>
#include <libftsock_struct.h>

struct s_client	*new_s_client(void)
{
	struct s_client	*new;

	if (!(new = (struct s_client*)malloc(sizeof(struct s_client))))
		return (NULL);
	new->*tcps = 0;
	new->*next = 0;
	new->*user_data = 0;
	new->closed = 0;
	new->recv_buf[FTSOCK_BUFFER] = 0;
	new->*recv_cbuf = 0;
	new->send_buf[FTSOCK_BUFFER + 1] = 0;
	new->*send_data = 0;
	new->send_offset = 0;
	return (new);
}

struct s_client	*manage_s_client(int macro)
{
	static struct s_client	*current;

	if (macro == NEW)
		current = new_s_client();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_client: no decent macro\n", 33);
	return (NULL);
}
