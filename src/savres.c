/* savres.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include <stdio.h>
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

FILE * filehandle;

/* --------------------------------------------- */
/* Subroutine */ int savres_(ii)
integer *ii;
{
    /* Format strings */
    static char fmt_3002[] = "(10z8)";
    static char fmt_3005[] = "(\002\n  I can't do that at this point in time\
.\002)";

    /* System generated locals */
    integer i__1;
    alist al__1;

    /* Builtin functions */
    integer f_rew(), s_wsfe(), do_fio(), e_wsfe(), s_rsfe(), e_rsfe();

    /* Local variables */
    static integer k, l, kk;
   // extern /* Subroutine */ int cms_();

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 13, 0, fmt_3002, 0 };
    static cilist io___5 = { 0, 13, 0, fmt_3002, 0 };
    static cilist io___6 = { 0, 6, 0, fmt_3005, 0 };




    if (*ii == 0) {
	goto L158;
    }
/*     ---SUSPEND--- */
/*     CALL CREATE('SAVEDQUEST ',1,0,256) */
/*     CALL PERMIT('SAVEDQUEST ',7,6,11,'AWCC:CASTLE',0) */
/*     CALL FTNCMD('ASSIGN 8=SAVEDQUEST;') */
/*    cms_("FI      ", "13      ", "DISK    ", "QUEST   ", "CQDATA  ", "(     \
  ", "LRECL   ", "80      ", "RECFM   ", "F       ", 8L, 8L, 8L, 8L, 8L, 8L, 
	    8L, 8L, 8L, 8L);*/
/*    al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
    l = 1;
    for (*ii = 1; *ii <= 40; ++(*ii)) {
	k = l + 9;
	s_wsfe(&io___3);
	i__1 = k;
	for (kk = l; kk <= i__1; ++kk) {
	    do_fio(&c__1, (char *)&block2_1.savar[kk - 1], (ftnlen)sizeof(
		    integer));
	}
	e_wsfe();
	l += 10;*/
     
       filehandle=fopen("SAVEDQUEST","wb");
       if (filehandle)
       {
           fwrite(block2_1.savar,4,400,filehandle);
           fclose(filehandle);
       }


/* L3001: */
//    }
/*     CALL FTNCMD('RELEASE 8;') */
    goto L9000;
L158:
/*     ---RESTORE--- */
    if (block2_1.savar[89] > 1) {
	goto L740;
    }
/*     CALL FTNCMD('ASSIGN 8=SAVEDQUEST;') */
/*    cms_("FI      ", "13      ", "DISK    ", "QUEST   ", "CQDATA  ", "(     \
  ", "LRECL   ", "80      ", "RECFM   ", "F       ", 8L, 8L, 8L, 8L, 8L, 8L, 
	    8L, 8L, 8L, 8L);*/
    /*al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
    l = 1;
    for (*ii = 1; *ii <= 40; ++(*ii)) {
	k = l + 9;
	s_rsfe(&io___5);
	i__1 = k;
	for (kk = l; kk <= i__1; ++kk) {
	    do_fio(&c__1, (char *)&block2_1.savar[kk - 1], (ftnlen)sizeof(
		    integer));
	}
	e_rsfe();
	l += 10;*/
    
        filehandle=fopen("SAVEDQUEST","rb");
       if (filehandle)
       {
           fread(block2_1.savar,4,400,filehandle);
           fclose(filehandle);
       }


/* L3003: */
 //   }
/*     CALL FTNCMD('RELEASE 8;') */
    goto L9000;
L740:
    s_wsfe(&io___6);
    e_wsfe();
L9000:
    return 0;
} /* savres_ */

