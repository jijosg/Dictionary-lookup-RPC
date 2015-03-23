/* rdict_cif.c - initw, insertw, deletew, lookupw */

#include <rpc/rpc.h>
#include<stdio.h>
#include "rdict.h"

/* Client-side stub interface routines written by programmer */

extern CLIENT *handle;	/* handle for remote procedure */


/* -------------------------------------------------------------
 * initw - client interface routine that calls initw_1
 * -------------------------------------------------------------
 */
 
int
initw(v)
void *v;
{
	return *initw_1(v, handle);
}

/* -------------------------------------------------------------
 * insertw - client interface routine that calls insertw_1
 * -------------------------------------------------------------
 */
int
insertw(word, meaning)
char  *word, *meaning;
{
	struct wordwithmeaning_t wordwithmeaning;
	wordwithmeaning.word = word;
	wordwithmeaning.meaning = meaning;
	return *insertw_1(&wordwithmeaning, handle);
}

/* -------------------------------------------------------------
 * deletew - client interface routine that calls deletew_1
 * -------------------------------------------------------------
 */
int
deletew(word)
char 	*word;
{
	char	**arg;	/* pointer to argument	*/
	arg = &word;
	return *deletew_1(arg, handle);
}

/* -------------------------------------------------------------
 * lookupw - client interface routine that calls lookupw_1
 * -------------------------------------------------------------
 */
int
lookupw(word)
char  *word;
{
	char	**arg;	/* pointer to argument	*/
	arg = &word;
	return *lookupw_1(arg, handle);
}

