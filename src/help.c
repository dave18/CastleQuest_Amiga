/* help.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

extern struct {
    integer form[2000]	/* was [100][20] */, form2[1200]	/* was [60][
	    20] */, inst[1000]	/* was [50][20] */, long_[10000]	/* was [400][
	    20] */, hint[1000]	/* was [50][20] */;
} block1_;

#define block1_1 block1_

extern struct {
    integer savar[400];
} block2_;

#define block2_1 block2_


extern struct {
    long cierr;
    long ciunit;
    long ciend;
    char *cifmt;
    long cirec;
}   outstring;


extern void printstring();

/* -------------------------------------------------------------- */
/* Subroutine */ int help_(ii, object)
integer *ii, *object;
{
    /* Initialized data */

    static integer index[100] = { 29,1,0,0,0,2,0,3,4,5,5,0,25,0,0,26,0,6,7,0,
	    0,0,0,0,8,9,10,0,0,0,0,0,0,0,0,0,12,0,13,0,0,0,0,0,0,14,0,15,16,
	    17,0,0,0,18,19,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,24,23,
	    27,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    /* Format strings */
    static char fmt_1001[] = "(\0020  Would you like more detailed instructi\
ons?\002)";
    static char fmt_1003[] = "(\0020  It will cost you five points.\002,/\
,\002   Do you still want the hint?.\002)";
    static char fmt_1002[] = "(\0020  Sorry, not available.\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
#define fire ((integer *)&block2_1 + 84)
#define hole ((logical *)&block2_1 + 206)
#define lamp ((integer *)&block2_1 + 97)
#define prec ((logical *)&block2_1 + 85)
#define numb ((integer *)&block2_1 + 94)
#define door ((integer *)&block2_1 + 100)
#define wher ((integer *)&block2_1 + 70)
#define rope ((integer *)&block2_1 + 66)
#define note ((integer *)&block2_1 + 95)
#define wolf ((logical *)&block2_1 + 205)
#define melt ((logical *)&block2_1 + 207)
#define room ((integer *)&block2_1 + 60)
    extern /* Subroutine */ int yorn_();
#define wind1 ((integer *)&block2_1 + 86)
#define wind2 ((integer *)&block2_1 + 87)
    static integer i, j;
#define match ((integer *)&block2_1 + 68)
#define blood ((logical *)&block2_1 + 90)
#define hunch ((integer *)&block2_1 + 67)
#define gnome ((logical *)&block2_1 + 204)
#define score ((integer *)&block2_1 + 88)
#define value ((integer *)&block2_1 + 30)
#define ipass ((integer *)&block2_1 + 96)
#define torch ((logical *)&block2_1 + 208)
#define items ((integer *)&block2_1)
#define lmove ((integer *)&block2_1 + 99)
#define mmove ((integer *)&block2_1 + 98)
#define water ((logical *)&block2_1 + 92)
#define lroom ((integer *)&block2_1 + 61)
    static integer jj;
#define ibrief ((integer *)&block2_1 + 203)
#define ndeath ((integer *)&block2_1 + 200)
#define lokval ((integer *)&block2_1 + 81)
#define bottle ((logical *)&block2_1 + 91)
#define master ((integer *)&block2_1 + 69)
#define butval ((integer *)&block2_1 + 82)
#define maxscr ((integer *)&block2_1 + 202)
#define notval ((integer *)&block2_1 + 80)
#define ropval ((integer *)&block2_1 + 83)
#define numove ((integer *)&block2_1 + 89)
#define shuttr ((integer *)&block2_1 + 65)
#define bat ((logical *)&block2_1 + 63)
#define max_ ((integer *)&block2_1 + 201)
    static integer fmt[20];
#define gun ((logical *)&block2_1 + 62)
#define but ((integer *)&block2_1 + 64)
#define sun ((integer *)&block2_1 + 93)

    /* Fortran I/O blocks */
    static cilist io___48 = { 0, 6, 0, (char *)fmt, 0 };
    static cilist io___49 = { 0, 6, 0, fmt_1001, 0 };
    static cilist io___51 = { 0, 6, 0, (char *)fmt, 0 };
    static cilist io___52 = { 0, 6, 0, fmt_1001, 0 };
    static cilist io___53 = { 0, 6, 0, (char *)fmt, 0 };
    static cilist io___54 = { 0, 6, 0, fmt_1003, 0 };
    static cilist io___55 = { 0, 6, 0, (char *)fmt, 0 };
    static cilist io___56 = { 0, 6, 0, fmt_1002, 0 };














    if (*ii > 0) {
	goto L100;
    }
    for (i = 1; i <= 13; ++i) {
	for (j = 1; j <= 20; ++j) {
	    fmt[j - 1] = block1_1.inst[i + j * 50 - 51];
/* L5: */
	}
	//s_wsfe(&io___48);
	//e_wsfe();
        printstring(&io___48);
/* L10: */
    }
    //s_wsfe(&io___49);
    //e_wsfe();
    printstring(&io___49);
    yorn_(&jj);
    if (jj < 1) {
	goto L900;
    }

/* L20: */
    for (i = 14; i <= 19; ++i) {
	for (j = 1; j <= 20; ++j) {
	    fmt[j - 1] = block1_1.inst[i + j * 50 - 51];
/* L25: */
	}
	//s_wsfe(&io___51);
	//e_wsfe();
        printstring(&io___51);
/* L27: */
    }
    //s_wsfe(&io___52);
    //e_wsfe();
    printstring(&io___52);
    yorn_(&jj);
    if (jj == 0) {
	goto L900;
    }
/*     INSERT THIRD LEVEL INSTRUCTIONS. */

L28:
    for (i = 20; i <= 23; ++i) {
	for (j = 1; j <= 20; ++j) {
	    fmt[j - 1] = block1_1.inst[i + j * 50 - 51];
/* L30: */
	}
	//s_wsfe(&io___53);
	//e_wsfe();
        printstring(&io___53);
/* L32: */
    }
    goto L900;

L100:
    if (*object == 0) {
	goto L28;
    }
    jj = index[*object - 1];
    if (*object != 45) {
	goto L108;
    }
    jj = 0;
    if (*room == 20 && *bat) {
	jj = 19;
    }
    if (*room == 1 && *wind1 == 2) {
	jj = 8;
    }
    if (*room >= 57 && *room <= 64) {
	jj = 21;
    }
    if (*room == 65 && ! (*melt)) {
	jj = 22;
    }
    if (*room == 86 && ! (*hole)) {
	jj = 23;
    }
L108:
    if (jj == 0) {
	goto L115;
    }
    s_wsfe(&io___54);
    e_wsfe();
    yorn_(ii);
    if (*ii == 0) {
	goto L900;
    }
    for (j = 1; j <= 20; ++j) {
	fmt[j - 1] = block1_1.hint[jj + j * 50 - 51];
/* L110: */
    }
    //s_wsfe(&io___55);
    //e_wsfe();
    printstring(&io___55);
    *score += -5;
    goto L900;

L115:
/*     NO HINT AVAILABLE. */
    //s_wsfe(&io___56);
    //e_wsfe();
    printstring(&io___56);
    *ii = 0;
    goto L900;
L900:
    return 0;
} /* help_ */

#undef sun
#undef but
#undef gun
#undef max_
#undef bat
#undef shuttr
#undef numove
#undef ropval
#undef notval
#undef maxscr
#undef butval
#undef master
#undef bottle
#undef lokval
#undef ndeath
#undef ibrief
#undef lroom
#undef water
#undef mmove
#undef lmove
#undef items
#undef torch
#undef ipass
#undef value
#undef score
#undef gnome
#undef hunch
#undef blood
#undef match
#undef wind2
#undef wind1
#undef room
#undef melt
#undef wolf
#undef note
#undef rope
#undef wher
#undef door
#undef numb
#undef prec
#undef lamp
#undef hole
#undef fire


