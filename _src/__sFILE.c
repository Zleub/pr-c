#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum e_macro
{
	NEW,
	GET
};

struct __sFILE	*new___sFILE(void)
{
	struct __sFILE	*new;

	if (!(new = (struct __sFILE*)malloc(sizeof(struct __sFILE))))
		return (NULL);
	new->_p = NULL;
	new->_r = 0;
	new->_w = 0;
	new->_flags = 0;
	new->_file = 0;
	bzero((void*)(&new->_bf), sizeof(struct	__sbuf));
	new->_lbfsize = 0;
	new->_cookie = NULL;
	new->_close = NULL;
	new->_read = NULL;
	new->_seek = NULL;
	new->_write = NULL;
	bzero((void*)(&new->_ub), sizeof(struct	__sbuf));
	new->_extra = NULL;
	new->_ur = 0;
	bzero((void*)(&new->_ubuf), sizeof(unsigned char) * 3);
	bzero((void*)(&new->_nbuf), sizeof(unsigned char) * 1);
	bzero((void*)(&new->_lb), sizeof(struct	__sbuf));
	new->_blksize = 0;
	new->_offset = 0;
	return (new);
}

struct __sFILE	*manage___sFILE(int macro)
{
	static struct __sFILE	*current;

	if (macro == NEW)
		current = new___sFILE();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage___sFILE: no decent macro\n", 32);
	return (NULL);
}
