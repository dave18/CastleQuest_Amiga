/* input.f -- translated by f2c (version 19940615).
   You must link the resulting object file with the libraries:
	f2c.lib math=standard   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;

/* ------------------------------------------------------ */
/* Subroutine */ int input_(action)
integer *action;
{
    /* Initialized data */

    static integer nverbs = 82;
    static integer nnouns = 76;
    static struct {
	char e_1[4];
	integer e_2;
	} equiv_17 = { {' ', ' ', ' ', ' '}, 0 };

#define blank (*(integer *)&equiv_17)

    static struct {
	char e_1[4];
	integer e_2;
	char e_3[4];
	integer e_4;
	char e_5[4];
	integer e_6;
	char e_7[4];
	integer e_8;
	char e_9[4];
	integer e_10;
	char e_11[4];
	integer e_12;
	char e_13[4];
	integer e_14;
	char e_15[4];
	integer e_16;
	char e_17[4];
	integer e_18;
	char e_19[4];
	integer e_20;
	char e_21[4];
	integer e_22;
	char e_23[4];
	integer e_24;
	char e_25[4];
	integer e_26;
	char e_27[4];
	integer e_28;
	char e_29[4];
	integer e_30;
	char e_31[4];
	integer e_32;
	char e_33[4];
	integer e_34;
	char e_35[4];
	integer e_36;
	char e_37[4];
	integer e_38;
	char e_39[4];
	integer e_40;
	char e_41[4];
	integer e_42;
	char e_43[4];
	integer e_44;
	char e_45[4];
	integer e_46;
	char e_47[4];
	integer e_48;
	char e_49[4];
	integer e_50;
	char e_51[4];
	integer e_52;
	char e_53[4];
	integer e_54;
	char e_55[4];
	integer e_56;
	char e_57[4];
	integer e_58;
	char e_59[4];
	integer e_60;
	char e_61[4];
	integer e_62;
	char e_63[4];
	integer e_64;
	char e_65[4];
	integer e_66;
	char e_67[4];
	integer e_68;
	char e_69[4];
	integer e_70;
	char e_71[4];
	integer e_72;
	char e_73[4];
	integer e_74;
	char e_75[4];
	integer e_76;
	char e_77[4];
	integer e_78;
	char e_79[4];
	integer e_80;
	char e_81[4];
	integer e_82;
	char e_83[4];
	integer e_84;
	char e_85[4];
	integer e_86;
	char e_87[4];
	integer e_88;
	char e_89[4];
	integer e_90;
	char e_91[4];
	integer e_92;
	char e_93[4];
	integer e_94;
	char e_95[4];
	integer e_96;
	char e_97[4];
	integer e_98;
	char e_99[4];
	integer e_100;
	char e_101[4];
	integer e_102;
	char e_103[4];
	integer e_104;
	char e_105[4];
	integer e_106;
	char e_107[4];
	integer e_108;
	char e_109[4];
	integer e_110;
	char e_111[4];
	integer e_112;
	char e_113[4];
	integer e_114;
	char e_115[4];
	integer e_116;
	char e_117[4];
	integer e_118;
	char e_119[4];
	integer e_120;
	char e_121[4];
	integer e_122;
	char e_123[4];
	integer e_124;
	char e_125[4];
	integer e_126;
	char e_127[4];
	integer e_128;
	char e_129[4];
	integer e_130;
	char e_131[4];
	integer e_132;
	char e_133[4];
	integer e_134;
	char e_135[4];
	integer e_136;
	char e_137[4];
	integer e_138;
	char e_139[4];
	integer e_140;
	char e_141[4];
	integer e_142;
	char e_143[4];
	integer e_144;
	char e_145[4];
	integer e_146;
	char e_147[4];
	integer e_148;
	char e_149[4];
	integer e_150;
	char e_151[4];
	integer e_152;
	char e_153[4];
	integer e_154;
	char e_155[4];
	integer e_156;
	char e_157[4];
	integer e_158;
	char e_159[4];
	integer e_160;
        char e_161[4];
	integer e_162;
        char e_163[4];
	integer e_164;
	} equiv_18 = { {'A', 'T', 'T', 'A'}, 15, {'B', 'A', 'C', 'K'}, 40, {
		'B', 'R', 'E', 'A'}, 37, {'B', 'R', 'I', 'E'}, 61, {'C', 'H', 
		'O', 'P'}, 37, {'C', 'L', 'I', 'M'}, 9, {'C', 'L', 'O', 'S'}, 
		28, {'C', 'R', 'O', 'S'}, 43, {'D', ' ', ' ', ' '}, 10, {'D', 
		'E', 'B', 'U'}, 59, {'D', 'O', 'W', 'N'}, 10, {'D', 'R', 'I', 
		'N'}, 24, {'D', 'R', 'O', 'P'}, 12, {'E', ' ', ' ', ' '}, 3, {
		'E', 'A', 'S', 'T'}, 3, {'E', 'A', 'T', ' '}, 23, {'E', 'N', 
		'T', 'E'}, 13, {'E', 'X', 'I', 'T'}, 14, {'E', 'X', 'T', 'I'},
		 34, {'F', 'E', 'E', 'D'}, 22, {'F', 'I', 'L', 'L'}, 49, {'F',
		 'I', 'R', 'E'}, 54, {'F', 'U', 'C', 'K'}, 19, {'G', 'O', 'T',
		 'O'}, 51, {'H', 'E', 'L', 'P'}, 50, {'H', 'I', 'N', 'T'}, 50,
		 {'H', 'O', 'N', 'K'}, 45, {'I', 'N', ' ', ' '}, 13, {'I', 
		'N', 'V', 'E'}, 26, {'J', 'U', 'M', 'P'}, 25, {'K', 'I', 'L', 
		'L'}, 16, {'L', ' ', ' ', ' '}, 52, {'L', 'E', 'A', 'V'}, 14, 
		{'L', 'E', 'F', 'T'}, 52, {'L', 'I', 'G', 'H'}, 32, {'L', 'O',
		 'A', 'D'}, 18, {'L', 'O', 'C', 'K'}, 29, {'L', 'O', 'N', 'G'}
		, 60, {'L', 'O', 'O', 'K'}, 35, {'M', 'E', 'L', 'T'}, 42,{'M','U','T','E'},62, {
		'N', ' ', ' ', ' '}, 1, {'N', 'E', ' ', ' '}, 2, {'N', 'O', 
		'R', 'T'}, 1, {'N', 'W', ' ', ' '}, 8, {'O', 'F', 'F', ' '}, 
		33, {'O', 'N', ' ', ' '}, 31, {'O', 'P', 'E', 'N'}, 27, {'O', 
		'U', 'T', ' '}, 14, {'P', 'O', 'O', 'F'}, 56, {'P', 'O', 'U', 
		'R'}, 39, {'Q', 'U', 'I', 'T'}, 44, {'R', ' ', ' ', ' '}, 53, 
		{'R', 'E', 'A', 'D'}, 48, {'R', 'E', 'S', 'T'}, 58, {'R', 'I',
		 'G', 'H'}, 53, {'S', ' ', ' ', ' '}, 5, {'S', 'A', 'V', 'E'},
		 57, {'S', 'C', 'O', 'R'}, 36, {'S', 'E', ' ', ' '}, 4, {'S', 
		'H', 'O', 'O'}, 54, {'S', 'H', 'O', 'W'}, 20, {'S', 'O', 'U', 
		'T'}, 5, {'S', 'T', 'A', 'B'}, 21, {'S', 'U', 'S', 'P'}, 57, {
		'S', 'W', ' ', ' '}, 6, {'S', 'W', 'I', 'M'}, 41, {'T', ' ', 
		' ', ' '}, 11, {'T', 'A', 'K', 'E'}, 11,
                {'T','A','L','K'},63, {'T', 'H', 'R', 'O'},
		 17, {'T', 'I', 'E', ' '}, 46, {'U', ' ', ' ', ' '}, 9, {'U', 
		'N', 'L', 'O'}, 30, {'U', 'N', 'T', 'I'}, 47, {'U', 'P', ' ', 
		' '}, 9, {'V', 'E', 'R', 'B'}, 60, {'W', ' ', ' ', ' '}, 7, {
		'W', 'A', 'K', 'E'}, 55, {'W', 'A', 'T', 'E'}, 38, {'W', 'A', 
		'V', 'E'}, 20, {'W', 'E', 'S', 'T'}, 7};

#define verbs ((integer *)&equiv_18)

    static struct {
	char e_1[4];
	integer e_2;
	char e_3[4];
	integer e_4;
	char e_5[4];
	integer e_6;
	char e_7[4];
	integer e_8;
	char e_9[4];
	integer e_10;
	char e_11[4];
	integer e_12;
	char e_13[4];
	integer e_14;
	char e_15[4];
	integer e_16;
	char e_17[4];
	integer e_18;
	char e_19[4];
	integer e_20;
	char e_21[4];
	integer e_22;
	char e_23[4];
	integer e_24;
	char e_25[4];
	integer e_26;
	char e_27[4];
	integer e_28;
	char e_29[4];
	integer e_30;
	char e_31[4];
	integer e_32;
	char e_33[4];
	integer e_34;
	char e_35[4];
	integer e_36;
	char e_37[4];
	integer e_38;
	char e_39[4];
	integer e_40;
	char e_41[4];
	integer e_42;
	char e_43[4];
	integer e_44;
	char e_45[4];
	integer e_46;
	char e_47[4];
	integer e_48;
	char e_49[4];
	integer e_50;
	char e_51[4];
	integer e_52;
	char e_53[4];
	integer e_54;
	char e_55[4];
	integer e_56;
	char e_57[4];
	integer e_58;
	char e_59[4];
	integer e_60;
	char e_61[4];
	integer e_62;
	char e_63[4];
	integer e_64;
	char e_65[4];
	integer e_66;
	char e_67[4];
	integer e_68;
	char e_69[4];
	integer e_70;
	char e_71[4];
	integer e_72;
	char e_73[4];
	integer e_74;
	char e_75[4];
	integer e_76;
	char e_77[4];
	integer e_78;
	char e_79[4];
	integer e_80;
	char e_81[4];
	integer e_82;
	char e_83[4];
	integer e_84;
	char e_85[4];
	integer e_86;
	char e_87[4];
	integer e_88;
	char e_89[4];
	integer e_90;
	char e_91[4];
	integer e_92;
	char e_93[4];
	integer e_94;
	char e_95[4];
	integer e_96;
	char e_97[4];
	integer e_98;
	char e_99[4];
	integer e_100;
	char e_101[4];
	integer e_102;
	char e_103[4];
	integer e_104;
	char e_105[4];
	integer e_106;
	char e_107[4];
	integer e_108;
	char e_109[4];
	integer e_110;
	char e_111[4];
	integer e_112;
	char e_113[4];
	integer e_114;
	char e_115[4];
	integer e_116;
	char e_117[4];
	integer e_118;
	char e_119[4];
	integer e_120;
	char e_121[4];
	integer e_122;
	char e_123[4];
	integer e_124;
	char e_125[4];
	integer e_126;
	char e_127[4];
	integer e_128;
	char e_129[4];
	integer e_130;
	char e_131[4];
	integer e_132;
	char e_133[4];
	integer e_134;
	char e_135[4];
	integer e_136;
	char e_137[4];
	integer e_138;
	char e_139[4];
	integer e_140;
	char e_141[4];
	integer e_142;
	char e_143[4];
	integer e_144;
	char e_145[4];
	integer e_146;
	char e_147[4];
	integer e_148;
	char e_149[4];
	integer e_150;
	char e_151[4];
	integer e_152;
	} equiv_19 = { {'A', 'C', 'I', 'D'}, 25, {'A', 'L', 'L', ' '}, 31, {
		'A', 'X', 'E', ' '}, 3, {'B', 'A', 'R', 'S'}, 54, {'B', 'A', 
		'T', ' '}, 55, {'B', 'L', 'O', 'O'}, 5, {'B', 'O', 'A', 'R'}, 
		56, {'B', 'O', 'A', 'T'}, 14, {'B', 'O', 'O', 'K'}, 46, {'B', 
		'O', 'T', 'T'}, 18, {'B', 'U', 'L', 'L'}, 2, {'B', 'U', 'T', 
		'L'}, 49, {'C', 'A', 'S', 'K'}, 40, {'C', 'H', 'A', 'M'}, 7, {
		'C', 'I', 'G', 'A'}, 27, {'C', 'O', 'F', 'F'}, 40, {'C', 'O', 
		'M', 'P'}, 57, {'C', 'O', 'U', 'N'}, 39, {'C', 'R', 'O', 'S'},
		 19, {'C', 'R', 'Y', 'S'}, 30, {'C', 'Y', 'C', 'L'}, 78, {'D',
		 'O', 'O', 'R'}, 47, {'D', 'R', 'A', 'W'}, 48, {'F', 'I', 'G',
		 'U'}, 24, {'F', 'I', 'R', 'E'}, 34, {'F', 'L', 'A', 'S'}, 25,
		 {'F', 'O', 'O', 'D'}, 22, {'G', 'L', 'A', 'C'}, 79, {'G', 
		'N', 'O', 'M'}, 77, {'G', 'R', 'A', 'P'}, 16, {'G', 'U', 'N', 
		' '}, 20, {'H', 'A', 'T', 'C'}, 3, {'H', 'O', 'O', 'K'}, 16, {
		'H', 'U', 'N', 'C'}, 8, {'I', 'C', 'E', ' '}, 79, {'I', 'V', 
		'O', 'R'}, 12, {'J', 'A', 'D', 'E'}, 24, {'K', 'E', 'R', 'O'},
		 1, {'K', 'E', 'Y', ' '}, 4, {'L', 'A', 'M', 'P'}, 21, {'L', 
		'A', 'N', 'T'}, 21, {'L', 'I', 'G', 'H'}, 21, {'L', 'O', 'C', 
		'K'}, 33, {'M', 'A', 'S', 'T'}, 39, {'M', 'A', 'T', 'C'}, 15, 
		{'M', 'I', 'R', 'R'}, 50, {'M', 'O', 'A', 'T'}, 51, {'M', 'O',
		 'N', 'E'}, 29, {'N', 'O', 'T', 'E'}, 52, {'O', 'I', 'L', ' '}
		, 1, {'P', 'A', 'P', 'E'}, 10, {'P', 'E', 'N', ' '}, 11, {'P',
		 'I', 'S', 'T'}, 20, {'Q', 'U', 'I', 'L'}, 11, {'R', 'O', 'O',
		 'M'}, 45, {'R', 'O', 'P', 'E'}, 9, {'R', 'O', 'W', 'B'}, 14, 
		{'R', 'U', 'B', 'Y'}, 23, {'S', 'A', 'P', 'P'}, 28, {'S', 'H',
		 'U', 'T'}, 38, {'S', 'T', 'A', 'K'}, 6, {'S', 'T', 'A', 'T'},
		 17, {'S', 'W', 'A', 'N'}, 30, {'S', 'W', 'O', 'R'}, 12, {'T',
		 'O', 'R', 'C'}, 13, {'T', 'U', 'N', 'N'}, 41, {'V', 'A', 'M',
		 'P'}, 39, {'V', 'L', 'A', 'D'}, 39, {'W', 'A', 'T', 'E'}, 26,
		 {'W', 'E', 'R', 'E'}, 76, {'W', 'I', 'N', 'D'}, 37, {'W', 
		'I', 'Z', 'A'}, 80, {'W', 'O', 'L', 'F'}, 76, {'3', '1', ' ', 
		' '}, 43, {'5', '9', ' ', ' '}, 44, {'8', ' ', ' ', ' '}, 42 }
		;

#define nouns ((integer *)&equiv_19)


    /* Format strings */
    static char fmt_2004[] = "(\002 \002)";
    static char fmt_2002[] = "(\002\n  Do WHAT with the \002,2a4,a2,\002??\
\002)";
    static char fmt_2003[] = "(\002\n  I don't think I understand.\002)";
    static char fmt_2001[] = "(\002\n  \002,2a4,a2,\002what???\002)";

    /* System generated locals */
    integer i__1;
    static integer equiv_0[3], equiv_1[3];

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer high;
#define verb (equiv_0)
#define noun (equiv_1)
    static integer i;
#define n (equiv_1)
    extern /* Subroutine */ int fread_();
#define v (equiv_0)
    static integer low;

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 6, 0, fmt_2004, 0 };
    static cilist io___14 = { 0, 6, 0, fmt_2002, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_2003, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_2001, 0 };





    /* Parameter adjustments */
    --action;

    /* Function Body */





    action[1] = 0;
    action[2] = 0;
L3:
    s_wsfe(&io___10);
    e_wsfe();
    fread_(verb, noun);
/*     CALL MOVEC(4,VERB,V,21) */
/*     CALL MOVEC(4,NOUN,N,21) */
    low = 1;
    high = nverbs;
    //printf("i__1 = %x  v=%x  n=%x high=%d\n",i__1,v[0],n[0],high);
L18:
    //printf("i=%d \n",i);
    if (high < low) {
	goto L21;
    }
    i = (low + high) / 2;
    if ((i__1 = *v - verbs[(i << 1) - 2]) < 0) {
	goto L19;
    } else if (i__1 == 0) {
	goto L22;
    } else {
	goto L20;
    }
L19:
    high = i - 1;
    goto L18;
L20:
    low = i + 1;
    goto L18;
L21:
    if (*n != blank) {
	s_wsfe(&io___14);
	do_fio(&c__3, (char *)&noun[0], (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*n == blank) {
	s_wsfe(&io___15);
	e_wsfe();
    }
    goto L3;

/*     LOOK FOR A NOUN.... */

L22:
    action[1] = verbs[(i << 1) - 1];
    if (*n == blank) {
	goto L45;
    }
    low = 1;
    high = nnouns;
L26:
    if (high < low) {
	goto L30;
    }
    i = (low + high) / 2;
    if ((i__1 = *n - nouns[(i << 1) - 2]) < 0) {
	goto L27;
    } else if (i__1 == 0) {
	goto L40;
    } else {
	goto L28;
    }
L27:
    high = i - 1;
    goto L26;
L28:
    low = i + 1;
    goto L26;
L30:
    if (action[1] == 19) {
	goto L40;
    }
/* L31: */
    s_wsfe(&io___16);
    do_fio(&c__3, (char *)&verb[0], (ftnlen)sizeof(integer));
    e_wsfe();
    goto L3;
L40:
    action[2] = nouns[(i << 1) - 1];
L45:
    if (action[1] == 10 && action[2] != 0) {
	action[1] = 12;
    }
    return 0;
} /* input_ */

#undef v
#undef n
#undef noun
#undef verb
#undef nouns
#undef verbs
#undef blank


