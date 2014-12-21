#include <stdlib.h>
#include <string.h>
#include <tkPlatDecls.h>

enum e_macro
{
	NEW,
	GET
};

struct TkPlatStubs	*new_TkPlatStubs(void)
{
	struct TkPlatStubs	*new;

	if (!(new = (struct TkPlatStubs*)malloc(sizeof(struct TkPlatStubs))))
		return (NULL);
	new->magic = 0;
	new->hooks = NULL;
	new->tk_AttachHWND = NULL;
	new->tk_GetHINSTANCE = NULL;
	new->tk_GetHWND = NULL;
	new->tk_HWNDToWindow = NULL;
	new->tk_PointerEvent = NULL;
	new->tk_TranslateWinEvent = NULL;
	new->tk_MacOSXSetEmbedHandler = NULL;
	new->tk_MacOSXTurnOffMenus = NULL;
	new->tk_MacOSXTkOwnsCursor = NULL;
	new->tkMacOSXInitMenus = NULL;
	new->tkMacOSXInitAppleEvents = NULL;
	new->tkGenWMConfigureEvent = NULL;
	new->tkMacOSXInvalClipRgns = NULL;
	new->tkMacOSXGetDrawablePort = NULL;
	new->tkMacOSXGetRootControl = NULL;
	new->tk_MacOSXSetupTkNotifier = NULL;
	new->tk_MacOSXIsAppInFront = NULL;
	return (new);
}

struct TkPlatStubs	*manage_TkPlatStubs(int macro)
{
	static struct TkPlatStubs	*current;

	if (macro == NEW)
		current = new_TkPlatStubs();
	else if (macro == GET)
		return (current);
	else
		write(1, "manage_TkPlatStubs: no decent macro\n", 36);
	return (NULL);
}
