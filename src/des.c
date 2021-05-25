/* des.f -- translated by f2c (version 19940615).
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
    integer form[2000]	/* was [100][20] */, form2[1200]	/* was [60][
	    20] */, inst[1000]	/* was [50][20] */, long_[10000]	/* 
	    was [400][25] */, hint[1000]	/* was [50][20] */;
} block1_;

#define block1_1 block1_

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

/* -------------------------------------------------------------- */
/* Subroutine */ int des_(room)
integer *room;
{
    /* Initialized data */

    static integer first[101] = { 1,6,8,12,16,19,23,26,31,33,37,40,42,45,49,
	    51,52,54,56,58,61,64,66,67,71,73,76,79,81,83,85,89,92,95,97,101,
	    104,106,110,112,117,124,129,135,140,142,145,149,154,156,158,160,
	    163,165,168,173,176,177,178,179,180,181,182,183,184,190,193,203,
	    206,211,214,217,222,228,231,236,240,244,247,250,255,260,262,266,
	    269,273,275,283,287,291,293,300,303,309,312,317,323,328,332,333,
	    341 };

    /* Format strings */
    static char fmt_9797[] = "(\0020  REQUEST FOR DESCRIPTION #\002,i4)";
    static char fmt_2003[] = "(\0020  NO DESCRIPTION-MESSAGE NUMBER \002,i4)";
    static char fmt_9898[] = "(\0020  THE FIRST AND LAST LINE OF LONG ARE:\
 \002,2i5)";
    static char fmt_7001[] = "(\0020  You leap through the open window and a\
re\002)";
    static char fmt_7002[] = "(\002   dashed into pieces on the rocks below\
.\002)";
    static char fmt_7004[] = "(\0020  A thick black smoke fills the room,\
 \002,\002engulfing you in\002)";
    static char fmt_7005[] = "(\002   lethal choking fumes (smoking is bad f\
or\002,\002 your health).\002)";
    static char fmt_7007[] = "(\0020  You leap into the pit and fall for hou\
rs.  You land \002)";
    static char fmt_7008[] = "(\002   on some moist \"undead\" bodies and ar\
e eaten alive.\002)";
    static char fmt_7010[] = "(\0020  My, My.  You seem to have bitten the d\
ust.\002)";
    static char fmt_7011[] = "(\002   I can attempt to reincarnate you, but \
I'm\002)";
    static char fmt_7012[] = "(\002   not very good at it. Should I try?\002)"
	    ;
    static char fmt_7013[] = "(\0020  You fall weightlessly through a thick \
mist.\002)";
    static char fmt_7014[] = "(\002   Your head is spinning as you emerge an\
d find\002,\002...\002,/\002 \002)";
    static char fmt_7015[] = "(\0020  You seem to have died again.  I can tr\
y and \002)";
    static char fmt_7016[] = "(\002   reincarnate you, but you're taxing m\
y  \002,\002patience.\002)";
    static char fmt_7017[] = "(\0020  Would you like me to try??\002)";
    static char fmt_7018[] = "(\0020  You float aimlessly through a green mi\
st which\002)";
    static char fmt_7019[] = "(\002   transcends time and space. You regain \
your \002)";
    static char fmt_7020[] = "(\002   senses and realize that ...\002,/\002\
 \002)";
    static char fmt_7021[] = "(\0020  You did it again, didn't you? I'm afra\
id \002,\002that\002)";
    static char fmt_7022[] = "(\002   all the mist has evaporated.  I'm so s\
orry,\002)";
    static char fmt_7023[] = "(\002   but this means you are dead for good\
.\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer j, ff, ii, ll, fmt[20];


    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, fmt_9797, 0 };
    static cilist io___4 = { 0, 6, 0, fmt_2003, 0 };
    static cilist io___6 = { 0, 6, 0, fmt_9898, 0 };
    static cilist io___10 = { 0, 6, 0, (char *)fmt, 0 };
    static cilist io___11 = { 0, 6, 0, fmt_7001, 0 };
    static cilist io___12 = { 0, 6, 0, fmt_7002, 0 };
    static cilist io___13 = { 0, 6, 0, fmt_7004, 0 };
    static cilist io___14 = { 0, 6, 0, fmt_7005, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_7007, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_7008, 0 };
    static cilist io___17 = { 0, 6, 0, fmt_7010, 0 };
    static cilist io___18 = { 0, 6, 0, fmt_7011, 0 };
    static cilist io___19 = { 0, 6, 0, fmt_7012, 0 };
    static cilist io___20 = { 0, 6, 0, fmt_7013, 0 };
    static cilist io___21 = { 0, 6, 0, fmt_7014, 0 };
    static cilist io___22 = { 0, 6, 0, fmt_7015, 0 };
    static cilist io___23 = { 0, 6, 0, fmt_7016, 0 };
    static cilist io___24 = { 0, 6, 0, fmt_7017, 0 };
    static cilist io___25 = { 0, 6, 0, fmt_7018, 0 };
    static cilist io___26 = { 0, 6, 0, fmt_7019, 0 };
    static cilist io___27 = { 0, 6, 0, fmt_7020, 0 };
    static cilist io___28 = { 0, 6, 0, fmt_7021, 0 };
    static cilist io___29 = { 0, 6, 0, fmt_7022, 0 };
    static cilist io___30 = { 0, 6, 0, fmt_7023, 0 };
    static cilist io___31 = { 0, 6, 0, (char *)fmt, 0 };
    static cilist io___32 = { 0, 6, 0, (char *)fmt, 0 };





    if (_BLNK__1.debug) {
	s_wsfe(&io___2);
	do_fio(&c__1, (char *)&(*room), (ftnlen)sizeof(integer));
	e_wsfe();
    }

    if (*room == 300) {
	*room = 100;
    }

    if (*room > 200 && *room < 300) {
	goto L100;
    }
    if (*room >= 400 && *room < 500) {
	goto L190;
    }
    if (*room > 600 && *room < 700) {
	goto L200;
    }
    if (*room == 801) {
	goto L50;
    }
    if (*room == 803) {
	goto L60;
    }
    if (*room == 805) {
	goto L64;
    }
    if (*room == 850) {
	goto L66;
    }
    if (*room == 851) {
	goto L68;
    }
    if (*room == 852) {
	goto L70;
    }
    if (*room == 853) {
	goto L72;
    }
    if (*room == 854) {
	goto L74;
    }
    ff = first[*room - 1];
    if (ff > 0) {
	goto L3;
    }
    s_wsfe(&io___4);
    do_fio(&c__1, (char *)&(*room), (ftnlen)sizeof(integer));
    e_wsfe();
    goto L900;
L3:
    ll = first[*room] - 1;
    if (_BLNK__1.debug) {
	s_wsfe(&io___6);
	do_fio(&c__1, (char *)&ff, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ll, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    i__1 = ll;
    for (ii = ff; ii <= i__1; ++ii) {
	for (j = 1; j <= 20; ++j) {
	    fmt[j - 1] = block1_1.long_[ii + j * 400 - 401];
/* L5: */
	}
	//s_wsfe(&io___10);
	//e_wsfe();
        //printf("io___10 \n");
        printstring(&io___10);
/* L10: */
    }
    goto L900;
L50:
    /*s_wsfe(&io___11);
    e_wsfe();
    s_wsfe(&io___12);
    e_wsfe();*/
    printstring(&io___11);
    printstring(&io___12);
    goto L900;
L60:
    /*s_wsfe(&io___13);
    e_wsfe();
    s_wsfe(&io___14);
    e_wsfe();*/
    printstring(&io___13);
    printstring(&io___14);
    goto L900;
L64:
    /*s_wsfe(&io___15);
    e_wsfe();
    s_wsfe(&io___16);
    e_wsfe();*/
    printstring(&io___15);
    printstring(&io___16);
    goto L900;
L66:
    /*s_wsfe(&io___17);
    e_wsfe();
    s_wsfe(&io___18);
    e_wsfe();
    s_wsfe(&io___19);
    e_wsfe();*/
    printstring(&io___17);
    printstring(&io___18);
    printstring(&io___19);
    goto L900;
L68:
    /*s_wsfe(&io___20);
    e_wsfe();
    s_wsfe(&io___21);
    e_wsfe();*/
    printstring(&io___20);
    printstring(&io___21);
    goto L900;
L70:
    /*s_wsfe(&io___22);
    e_wsfe();
    s_wsfe(&io___23);
    e_wsfe();
    s_wsfe(&io___24);
    e_wsfe();*/
    printstring(&io___22);
    printstring(&io___23);
    printstring(&io___24);
    goto L900;
L72:
    /*s_wsfe(&io___25);
    e_wsfe();
    s_wsfe(&io___26);
    e_wsfe();
    s_wsfe(&io___27);
    e_wsfe();*/
    printstring(&io___25);
    printstring(&io___26);
    printstring(&io___27);
    goto L900;
L74:
    /*s_wsfe(&io___28);
    e_wsfe();
    s_wsfe(&io___29);
    e_wsfe();
    s_wsfe(&io___30);
    e_wsfe();*/
    printstring(&io___28);
    printstring(&io___29);
    printstring(&io___30);
    goto L900;

L100:
    ii = *room - 200;
    for (j = 1; j <= 20; ++j) {
	fmt[j - 1] = block1_1.form[ii + j * 100 - 101];
/* L110: */
    }
    //s_wsfe(&io___31);
    //e_wsfe();
    //printf("io___31");
    printstring(&io___31);
    goto L900;

L190:
    ii = *room - 369;
    goto L205;
L200:
    ii = *room - 600;
L205:
    for (j = 1; j <= 20; ++j) {
	fmt[j - 1] = block1_1.form2[ii + j * 60 - 61];
/* L210: */
    }
    //s_wsfe(&io___32);
    //e_wsfe();
    //printf("io___32 \n");
    printstring(&io___32);

L900:

/* L2001: */

/* L7024: */
    return 0;
} /* des_ */

