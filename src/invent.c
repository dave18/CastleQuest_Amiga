/* invent.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

extern struct {
    integer savar[400];
} block2_;

#define block2_1 block2_

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
static integer c__2 = 2;

/* ________________________________________________ */
/* Subroutine */ int invent_(nitems)
integer *nitems;
{
    /* Initialized data */

    static struct {
	char e_1[480];
	doublereal e_2;
	} equiv_15 = { {'K', 'e', 'r', 'o', 's', 'e', 'n', 'e', ' ', ' ', ' ',
		 ' ', ' ', ' ', ' ', ' ', 'S', 'i', 'l', 'v', 'e', 'r', ' ', 
		'b', 'u', 'l', 'l', 'e', 't', ' ', ' ', ' ', 'B', 'l', 'o', 
		'o', 'd', 'y', ' ', 'h', 'a', 't', 'c', 'h', 'e', 't', ' ', 
		' ', 'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', ' ', 'k', 'e', 
		'y', ' ', ' ', ' ', ' ', 'B', 'l', 'o', 'o', 'd', ' ', 'i', 
		'n', ' ', 'b', 'o', 't', 't', 'l', 'e', ' ', 'W', 'o', 'o', 
		'd', 'e', 'n', ' ', 's', 't', 'a', 'k', 'e', ' ', ' ', ' ', 
		' ', 'C', 'h', 'a', 'm', 'p', 'a', 'g', 'n', 'e', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', 'H', 'u', 'n', 'c', 'h', 'b', 'a', 
		'c', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'o', 'i', 
		'l', ' ', 'o', 'f', ' ', 'r', 'o', 'p', 'e', ' ', ' ', ' ', 
		' ', 'W', 'r', 'i', 't', 'i', 'n', 'g', ' ', 'p', 'a', 'p', 
		'e', 'r', ' ', ' ', ' ', 'Q', 'u', 'i', 'l', 'l', ' ', 'p', 
		'e', 'n', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', 'v', 'o', 
		'r', 'y', ' ', 's', 'w', 'o', 'r', 'd', ' ', ' ', ' ', ' ', 
		' ', 'A', 'c', 'e', 't', 'y', 'l', 'e', 'n', 'e', ' ', 't', 
		'o', 'r', 'c', 'h', ' ', 'R', 'o', 'w', 'b', 'o', 'a', 't', 
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R', 'e', 'u', 
		's', 'a', 'b', 'l', 'e', ' ', 'm', 'a', 't', 'c', 'h', ' ', 
		' ', 'G', 'r', 'a', 'p', 'p', 'l', 'i', 'n', 'g', ' ', 'H', 
		'o', 'o', 'k', ' ', ' ', 'G', 'o', 'l', 'd', ' ', 's', 't', 
		'a', 't', 'u', 'e', ' ', ' ', ' ', ' ', ' ', 'E', 'm', 'p', 
		't', 'y', ' ', 'b', 'o', 't', 't', 'l', 'e', ' ', ' ', ' ', 
		' ', 'S', 'i', 'l', 'v', 'e', 'r', ' ', 'c', 'r', 'o', 's', 
		's', ' ', ' ', ' ', ' ', 'O', 'l', 'd', ' ', 'g', 'u', 'n', 
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', 'r', 'a', 
		's', 's', ' ', 'l', 'a', 'n', 't', 'e', 'r', 'n', ' ', ' ', 
		' ', 'T', 'a', 's', 't', 'y', ' ', 'f', 'o', 'o', 'd', ' ', 
		' ', ' ', ' ', ' ', ' ', 'L', 'a', 'r', 'g', 'e', ' ', 'r', 
		'u', 'b', 'y', ' ', ' ', ' ', ' ', ' ', ' ', 'J', 'a', 'd', 
		'e', ' ', 'f', 'i', 'g', 'u', 'r', 'e', ' ', ' ', ' ', ' ', 
		' ', 'F', 'l', 'a', 's', 'k', ' ', 'o', 'f', ' ', 'a', 'c', 
		'i', 'd', ' ', ' ', ' ', 'W', 'a', 't', 'e', 'r', ' ', 'i', 
		'n', ' ', 'b', 'o', 't', 't', 'l', 'e', ' ', 'C', 'u', 'b', 
		'a', 'n', ' ', 'c', 'i', 'g', 'a', 'r', ' ', ' ', ' ', ' ', 
		' ', 'S', 'a', 'p', 'p', 'h', 'i', 'r', 'e', ' ', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', 'L', 'o', 't', 's', ' ', 'o', 'f', 
		' ', 'm', 'o', 'n', 'e', 'y', ' ', ' ', ' ', 'C', 'r', 'y', 
		's', 't', 'a', 'l', ' ', 's', 'w', 'a', 'n', ' ', ' ', ' ', 
		' '}, 0. };

#define obj ((doublecomplex *)&equiv_15)

    static struct {
	char e_1[16];
	doublereal e_2;
	} equiv_16 = { {'B', 'u', 'l', 'l', 'e', 't', ' ', 'i', 'n', ' ', 'g',
		 'u', 'n', ' ', ' ', ' '}, 0. };

#define loaded (*(doublecomplex *)&equiv_16)


    /* Format strings */
    static char fmt_1010[] = "(\002\n  You are carrying the following object\
:\002)";
    static char fmt_1000[] = "(\002\n  You are carrying the following \002,\
i2,\002 objects:\002)";
    static char fmt_2000[] = "(6x,2a8)";
    static char fmt_3000[] = "(\002\n  You're not carrying anything.\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
#define numb ((integer *)&block2_1 + 94)
#define blood ((logical *)&block2_1 + 90)
#define items ((integer *)&block2_1)
#define water ((logical *)&block2_1 + 92)
    static integer ii;
#define bottle ((logical *)&block2_1 + 91)
#define gun ((logical *)&block2_1 + 62)

    /* Fortran I/O blocks */
    static cilist io___9 = { 0, 6, 0, fmt_1010, 0 };
    static cilist io___10 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___11 = { 0, 6, 0, fmt_2000, 0 };
    static cilist io___13 = { 0, 6, 0, fmt_2000, 0 };
    static cilist io___14 = { 0, 6, 0, fmt_3000, 0 };










    if (*numb == 0) {
	goto L20;
    }
    if (*bottle) {
	items[17] = 0;
    }
    if (*numb == 1) {
	s_wsfe(&io___9);
	e_wsfe();
    }
    if (*numb == 1) {
	goto L100;
    }
    s_wsfe(&io___10);
    do_fio(&c__1, (char *)&(*numb), (ftnlen)sizeof(integer));
    e_wsfe();
L100:
    *numb = 0;
    if (! (*gun)) {
	goto L120;
    }
    items[19] = 0;
    items[1] = 0;
    s_wsfe(&io___11);
    do_fio(&c__2, (char *)&loaded, (ftnlen)sizeof(doublereal));
    e_wsfe();
L120:
    i__1 = *nitems;
    for (ii = 1; ii <= i__1; ++ii) {
	if (items[ii - 1] == -1) {
	    s_wsfe(&io___13);
	    do_fio(&c__2, (char *)&obj[ii - 1], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (items[ii - 1] == -1) {
	    ++(*numb);
	}
/* L10: */
    }
    if (*bottle) {
	items[17] = -1;
    }
    if (! (*gun)) {
	goto L15;
    }
    items[19] = -1;
    items[1] = -1;
    ++(*numb);
L15:
    if (*numb > 0) {
	return 0;
    }
L20:
    s_wsfe(&io___14);
    e_wsfe();
    return 0;
} /* invent_ */

#undef gun
#undef bottle
#undef water
#undef items
#undef blood
#undef numb
#undef loaded
#undef obj


