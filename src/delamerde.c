/*
** header
*/

t_merde		*create_delamerde()
{
}
t_merde		*manage_delamerde(int macro, t_merde *object)
{
	static t_merde	*elem;

	if (macro == GET)
		return (elem);
	if (macro == SET)
		elem = object;
	if (macro == NEW)
		elem = create_delamerde();
	if (macro == DEL)
		free_delamerde(elem);
}
