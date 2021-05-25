/* adscor.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

extern struct {
    logical debug;
    integer iseed;
} _BLNK__;

#define _BLNK__1 _BLNK__

extern struct {
    integer savar[400];
} block2_;

#define block2_1 block2_

/* Table of constant values */

static integer c__1 = 1;

/* ---------------------------------------------------- */
/* Subroutine */ int adscor_(ii)
integer *ii;
{
    /* Format strings */
    static char fmt_8001[] = "(\0020  RESULT OF \"ADSCOR\" IS:\002,i3)";

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer itemp;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, fmt_8001, 0 };


    *ii = 0;
    if (block2_1.savar[3] == 72) {
	*ii += 9;
    }
    if (block2_1.savar[6] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[11] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[16] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[17] == 81) {
	++(*ii);
    }
    if (block2_1.savar[18] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[22] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[23] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[27] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[28] == 72) {
	*ii += 10;
    }
    if (block2_1.savar[29] == 72) {
	*ii += 10;
    }
/* Score is dependent on the number of moves. */
    itemp = block2_1.savar[89] - 250;
    if (itemp >= 0) {
	*ii -= itemp / 5;
    }
    if (_BLNK__1.debug) {
	s_wsfe(&io___2);
	do_fio(&c__1, (char *)&(*ii), (ftnlen)sizeof(integer));
	e_wsfe();
    }
    return 0;
} /* adscor_ */

