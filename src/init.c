/* init.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include <stdio.h>

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
    logical debug;
    integer iseed;
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
long fs,fs2;
FILE * filein;


//**** Read in strings from a dat file ****
integer readfromdat(char * buf_,integer s_,integer n_,FILE * f_)
{
    long i;
    fs=0;
    for (i=0;i<s_;i++)
    {
        fs2=fread(buf_+i,1,1,f_);
     //   printf("Read %d bytes into address %d (total bytes %d)\n",fs2,buf_+i,fs+fs2);
        fs+=fs2;
        if (fs2==0) {
       //     printf ("return as no bytes read (EOF?)\n");
            return -1;
        }
        if (buf_[i]==0x0A) {
      //      printf ("return as LF reached\n");
            return -2;
        }
    }
    //printf ("return normal\n");
    return 0;
 
}

/* --------------------------------------------------------------- */
/* Subroutine */ int init_()
{
    /* Initialized data */

    static integer v[30] = { 0,0,0,0,0,0,10,0,0,0,0,10,0,0,0,0,20,0,25,0,0,0,
	    10,10,0,0,0,10,10,10 };
    static integer t[30] = { 25,1,33,-3,18,12,55,35,19,3,15,88,36,32,13,11,29,
	    31,0,3,22,6,81,52,14,0,10,77,94,89 };
    static integer d[100] = { -2,0,-2,2,-2,0,2,-2,-2,-2,-2,-2,2,-2,-2,-2,-2,
	    -2,-2,-2,0,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,
	    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    static integer w[10] = { 28,15,28,9,28,15,15,9,28,15 };

    /* Format strings */
    static char fmt_1001[] = "(20a4)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
#define fire ((logical *)&block2_1 + 84)
#define hole ((logical *)&block2_1 + 206)
#define lamp ((integer *)&block2_1 + 97)
#define prec ((logical *)&block2_1 + 85)
#define wher ((integer *)&block2_1 + 70)
#define door ((integer *)&block2_1 + 100)
#define rope ((integer *)&block2_1 + 66)
#define numb ((integer *)&block2_1 + 94)
#define note ((integer *)&block2_1 + 95)
#define wolf ((logical *)&block2_1 + 205)
#define room ((integer *)&block2_1 + 60)
#define melt ((logical *)&block2_1 + 207)
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
#define ibrief ((integer *)&block2_1 + 203)
#define ndeath ((integer *)&block2_1 + 200)
#define masect ((logical *)&block2_1 + 210)
#define lokval ((integer *)&block2_1 + 81)
#define bottle ((logical *)&block2_1 + 91)
#define master ((integer *)&block2_1 + 69)
#define butval ((integer *)&block2_1 + 82)
#define maxscr ((integer *)&block2_1 + 202)
#define notval ((integer *)&block2_1 + 80)
#define ropval ((integer *)&block2_1 + 83)
#define numove ((integer *)&block2_1 + 89)
  //  extern /* Subroutine */ int rstart_();
#define shuttr ((integer *)&block2_1 + 65)
#define bat ((logical *)&block2_1 + 63)
  //  extern /* Subroutine */ int cms_();
#define max_ ((integer *)&block2_1 + 201)
#define gun ((logical *)&block2_1 + 62)
#define but ((integer *)&block2_1 + 64)
#define sun ((integer *)&block2_1 + 93)
#define wiz ((logical *)&block2_1 + 209)
#define mas1 ((logical *)&block2_1 + 211)
#define mas2 ((logical *)&block2_1 + 212)
#define mas3 ((logical *)&block2_1 + 213)
#define mas4 ((logical *)&block2_1 + 214)

    /* Fortran I/O blocks */
    static cilist io___60 = { 1, 9, 1, fmt_1001, 0 };
    static cilist io___62 = { 1, 10, 1, fmt_1001, 0 };
    static cilist io___63 = { 1, 11, 1, fmt_1001, 0 };
    static cilist io___64 = { 1, 12, 1, fmt_1001, 0 };
    static cilist io___65 = { 1, 8, 1, fmt_1001, 0 };



















/*     CALL CMDNOE('$CONTROL *MSOURCE* K=UC',23) */
/*     CALL CMDNOE('$C AWCC:CASTMES',15) */
/*    cms_("TYPE    ", "CASTMES ", "MEMO    ", 8L, 8L, 8L);*/
/*     CALL TIME(22,0,TME) */
/*     IF (TME(1) .EQ. SAT .OR. TME(1) .EQ. SUND) GOTO 15 */
/*     IF (LCOMC(8,TME(5),OPEN) .EQ.  1) GOTO 15 */
/*     IF (LCOMC(8,TME(5),OPN ) .EQ. -1) GOTO 15 */
/*     WRITE(6,1002) */
/*     CALL YORN(M) */
/*     IF(M.EQ.0) STOP */
/*     WRITE(6,1003) */
/*     CALL CMDNOE('$CONTROL *MSINK* BLANK=6', 24) */
/*     READ(5,1004)(INPUT(L),L=1,5) */
/*     IF(LCOMC(3,TME(1),INPUT) .EQ. 0) GOTO 15 */
/*     WRITE(6,1005) */
/*     STOP */
/* L15: */

    for (i = 1; i <= 400; ++i) {
	block2_1.savar[i - 1] = 0;
/* L18: */
    }
/*     CALL GUINFO(44,ISEED) */

    //rstart_(&_BLNK__1.iseed);
    _BLNK__1.iseed = (_BLNK__1.iseed << 1) + 1;
    for (i = 1; i <= 30; ++i) {
	value[i - 1] = v[i - 1];
	items[i - 1] = t[i - 1];
	door[i - 1] = d[i - 1];
	if (i <= 10) {
	    wher[i - 1] = w[i - 1];
	}
/* L16: */
    }
    for (i = 31; i <= 100; ++i) {
	door[i - 1] = d[i - 1];
/* L17: */
    }

    _BLNK__1.debug = FALSE_;
    *bottle = FALSE_;
    *blood = FALSE_;
    *water = FALSE_;
    *gnome = FALSE_;
    *wolf = FALSE_;
    *hole = FALSE_;
    *melt = FALSE_;
    *wiz = TRUE_;
    *torch = FALSE_;
    *masect = FALSE_;
    *rope = 0;
    *room = 1;
    *lroom = 1;
    *ibrief = 0;
    *match = 0;
    *ropval = 10;
    *butval = 5;
    *notval = 15;
    *lokval = 5;
    *sun = 0;
    *master = 0;
    *numb = 0;
    *gun = FALSE_;
    *prec = FALSE_;
    *note = 0;
    *wind1 = 0;
    *wind2 = 0;
    *but = 0;
    *shuttr = 0;
    *ipass = 0;
    *bat = TRUE_;
    *lamp = 0;
    *numove = 0;
    *hunch = 0;
    *mmove = 0;
    *lmove = 0;
    *score = 0;
    *fire = TRUE_;
    *mas1 = FALSE_;
    *mas2 = FALSE_;
    *mas3 = FALSE_;
    *mas4 = FALSE_;
    *ndeath = 0;
    *max_ = 99;
    *maxscr = 300;

/*     CALL FTNCMD('ASSIGN 5=*SOURCE*;') */
/*     CALL FTNCMD('ASSIGN 6=*SINK*;') */
/*     CALL FTNCMD('ASSIGN 8=AWCC:HINT;') */
/*     CALL FTNCMD('ASSIGN 9=AWCC:SHORT;') */
/*     CALL FTNCMD('ASSIGN 10=AWCC:OBJECT;') */
/*     CALL FTNCMD('ASSIGN 11=AWCC:INST;') */
/*     CALL FTNCMD('ASSIGN 12=AWCC:LONG;') */
/* *** */
/*    cms_("FI      ", "8       ", "DISK    ", "HINT    ", "CQDATA  ", "(     \
  ", "LRECL  ", "80      ", "RECFM   ", "F       ", 8L, 8L, 8L, 8L, 8L, 8L, 
	    7L, 8L, 8L, 8L);
    cms_("FI      ", "9       ", "DISK    ", "SHORT   ", "CQDATA  ", "(     \
  ", "LRECL  ", "80      ", "RECFM   ", "F       ", 8L, 8L, 8L, 8L, 8L, 8L, 
	    7L, 8L, 8L, 8L);
    cms_("FI      ", "10      ", "DISK    ", "OBJECT  ", "CQDATA  ", "(     \
  ", "LRECL  ", "80      ", "RECFM   ", "F       ", 8L, 8L, 8L, 8L, 8L, 8L, 
	    7L, 8L, 8L, 8L);
    cms_("FI      ", "11      ", "DISK    ", "INST    ", "CQDATA  ", "(     \
  ", "LRECL  ", "80      ", "RECFM   ", "F       ", 8L, 8L, 8L, 8L, 8L, 8L, 
	    7L, 8L, 8L, 8L);
    cms_("FI      ", "12      ", "DISK    ", "LONG    ", "CQDATA  ", "(     \
  ", "LRECL  ", "80      ", "RECFM   ", "F       ", 8L, 8L, 8L, 8L, 8L, 8L, 
	    7L, 8L, 8L, 8L);*/


    filein=fopen("short.dat","rb");
    for (i = 1; i <= 100; ++i) {

	for (j = 1; j <= 20; ++j) {
            i__1=readfromdat((char *)&block1_1.form[i+j * 100 - 101],4,1,filein);
	    if (i__1 == -1) {
		goto L30;
	    }
	    if (i__1 == -2) {
		goto L20;
	    }
	}
L20: 
    }
L30:
    fclose(filein);

        filein=fopen("object.dat","rb");
    for (i = 1; i <= 60; ++i) {

	for (j = 1; j <= 20; ++j) {
            i__1=readfromdat((char *)&block1_1.form2[i+j * 60 - 61],4,1,filein);
	    if (i__1 == -1) {
		goto L50;
	    }
	    if (i__1 == -2) {
		goto L40;
	    }
	}

L40: 
    }
L50:
    fclose (filein);
    filein=fopen("inst.dat","rb");
    for (i = 1; i <= 50; ++i) {

	for (j = 1; j <= 20; ++j) {
            i__1=readfromdat((char *)&block1_1.inst[i+j * 50 - 51],4,1,filein);
	    if (i__1 == -1) {
		goto L80;
	    }
	    if (i__1 == -2) {
		goto L60;
	    }
	}
L60: 
    }
L80:
    fclose(filein);

    filein=fopen("long.dat","rb");
    for (i = 1; i <= 400; ++i) {

	for (j = 1; j <= 20; ++j) {
            i__1=readfromdat((char *)&block1_1.long_[i+j * 400 - 401],4,1,filein);
	    if (i__1 == -1) {
		goto L100;
	    }
	    if (i__1 == -2) {
		goto L90;
	    }
	}

 L90: 
    }
L100:
    fclose(filein);

    filein=fopen("hint.dat","rb");
    for (i = 1; i <= 50; ++i) {

	for (j = 1; j <= 20; ++j) {
            i__1=readfromdat((char *)&block1_1.hint[i+j * 50 - 51],4,1,filein);
	    if (i__1 == -1) {
		goto L120;
	    }
	    if (i__1 == -2) {
		goto L110;
	    }
	}        
L110: 
    }
L120:
    fclose(filein);
/*     CALL FTNCMD('RELEASE 9;') */
/*     CALL FTNCMD('RELEASE 10;') */
/*     CALL FTNCMD('RELEASE 11;') */
/*     CALL FTNCMD('RELEASE 12;') */
/*     CALL FTNCMD('RELEASE 8;') */
/* L1002: */
/* L1003: */
/* L1004: */
/* L1005: */
    return 0;
} /* init_ */

#undef mas4
#undef mas3
#undef mas2
#undef mas1
#undef wiz
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
#undef masect
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
#undef melt
#undef room
#undef wolf
#undef note
#undef numb
#undef rope
#undef door
#undef wher
#undef prec
#undef lamp
#undef hole
#undef fire


