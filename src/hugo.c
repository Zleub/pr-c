/*
** header
*/

t_hugo		*create_hugo(void)
{
	t_hugo	*elem;

	if (!(elem = (t_hugo*)malloc(sizeof(t_hugo))))
		return(NULL);
	elem->name = NULL;
	elem->height = 0;
	elem->weight = 0;
	elem->pointofview = NULL;
	elem->state = NULL;
	return (elem);
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
		free_hugo(elem);
	return (NULL);
}
