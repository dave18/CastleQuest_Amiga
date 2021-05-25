/* ggnome.f -- translated by f2c (version 19940615).
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

/* --------------------------------------------------------------- */
/* Subroutine */ int ggnome_(ii, gnome)
integer *ii;
logical *gnome;
{
    /* Format strings */
    static char fmt_1001[] = "(\0020  There is an ugly little gnome in the r\
oom with you!\002)";
    static char fmt_1004[] = "(\0020  He shoots a poisoned dart at you!\002)";
    static char fmt_1002[] = "(\0020  IT GETS YOU!!\002)";
    static char fmt_1003[] = "(\0020  It misses by an elf-hair!\002)";
    static char fmt_8001[] = "(\0020  GNOME:\002,l2,\002 XLIM:\002,f5.3)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static real seed, xlim, val;
    extern doublereal rdm_();

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, fmt_1001, 0 };
    static cilist io___5 = { 0, 6, 0, fmt_1004, 0 };
    static cilist io___6 = { 0, 6, 0, fmt_1002, 0 };
    static cilist io___7 = { 0, 6, 0, fmt_1003, 0 };
    static cilist io___8 = { 0, 6, 0, fmt_8001, 0 };



    seed = (real) _BLNK__1.iseed;
    val = rdm_(&seed);
    if (*gnome) {
	goto L50;
    }
    xlim = (float).075;
    if (val <= (float).97) {
	goto L900;
    }
    *gnome = TRUE_;
/*          GNOME ATTACKS! */
L50:
    /*s_wsfe(&io___4);
    e_wsfe();*/
    printstring(&io___4);
    if (val > (float).98) {
	goto L900;
    }
    /*s_wsfe(&io___5);
    e_wsfe();*/
    printstring(&io___5);
    val = rdm_(&seed);
    if (val >= xlim) {
	goto L100;
    }
/*                YOU DIE. */
    *ii = 1;
    /*s_wsfe(&io___6);
    e_wsfe();*/
    printstring(&io___6);
    goto L900;
L100:
    xlim += (float).2;
    /*s_wsfe(&io___7);
    e_wsfe();*/
    printstring(&io___7);
L900:
    if (_BLNK__1.debug) {
	s_wsfe(&io___8);
	do_fio(&c__1, (char *)&(*gnome), (ftnlen)sizeof(logical));
	do_fio(&c__1, (char *)&xlim, (ftnlen)sizeof(real));
	e_wsfe();
    }
    return 0;
} /* ggnome_ */

