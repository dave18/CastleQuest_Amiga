/* wwolf.f -- translated by f2c (version 19940615).
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

/* --------------------------------------------------- */
/* Subroutine */ int wwolf_(ii, wolf)
integer *ii;
logical *wolf;
{
    /* Format strings */
    static char fmt_1001[] = "(\0020  There is a fearsome werewolf in the ro\
om with you!\002)";
    static char fmt_1002[] = "(\0020  The werewolf attacks you with its shar\
p claw!\002)";
    static char fmt_1003[] = "(\0020  It severs your jugular vein and mortal\
ly wounds you!\002)";
    static char fmt_1004[] = "(\0020  It just misses your neck!\002)";
    static char fmt_1005[] = "(\0020  A nasty werewolf lunges at you, takes \
a swipe at\002,/,\002   your neck, misses and runs away.\002)";
    static char fmt_8001[] = "(\0020  WOLF :\002,l2,\002XLIM:\002,f5.3)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static real seed, xlim, val;
    extern doublereal rdm_();

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, fmt_1001, 0 };
    static cilist io___5 = { 0, 6, 0, fmt_1002, 0 };
    static cilist io___6 = { 0, 6, 0, fmt_1003, 0 };
    static cilist io___7 = { 0, 6, 0, fmt_1004, 0 };
    static cilist io___8 = { 0, 6, 0, fmt_1005, 0 };
    static cilist io___9 = { 0, 6, 0, fmt_8001, 0 };



/*     SEED = FLOAT(ISEED) */
    val = rdm_(&seed);
    if (*ii > 0) {
	goto L75;
    }
    if (*wolf) {
	goto L50;
    }
    xlim = (float).075;
    if (val <= (float).96) {
	goto L800;
    }
    *wolf = TRUE_;
L50:
    /*s_wsfe(&io___4);
    e_wsfe();*/
    printstring(&io___4);
    val = rdm_(&seed);
    if (val > (float).4) {
	goto L900;
    }
L75:
    /*s_wsfe(&io___5);
    e_wsfe();*/
    printstring(&io___5);
    *ii = 0;
    val = rdm_(&seed);
    if (val > xlim) {
	goto L100;
    }
/* GETS YOU. */
    *ii = 1;
    /*s_wsfe(&io___6);
    e_wsfe();*/
    printstring(&io___6);
    goto L900;
L100:
/* HE MISSES. */
    xlim += (float).15;
    /*s_wsfe(&io___7);
    e_wsfe();*/
    printstring(&io___7);
    goto L900;
L800:
    *ii = 0;
/* SWIPE AND RUN AWAY. */
    if (val < (float).9) {
	goto L900;
    }
    /*s_wsfe(&io___8);
    e_wsfe();*/
    printstring(&io___8);
L900:
    if (_BLNK__1.debug) {
	s_wsfe(&io___9);
	do_fio(&c__1, (char *)&(*wolf), (ftnlen)sizeof(logical));
	do_fio(&c__1, (char *)&xlim, (ftnlen)sizeof(real));
	e_wsfe();
    }

    return 0;
} /* wwolf_ */

