# CastleQuest_Amiga
Port of CastleQuest to Amiga with Speech

# Port of Castlequest (1980)

By Michael S. Holtzman and Mark Kershenblatt.


## Provenance

Port based on code from (https://github.com/Quuxplusone/Castlequest)

Info below copied from above GitHub.

The U.S. Copyright Office has a deposit related to this game:
[TXu000091366](https://cocatalog.loc.gov/cgi-bin/Pwebrecon.cgi?Search_Arg=TXu000091366&Search_Code=REGS&CNT=10&HIST=1)

On 2021-03-02, Mark Kershenblatt received 78 pages of paper copies
from the USCTO. He scanned them in and sent the scans to Arthur O'Dwyer,
in the form of two PDFs. Arthur rotated and concatenated the PDFs
into the single 78-page PDF in this repository, `castlequest.pdf`.

Arthur O'Dwyer manually transcribed the PDF into the plain text
file in this repository, `castlequest.ocr.txt`. (If you find any
places where the transcription differs from the original PDF,
Arthur will pay a "bug bounty" of $5 per error! Open a pull request
on this repository or send him an email.)

## Amiga Conversion

I used the excellent ForTran to C converter by Torsten Poulin (f2c) which is found on aminet under dev/lang.

I had to tweak the .f file to separate the data from the declarations (f2c didn't like the combined syntax), but other than that it worked like a charm.

Once in C I had to rewite the .dat loaders as the converted code didn't work.  I also had to rewrite the SAVE and RESTORE routines, but it was basically just dumping 400 integers into a file and reloading them into the same variable space.

Biggest job was redirecting all the text output from the original routines to a more C friendly printf routine, including parsing the ForTran format and making it compatible.  Once I had normal text strings, it was a relatively easy task to pass them via the Translator library to the narrator device to enable speech.

I added two verbs to the game, MUTE and TALK.  As you'd expect, MUTE turns off the speech and TALK enables it.

If there is enough/any interest, I would consider adding a config file to control the speech options.

All the Amiga C code was compiled use SAS/C.

## How to obtain
Ready to play binary is available in the releases folder.  Make sure the .dat files are in the same folder as the main program.

## How to compile
Compilation is though Shell using SAS/C.

You need to install the F2C includes and library as per the instructions here (https://aminet.net/dev/lang/f2c3.2bin.readme)

Once installed you should just be able to 'execute make' within the src directory.


