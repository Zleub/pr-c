/*
** header
*/

t_hugo		*create_hugo(void)
{
	t_hugo	*elem;

	if (!(elem = (t_hugo*)malloc(sizeof(t_hugo))))
		return(NULL);
	elem->name = NULL;
	elem->height = -1;
	elem->weight = -1;
	elem->pointofview = NULL;
	return (elem);
}

t_hugo		*free_hugo(t_hugo *elem)
{
	free(elem->name);
	free(elem->pointofview);
	free_(elem);
	elem = NULL;
	return (NULL);
}

t_hugo		*manage_hugo(int macro, t_hugo *object)
{
	static t_hugo	*elem;

	if (macro == GET)
		return (elem);
	if (macro == SET)
		elem = object;
	if (macro == NEW)
		elem = create_hugo();
	if (macro == DEL)
		elem = free_hugo(elem);
	return (NULL);
}
