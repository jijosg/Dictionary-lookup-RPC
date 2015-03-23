/* rdict_srp.c - initw, insertw, deletew, lookupw */

#include <rpc/rpc.h>
#include "rdict.h"

/* Server-side remote procedure and the global data they use */

char	dict[DICTSIZ][MAXWORD+1]; 	/* storage for a dictionary of words  */
char	dictm[DICTSIZ][MAXWORD+1]; 	/* storage for a dictionary of words - meaning part  */
int	nwords = 0;			/* number of word in the dictionary	*/

/* ----------------------------------------------------------------------------------------------------- 
 *	initw - initialize the dictionary to contain no words at all
 * ----------------------------------------------------------------------------------------------------- 
 */
int initw() {
	nwords = 0;
	return 1;
}

/* ----------------------------------------------------------------------------------------------------- 
 *	insertw - insert a word in the dictionary
 * ----------------------------------------------------------------------------------------------------- 
 */
int insertw(word, meaning) char *word, *meaning; {
	int ret = lookupw(word);
	if(ret == 1) {
		deletew(word);
	}
	strcpy(dict[nwords], word);
	strcpy(dictm[nwords], meaning);
	nwords++;
	return nwords;
}

/* ----------------------------------------------------------------------------------------------------- 
 *	deletew - delete a word from the dictionary
 * ----------------------------------------------------------------------------------------------------- 
 */
int deletew(word) char  *word; {
	int i;
	for (i=0; i<nwords; i++) {
		if ( strcmp(word, dict[i]) == 0) {
			nwords--;
			strcpy(dict[i], dict[nwords]);
			strcpy(dictm[i], dictm[nwords]);
			return 1;
		}
	}
	return 0;
}


/* ----------------------------------------------------------------------------------------------------- 
 *	lookupw - look up a word in the dictionary
 * ----------------------------------------------------------------------------------------------------- 
 */
int
lookupw(word, meaning) char *word, **meaning;{
	int i;
	for (i=0; i<nwords; i++)
		if ( strcmp(word, dict[i]) == 0) {
			printf("%s is found.\n", word);	
			printf("It means: %s\n", dictm[i]);
			return 1;
		}
	return 0;
}


