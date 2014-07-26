/*
** header
*/

struct s_deladaube		*create_deladaube(void)
{
	struct s_deladaube	*elem;

	if (!(elem = (struct s_deladaube*)malloc(sizeof(struct s_deladaube))))
		return(NULL);
TYPE  "int"
NAME  "		chose;"
TYPE  "	char		"
NAME  "truc;"
}

struct s_deladaube		*manage_deladaube(int macro, struct s_deladaube *object)
{
	static struct s_deladaube	*elem;

	if (macro == GET)
		return (elem);
	if (macro == SET)
		elem = object;
	if (macro == NEW)
		elem = create_deladaube();
	if (macro == DEL)
		free_deladaube(elem);
}
