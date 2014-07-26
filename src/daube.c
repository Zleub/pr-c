/*
** header
*/

struct s_daube		*create_daube(void)
{
	struct s_daube	*elem;

	if (!(elem = (struct s_daube*)malloc(sizeof(struct s_daube))))
		return(NULL);
TYPE  "int"
NAME  "		chose;"
TYPE  "	char		"
NAME  "truc;"
}

struct s_daube		*manage_daube(int macro, struct s_daube *object)
{
	static struct s_daube	*elem;

	if (macro == GET)
		return (elem);
	if (macro == SET)
		elem = object;
	if (macro == NEW)
		elem = create_daube();
	if (macro == DEL)
		free_daube(elem);
}
