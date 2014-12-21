#include <stdlib.h>
#include <string.h>
#include <tcl.h>

enum e_macro
{
	NEW,
	GET
};

struct Tcl_Filesystem	*new_Tcl_Filesystem(void)
{
	struct Tcl_Filesystem	*new;

	if (!(new = (struct Tcl_Filesystem*)malloc(sizeof(struct Tcl_Filesystem))))
		return (NULL);
	new->typeName = NULL;
	new->structureLength = 0;
	new->version = 0;
	new->pathInFilesystemProc = NULL;
	new->dupInternalRepProc = NULL;
	new->freeInternalRepProc = NULL;
	new->internalToNormalizedProc = NULL;
	new->createInternalRepProc = NULL;
	new->normalizePathProc = NULL;
	new->filesystemPathTypeProc = NULL;
	new->filesystemSeparatorProc = NULL;
	new->statProc = NULL;
	new->accessProc = NULL;
	new->openFileChannelProc = NULL;
	new->matchInDirectoryProc = NULL;
	new->utimeProc = NULL;
	new->linkProc = NULL;
	new->listVolumesProc = NULL;
	new->fileAttrStringsProc = NULL;
	new->fileAttrsGetProc = NULL;
	new->fileAttrsSetProc = NULL;
	new->createDirectoryProc = NULL;
	new->removeDirectoryProc = NULL;
	new->deleteFileProc = NULL;
	new->copyFileProc = NULL;
	new->renameFileProc = NULL;
	new->copyDirectoryProc = NULL;
	new->lstatProc = NULL;
	new->loadFileProc = NULL;
	new->getCwdProc = NULL;
	new->chdirProc = NULL;
	return (new);
}

struct Tcl_Filesystem	*manage_Tcl_Filesystem(int macro)
{
	static struct Tcl_Filesystem	*current;

	if (macro == NEW)
		current = new_Tcl_Filesystem();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_Tcl_Filesystem: no decent macro\n", 39);
	return (NULL);
}
