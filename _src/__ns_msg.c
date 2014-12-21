#include <stdlib.h>
#include <string.h>
#include <nameser.h>

enum e_macro
{
	NEW,
	GET
};

struct __ns_msg	*new___ns_msg(void)
{
	struct __ns_msg	*new;

	if (!(new = (struct __ns_msg*)malloc(sizeof(struct __ns_msg))))
		return (NULL);
	new->_msg, *_eom = NULL;
	bzero((void*)(&new->_id, _flags, _counts), sizeof(u_int16_t) * ns_s_max);
	bzero((void*)(&new->_sections), sizeof(const u_char*) * ns_s_max);
	new->_sect = 0;
	new->_rrnum = 0;
	new->_msg_ptr = NULL;
	return (new);
}

struct __ns_msg	*manage___ns_msg(int macro)
{
	static struct __ns_msg	*current;

	if (macro == NEW)
		current = new___ns_msg();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage___ns_msg: no decent macro\n", 33);
	return (NULL);
}
