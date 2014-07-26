/*
** header
*/

t_merde		*create_merde()
{
}
t_merde		*manage_merde(int macro, t_merde *object)
{
	static t_merde	*elem;

	if (macro == GET)
		return (elem);
	if (macro == SET)
		elem = object;
	if (macro == NEW)
		elem = create_merde();
	if (macro == DEL)
		free_merde(elem);
}
