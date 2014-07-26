/*
** header
*/

struct s_deladaube		*create_deladaube()
{
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
