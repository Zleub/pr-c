#include <stdlib.h>
#include <libftsock_struct.h>

struct s_server	*new_s_server(void)
{
	struct s_server	*new;

	if (!(new = (struct s_server*)malloc(sizeof(struct s_server))))
		return (NULL);
	new->tcps = NULL;
	new->user_data = NULL;
	new->clients = NULL;
	new->read_fds = 0;
	new->write_fds = 0;
	new->higher_fd = 0;
	new->eot = 0;
	new->connect_handle)(t_serv *, t_ccom **) = NULL;
	new->disconnect_handle)(t_serv *, t_ccom **) = NULL;
	new->recv_handle)(t_serv *, t_ccom **, char *) = NULL;
	new->timeout_handle)(t_serv *) = NULL;
	new->loop_handle)(t_serv *) = NULL;
	new->tv = 0;
	return (new);
}

struct s_server	*manage_s_server(int macro)
{
	static struct s_server	*current;

	if (macro == NEW)
		current = new_s_server();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_s_server: no decent macro\n", 33);
	return (NULL);
}
