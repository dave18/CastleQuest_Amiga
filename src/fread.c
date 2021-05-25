/* fread.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* --------------------------------------------------------------------- */
/* Subroutine */ int fread_(iverb, inoun)
integer *iverb, *inoun;
{
    /* Initialized data */

    static char blank[1+1] = " ";
    static char blanks[12+1] = "            ";
    static char huh[20+11] = "(\002\n  I didn't get that!!\002)";

    /* Format strings */
    static char fmt_1001[] = "(a20)";

    /* System generated locals */
    integer i__1;
    alist al__1;
    static integer equiv_0[3], equiv_1[3];

    /* Builtin functions */
    /* Subroutine */ int s_copy();
    integer s_rsfe(), do_fio(), e_rsfe(), f_rew(), s_wsfe(), e_wsfe();

    /* Local variables */
    static char line[20];
#define verb ((char *)equiv_1)
#define noun ((char *)equiv_0)
    static integer i, j;
#define jverb (equiv_1)
    static integer isave, ilast;
#define jnoun (equiv_0)
    static integer ii, kk;

    /* Fortran I/O blocks */
    static cilist io___8 = { 1, 5, 1, fmt_1001, 0 };
    static cilist io___15 = { 0, 6, 0, huh, 0 };





    /* Parameter adjustments */
    --inoun;
    --iverb;

    /* Function Body */

    s_copy(noun, blanks, 12L, 12L);
    s_copy(verb, blanks, 12L, 12L);
L5:
    i__1 = s_rsfe(&io___8);
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, line, 20L);
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L30;
    }

    for (i = 1; i <= 20; ++i) {
	isave = i;
	if (line[i - 1] != blank[0]) {
	    goto L11;
	}
/* L10: */
    }
    goto L30;

L11:
    j = 1;
    ilast = isave + 11;
    i__1 = ilast;
    for (ii = isave; ii <= i__1; ++ii) {
	if (line[ii - 1] != blank[0]) {
	    verb[j - 1] = line[ii - 1];
	    ++j;
	} else {
	    isave = ii;
	    goto L13;
	}
/* L12: */
    }
    isave = ilast + 1;
L13:
    for (i = isave; i <= 20; ++i) {
	if (line[i - 1] != blank[0]) {
	    goto L20;
	}
/* L14: */
    }
    goto L100;

L20:
    j = 1;
    ilast = i + 11;
    i__1 = ilast;
    for (ii = i; ii <= i__1; ++ii) {
	if (line[ii - 1] != blank[0]) {
	    noun[j - 1] = line[ii - 1];
	    ++j;
	} else {
	    goto L23;
	}
/* L22: */
    }
L23:
    goto L100;

L30:
//    printf("HERE \n");
    al__1.aerr = 0;
    al__1.aunit = 5;
 //   f_rew(&al__1);
 //   printf("HERE2 \n");
    s_wsfe(&io___15);
    e_wsfe();
    goto L5;

L100:
    for (kk = 1; kk <= 3; ++kk) {
	inoun[kk] = jnoun[kk - 1];
	iverb[kk] = jverb[kk - 1];
/* L110: */
    }
    return 0;
} /* fread_ */

#undef jnoun
#undef jverb
#undef noun
#undef verb


