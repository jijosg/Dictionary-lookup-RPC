/* rdict_sif.c - init_1, insert_1, delete_1, lookup_1 */

#include <rpc/rpc.h>

#include "rdict.h"

/* Server-side stub interface routines written by programmer */

static int retcode;

/* -------------------------------------------------------------
 * insertw_1 - server side interface to remote insertw
 * -------------------------------------------------------------
 */
int	*
insertw_1_svc(struct wordwithmeaning_t *wordwithmeaning, struct svc_req *s)
{
	char *w, *m;
	w = wordwithmeaning->word;
	m = wordwithmeaning->meaning;
	retcode = insertw(w, m);
	return &retcode;
}

/* -------------------------------------------------------------
 * initw_1 - server side interface to remote procedure initw
 * -------------------------------------------------------------
 */
int	*
initw_1_svc(void *v, struct svc_req *s)
{
	retcode = initw();
	return &retcode;
}

/* -------------------------------------------------------------
 * deletew_1 - server side interface to remote procedure deletew
 * -------------------------------------------------------------
 */
int	*
deletew_1_svc(char **w, struct svc_req *s)
{
	retcode = deletew(*w);
	return &retcode;
}

/* -------------------------------------------------------------
 * lookupw_1 - server side interface to remote procedure lookupw
 * -------------------------------------------------------------
 */
int	*
lookupw_1_svc(char **w, struct svc_req *s)
{
	retcode = lookupw(*w);
	return &retcode;
}


