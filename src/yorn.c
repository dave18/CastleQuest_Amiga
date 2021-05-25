/* yorn.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

extern struct {
    long cierr;
    long ciunit;
    long ciend;
    char *cifmt;
    long cirec;
}   outstring;


extern void printstring();

static integer c__1 = 1;

/* Subroutine */ int yorn_(ii)
integer *ii;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_7 = { {'Y', ' ', ' ', ' '}, 0 };

#define y (*(integer *)&equiv_7)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_8 = { {'N', ' ', ' ', ' '}, 0 };

#define n (*(integer *)&equiv_8)


    /* Format strings */
    static char fmt_2000[] = "(\002 \002)";
    static char fmt_1001[] = "(a1)";
    static char fmt_2001[] = "(\0020  Please answer YES or NO !\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ans;

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 6, 0, fmt_2000, 0 };
    static cilist io___4 = { 1, 5, 1, fmt_1001, 0 };
    static cilist io___6 = { 0, 6, 0, fmt_2001, 0 };




L10:
    s_wsfe(&io___3);
    e_wsfe();
    i__1 = s_rsfe(&io___4);
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, (char *)&ans, (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L30;
    }

    *ii = 1;
    if (ans == y) {
	goto L100;
    }
    if (ans != n) {
	goto L30;
    }
    *ii = 0;
    goto L100;
L30:
    //s_wsfe(&io___6);
    //e_wsfe();
    printstring(&io___6);
    goto L10;

L100:
    return 0;
} /* yorn_ */

#undef n
#undef y


