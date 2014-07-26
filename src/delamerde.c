/*
** header
*/

t_merde		*create_delamerde(void)
{
	t_merde	*elem;

	if (!(elem = (t_merde*)malloc(sizeof(t_merde))))
		return(NULL);
TYPE  "int"
NAME  "		chose;"
TYPE  "	char		"
NAME  "truc;"
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
