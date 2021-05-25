/* isig.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* -------------------------------------------------------------- */
integer isig_(ii)
integer *ii;
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer j;

    j = 0;
    if (*ii > 0) {
	j = 1;
    }
    ret_val = j;
    return ret_val;
} /* isig_ */

