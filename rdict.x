/* rdict.x */

/* RPC declaration for dictionary program */

const	MAXWORD = 50;	/* maximun length of a command or word */
const	DICTSIZ=100;	/* number of entries in dictionary */

struct example	{/* unused structure declared here to */
	int	exfield1;/* illustrate how rpcgen build XDR	*/
	char	exfield2;/* routines to convert structures	*/
};

struct wordwithmeaning_t {
        string word < 128 >;
        string meaning < 128 >;
};

/*-------------------------------------------------------------------------------
 * RDICTPROG - remote program that provides insert, delete, and lookup
 *-------------------------------------------------------------------------------
 */

program RDICTPROG {		/* name of remote program (not used)	*/
     version RDICTVERS	{	/* declaration of version (see below)	*/
	int INITW(void)	= 1;	/* first procedure in this program 		*/
	int INSERTW(wordwithmeaning_t)	= 2;	/* second procedure in this program 	*/
	int DELETEW(string)	= 3;	/* third procedure in this program 		*/
	int LOOKUPW(string)	= 4;	/* fourth procedure in this program		*/
     } = 1;				/* definition of the program version 	*/
} = 0x30090949;				/* remote program number (must be unique)	*/


