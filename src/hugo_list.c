/*
** header
*/

t_hugo_list		*create_hugo_list(void)
{
	t_hugo_list	*elem;

	if (!(elem = (t_hugo_list*)malloc(sizeof(t_hugo_list))))
		return(NULL);
	elem->ptr = NULL;
	elem->next = NULL;
	return (elem);
}

t_hugo_list		*free_hugo_list(t_hugo_list *elem)
{
	free(elem->ptr);
	free(elem->next);
	free_(elem);
	elem = NULL;
	return (NULL);
}

t_hugo_list		*manage_hugo_list(int macro, t_hugo_list *object)
{
	static t_hugo_list	*elem;

	if (macro == GET)
		return (elem);
	if (macro == SET)
		elem = object;
	if (macro == NEW)
		elem = create_hugo_list();
	if (macro == DEL)
		elem = free_hugo_list(elem);
	return (NULL);
}
