#include <stdlib.h>
#include <stdio.h>

struct __sFILE	*new___sFILE(void)
{
	struct __sFILE	*new;

	if (!(new = (struct __sFILE*)malloc(sizeof(struct __sFILE))))
		return (NULL);
	new->*_p = 0;
	new->_r = 0;
	new->_w = 0;
	new->_flags = 0;
	new->_file = 0;
	new->_bf = 0;
	new->_lbfsize = 0;
	new->*_cookie = 0;
	new->(*_close)(void *) = 0;
	new->(*_read) (void *, char *, int) = 0;
	new->(*_seek) (void *, fpos_t, int) = 0;
	new->(*_write)(void *, const char *, int) = 0;
	new->_ub = 0;
	new->*_extra = 0;
	new->_ur = 0;
	new->_ubuf[3] = 0;
	new->_nbuf[1] = 0;
	new->_lb = 0;
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
