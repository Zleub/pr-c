#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

enum e_macro
{
	NEW,
	GET
};

struct _win_st	*new__win_st(void)
{
	struct _win_st	*new;

	if (!(new = (struct _win_st*)malloc(sizeof(struct _win_st))))
		return (NULL);
	new->_cury, _curx = 0;
	new->_maxy, _maxx = 0;
	new->_begy, _begx = 0;
	new->_flags = 0;
	new->_attrs = 0;
	new->_bkgd = 0;
	new->_notimeout = 0;
	new->_clear = 0;
	new->_leaveok = 0;
	new->_scroll = 0;
	new->_idlok = 0;
	new->_idcok = 0;
	new->_immed = 0;
	new->_sync = 0;
	new->_use_keypad = 0;
	new->_delay = 0;
	new->_line = NULL;
	new->_regtop = 0;
	new->_regbottom = 0;
	new->_parx = 0;
	new->_pary = 0;
	new->_parent = NULL;
	new->_pad_y,      _pad_x = 0;
	new->_pad_top,    _pad_left = 0;
	new->_pad_bottom, _pad_right = 0;
	return (new);
}

struct _win_st	*manage__win_st(int macro)
{
	static struct _win_st	*current;

	if (macro == NEW)
		current = new__win_st();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage__win_st: no decent macro\n", 32);
	return (NULL);
}
