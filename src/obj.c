/* obj.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

extern struct {
    real savar[400];
} block2_;

#define block2_1 block2_

/* -------------------------------------------------------------- */
/* Subroutine */ int obj_(items, room, score, value)
integer *items, *room, *score, *value;
{
    /* Local variables */
#define prec ((logical *)&block2_1 + 85)
    static integer i, ii;
    extern /* Subroutine */ int des_();



    /* Parameter adjustments */
    --value;
    --items;

    /* Function Body */
    if (*prec) {
	items[9] = 0;
    }
    if (*prec) {
	items[16] = 0;
    }
    for (i = 1; i <= 30; ++i) {
	if (items[i] != *room) {
	    goto L10;
	}
	ii = i + 600;
	*score += value[i];
	value[i] = 0;
	des_(&ii);
L10:
	;
    }
    if (! (*prec)) {
	goto L20;
    }
    items[9] = *room;
    items[16] = *room;
L20:
    return 0;
} /* obj_ */

#undef prec


