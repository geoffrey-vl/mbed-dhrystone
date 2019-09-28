#include "dhrystone22.h"
#include <stdio.h> // strcpy, strcmp 
#include <stdlib.h> //malloc
#include <string.h> //strcpy
#include "Timer.h"

#define Version "C, Version 2.2"


#define NUMBER_OF_RUNS 50000  //Default number of runs


#define CLOCK_TYPE "mbed::Timer"
mbed::Timer timer;
#undef HZ
#define HZ				(1000)		// mbed::Timer returns time in milliseconds (=1000Hz resolution)
#define TOO_SMALL_TIME	(2*HZ)		// Measurements should last at least 2 seconds
#define US_PER_SECOND	1000000.0
#define VAX_11_780_DHRYSTONES_PER_SECOND 1757 	// the number of Dhrystones per second obtained on the VAX 11/780, nominally a 1 MIPS machine

// Procedure for the assignment of structures,
// if the C compiler doesn't support this feature
#ifdef  NOSTRUCTASSIGN
#define structassign(d, s)      memcpy(&(d), &(s), sizeof(d))
#else
#define structassign(d, s)      d = s
#endif


// General definitions:
#define Null 0      // Value of a Null pointer
#define true  1
#define false 0

typedef enum {
    Ident_1, Ident_2, Ident_3, Ident_4, Ident_5
} Enumeration;

typedef int     One_Thirty;
typedef int     One_Fifty;
typedef char    Capital_Letter;
typedef int     Boolean;
typedef char    Str_30 [31];
typedef int     Arr_1_Dim [50];
typedef int     Arr_2_Dim [50] [50];

struct Record 
{
    struct Record *Ptr_Comp;
    Enumeration Discr;
    union {
        struct {
            Enumeration Enum_Comp;
            int Int_Comp;
            char Str_Comp [31];
        } var_1;
        struct {
            Enumeration E_Comp_2;
            char Str_2_Comp [31];
        } var_2;
        struct {
            char Ch_1_Comp;
            char Ch_2_Comp;
        } var_3;
    } variant;
};
typedef struct Record Rec_Type;
typedef Rec_Type *Rec_Pointer;


#ifndef REG
Boolean Reg = false;
#define REG
// REG becomes defined as empty
// i.e. no register variables
#else
Boolean Reg = true;
#undef REG
#define REG register
#endif

// private Global Variables:
Rec_Pointer     g_Ptr,
                g_NextPtr;
int             g_Int;
Boolean         g_Bool;
char            g_Char1,
                g_Char2;
int             g_Array1 [50];
int             g_Array2 [50] [50];
//public global vars:
long            g_dry_UserTime;
float           g_dry_Microseconds,
                g_dry_Dhrystones_Per_Second,
				g_dmips,
				g_efficiency_per_mhz;


// Functions:
void Proc_1 (REG Rec_Pointer ptrValPar) ;
void Proc_2 (One_Fifty* intParRef);
void Proc_3 (Rec_Pointer* ptrRefPar);
void Proc_4 ();
void Proc_5 ();
void Proc_6 (Enumeration enumValPar, Enumeration* enumRefPar);
void Proc_7 (One_Fifty int1ParVal, One_Fifty int2ParVal, One_Fifty* intParRef);
void Proc_8 (Arr_1_Dim arr1ParRef, Arr_2_Dim arr2ParRef, int int1ParVal, int int2ParVal);
Enumeration Func_1 (Capital_Letter ch1ParVal, Capital_Letter ch2ParVal);
bool Func_2 (Str_30 str1ParRef, Str_30 str2ParRef);
bool Func_3 (Enumeration enumParVal);

void Proc_0 (uint32_t loops)
{
	One_Fifty int1Loc;
	REG One_Fifty int2Loc;
	One_Fifty int3Loc;
	REG char charIndex;
	Enumeration enumLoc;
	Str_30 str1Loc;
	Str_30 str2Loc;
	REG int runIndex;
	REG int numberOfRuns = loops;
	if (numberOfRuns <= 0)
	{
		numberOfRuns = NUMBER_OF_RUNS;
	}

	// Initializations

	g_NextPtr = (Rec_Pointer) malloc (sizeof (Rec_Type));
	g_Ptr = (Rec_Pointer) malloc (sizeof (Rec_Type));

	g_Ptr->Ptr_Comp                    = g_NextPtr;
	g_Ptr->Discr                       = Ident_1;
	g_Ptr->variant.var_1.Enum_Comp     = Ident_3;
	g_Ptr->variant.var_1.Int_Comp      = 40;
	strcpy (g_Ptr->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING");
	strcpy (str1Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

	g_Array2 [8][7] = 10;
	// Was missing in published program. Without this statement,
	// g_Array2 [8][7] would have an undefined value.
	// Warning: With 16-Bit processors and numberOfRuns > 32000,
	// overflow may occur for this array element.

	printf ("\n");
	printf ("Dhrystone Benchmark, Version %s\n", Version);
	if (Reg)
	{
		printf ("Program compiled with 'register' attribute\n");
	}
	else
	{
		printf ("Program compiled without 'register' attribute\n");
	}
	printf ("Using %s, HZ=%d\n", CLOCK_TYPE, HZ);
	printf ("\n");

	timer.stop();
	Boolean done = false;
	while (!done) {

		printf ("Trying %d runs through Dhrystone:\n", numberOfRuns);

		/***************/
		/* Start timer */
		/***************/
		timer.reset();
		timer.start();

		for (runIndex = 1; runIndex <= numberOfRuns; ++runIndex)
		{

			Proc_5();
			Proc_4();

			int1Loc = 2;
			int2Loc = 3;
			strcpy (str2Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
			enumLoc = Ident_2;
			g_Bool = ! Func_2 (str1Loc, str2Loc);

			while (int1Loc < int2Loc)
			{
				// loop body executed once 
				int3Loc = 5 * int1Loc - int2Loc;
				Proc_7 (int1Loc, int2Loc, &int3Loc);
				int1Loc += 1;
			}

			Proc_8 (g_Array1, g_Array2, int1Loc, int3Loc);

			Proc_1 (g_Ptr);

			for (charIndex = 'A'; charIndex <= g_Char2; ++charIndex)
			{
				// loop body executed twice 
				if (enumLoc == Func_1 (charIndex, 'C'))
				{
					Proc_6 (Ident_1, &enumLoc);
					strcpy (str2Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
					int2Loc = runIndex;
					g_Int = runIndex;
				}
			}

			int2Loc = int2Loc * int1Loc;
			int1Loc = int2Loc / int3Loc;
			int2Loc = 7 * (int2Loc - int3Loc) - int1Loc;

			Proc_2 (&int1Loc);
		}

		/**************/
		/* Stop timer */
		/**************/
		timer.stop();

		g_dry_UserTime = timer.read_ms();

		if (g_dry_UserTime < TOO_SMALL_TIME)
		{
			printf ("Measured time too small to obtain meaningful results\n");
			numberOfRuns = numberOfRuns * 10;
			printf ("\n");
		} else 
			done = true;
	}

    fprintf (stderr, "Final values of the variables used in the benchmark:\n");
	fprintf (stderr, "\n");
	fprintf (stderr, "Int_Glob:            %d\n", g_Int);
	fprintf (stderr, "        should be:   %d\n", 5);
	fprintf (stderr, "Bool_Glob:           %d\n", g_Bool);
	fprintf (stderr, "        should be:   %d\n", 1);
	fprintf (stderr, "Ch_1_Glob:           %c\n", g_Char1);
	fprintf (stderr, "        should be:   %c\n", 'A');
	fprintf (stderr, "Ch_2_Glob:           %c\n", g_Char2);
	fprintf (stderr, "        should be:   %c\n", 'B');
	fprintf (stderr, "Arr_1_Glob[8]:       %d\n", g_Array1[8]);
	fprintf (stderr, "        should be:   %d\n", 7);
	fprintf (stderr, "Arr_2_Glob[8][7]:    %d\n", g_Array2[8][7]);
	fprintf (stderr, "        should be:   Number_Of_Runs + 10\n");
	fprintf (stderr, "Ptr_Glob->\n");
	fprintf (stderr, "  Ptr_Comp:          %d\n", (int) g_Ptr->Ptr_Comp);
	fprintf (stderr, "        should be:   (implementation-dependent)\n");
	fprintf (stderr, "  Discr:             %d\n", g_Ptr->Discr);
	fprintf (stderr, "        should be:   %d\n", 0);
	fprintf (stderr, "  Enum_Comp:         %d\n", g_Ptr->variant.var_1.Enum_Comp);
	fprintf (stderr, "        should be:   %d\n", 2);
	fprintf (stderr, "  Int_Comp:          %d\n", g_Ptr->variant.var_1.Int_Comp);
	fprintf (stderr, "        should be:   %d\n", 17);
	fprintf (stderr, "  Str_Comp:          %s\n", g_Ptr->variant.var_1.Str_Comp);
	fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
	fprintf (stderr, "Next_Ptr_Glob->\n");
	fprintf (stderr, "  Ptr_Comp:          %d\n", (int) g_NextPtr->Ptr_Comp);
	fprintf (stderr, "        should be:   (implementation-dependent), same as above\n");
	fprintf (stderr, "  Discr:             %d\n", g_NextPtr->Discr);
	fprintf (stderr, "        should be:   %d\n", 0);
	fprintf (stderr, "  Enum_Comp:         %d\n", g_NextPtr->variant.var_1.Enum_Comp);
	fprintf (stderr, "        should be:   %d\n", 1);
	fprintf (stderr, "  Int_Comp:          %d\n", g_NextPtr->variant.var_1.Int_Comp);
	fprintf (stderr, "        should be:   %d\n", 18);
	fprintf (stderr, "  Str_Comp:          %s\n", g_NextPtr->variant.var_1.Str_Comp);
	fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
	fprintf (stderr, "Int_1_Loc:           %d\n", int1Loc);
	fprintf (stderr, "        should be:   %d\n", 5);
	fprintf (stderr, "Int_2_Loc:           %d\n", int2Loc);
	fprintf (stderr, "        should be:   %d\n", 13);
	fprintf (stderr, "Int_3_Loc:           %d\n", int3Loc);
	fprintf (stderr, "        should be:   %d\n", 7);
	fprintf (stderr, "Enum_Loc:            %d\n", enumLoc);
	fprintf (stderr, "        should be:   %d\n", 1);
	fprintf (stderr, "Str_1_Loc:           %s\n", str1Loc);
	fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
	fprintf (stderr, "Str_2_Loc:           %s\n", str2Loc);
	fprintf (stderr, "        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
	fprintf (stderr, "\n");

	g_dry_Microseconds = (float) g_dry_UserTime * US_PER_SECOND 
		                / ((float) HZ * ((float) numberOfRuns));
	g_dry_Dhrystones_Per_Second = ((float) HZ * (float) numberOfRuns)
		                / (float) g_dry_UserTime;
	g_dmips = g_dry_Dhrystones_Per_Second / VAX_11_780_DHRYSTONES_PER_SECOND;
	g_efficiency_per_mhz = g_dmips / (SystemCoreClock/1000000);

	printf ("Microseconds for one run through Dhrystone: ");
	printf ("%10.1f \n", g_dry_Microseconds);
	printf ("Dhrystones per Second:                      ");
	printf ("%10.0f \n", g_dry_Dhrystones_Per_Second);
	printf ("DMIPS:                                      ");
	printf ("%10.0f \n", g_dmips);
	printf ("Efficiancy per Mhz:                         ");
	printf ("%10.2f \n", g_efficiency_per_mhz);
	printf ("\n");
}



/**
 * executed once
 */
void Proc_1 (REG Rec_Pointer ptrValPar) 
{
    REG Rec_Pointer nextRecord = ptrValPar->Ptr_Comp;  
    // Local variable, initialized with ptrValPar->Ptr_Comp,
    // corresponds to "rename" in Ada, "with" in Pascal
  
    structassign (*ptrValPar->Ptr_Comp, *g_Ptr); 
    ptrValPar->variant.var_1.Int_Comp = 5;
    nextRecord->variant.var_1.Int_Comp = ptrValPar->variant.var_1.Int_Comp;
    nextRecord->Ptr_Comp = ptrValPar->Ptr_Comp;

    Proc_3 (&nextRecord->Ptr_Comp);

    if (nextRecord->Discr == Ident_1)
    {
        nextRecord->variant.var_1.Int_Comp = 6;

        Proc_6 (ptrValPar->variant.var_1.Enum_Comp, &nextRecord->variant.var_1.Enum_Comp);

        nextRecord->Ptr_Comp = g_Ptr->Ptr_Comp;

        Proc_7 (nextRecord->variant.var_1.Int_Comp, 10, &nextRecord->variant.var_1.Int_Comp);
    }
    else
        structassign (*ptrValPar, *ptrValPar->Ptr_Comp);
}


/**
 * executed once
 * *intParRef == 1, becomes 4
 */
void Proc_2 (One_Fifty* intParRef)
{
    One_Fifty intLoc;  
    Enumeration enumLoc;

    intLoc = *intParRef + 10;
    do {
        /* executed once */
        if (g_Char1 == 'A')
        {
            intLoc -= 1;
            *intParRef = intLoc - g_Int;
            enumLoc = Ident_1;
        }
    } while (enumLoc != Ident_1);
}


/**
 * executed once
 * ptrRefPar becomes g_Ptr
 */
void Proc_3 (Rec_Pointer* ptrRefPar)
{
    if (g_Ptr != Null)
        *ptrRefPar = g_Ptr->Ptr_Comp;

    Proc_7(10, g_Int, &g_Ptr->variant.var_1.Int_Comp);
}


/**
 * executed once
 */ 
void Proc_4 ()
{
    Boolean boolLoc;

    boolLoc = g_Char1 == 'A';
    g_Bool = boolLoc | g_Bool;
    g_Char2 = 'B';
}


/**
 * executed once
 */ 
void Proc_5 ()
{
    g_Char1 = 'A';
    g_Bool = false;
}


/**
 * executed once
 * enumValPar == Ident_3, enumRefPar becomes Ident_2
 */ 
void Proc_6 (Enumeration enumValPar, Enumeration* enumRefPar)
{
    *enumRefPar = enumValPar;
    if (! Func_3 (enumValPar))
        *enumRefPar = Ident_4;

    switch (enumValPar)
    {
        case Ident_1: 
            *enumRefPar = Ident_1;
            break;
        case Ident_2: 
            if (g_Int > 100)
                *enumRefPar = Ident_1;
            else 
                *enumRefPar = Ident_4;
            break;
        case Ident_3:
            *enumRefPar = Ident_2;
            break;
        case Ident_4: 
            break;
        case Ident_5: 
            *enumRefPar = Ident_3;
            break;
    }
}


/** 
 * executed three times
 * first call:      int1ParVal == 2, int2ParVal == 3,
 *                  intParRef becomes 7
 * second call:     int1ParVal == 10, int2ParVal == 5,
 *                  intParRef becomes 17
 * third call:      int1ParVal == 6, int2ParVal == 10,
 *                  intParRef becomes 18
 */ 
void Proc_7 (One_Fifty int1ParVal, One_Fifty int2ParVal, One_Fifty* intParRef)
{
    One_Fifty intLoc;

    intLoc = int1ParVal + 2;
    *intParRef = int2ParVal + intLoc;
}


/** 
 * executed once
 * Int_Par_Val_1 == 3
 * Int_Par_Val_2 == 7
 */ 
void Proc_8 (Arr_1_Dim arr1ParRef, Arr_2_Dim arr2ParRef, int int1ParVal, int int2ParVal)
{
    REG One_Fifty intIndex;
    REG One_Fifty intLoc;

    intLoc = int1ParVal + 5;
    arr1ParRef [intLoc] = int2ParVal;
    arr1ParRef [intLoc+1] = arr1ParRef [intLoc];
    arr1ParRef [intLoc+30] = intLoc;
    for (intIndex = intLoc; intIndex <= intLoc+1; ++intIndex)
        arr2ParRef [intLoc] [intIndex] = intLoc;
    arr2ParRef [intLoc] [intLoc-1] += 1;
    arr2ParRef [intLoc+20] [intLoc] = arr1ParRef [intLoc];
    g_Int = 5;
}


/** 
 * executed three times
 * first call:      ch1ParVal == 'H', ch2ParVal == 'R'
 * second call:     ch1ParVal == 'A', ch2ParVal == 'C'
 * third call:      ch1ParVal == 'B', ch2ParVal == 'C'
 */
Enumeration Func_1 (Capital_Letter ch1ParVal, Capital_Letter ch2ParVal)
{
    Capital_Letter ch1Loc;
    Capital_Letter ch2Loc;

    ch1Loc = ch1ParVal;
    ch2Loc = ch1Loc;
    if (ch2Loc != ch2ParVal) {
        return (Ident_1);
    } else
    {
        g_Char1 = ch1Loc;
        return (Ident_2);
    }
}


/** 
 * executed once
 * str1ParRef == "DHRYSTONE PROGRAM, 1'ST STRING" 
 * str2ParRef == "DHRYSTONE PROGRAM, 2'ND STRING" 
 */
bool Func_2 (Str_30 str1ParRef, Str_30 str2ParRef)
{
    REG One_Thirty intLoc;
    Capital_Letter Ch_Loc;

    intLoc = 2;
    while (intLoc <= 2)  { 
        // loop body executed once
        if (Func_1 (str1ParRef[intLoc], str2ParRef[intLoc+1]) == Ident_1) {
            Ch_Loc = 'A';
            intLoc += 1;
        }
    }
    if (Ch_Loc >= 'W' && Ch_Loc < 'Z') {
        intLoc = 7;
    }
    if (Ch_Loc == 'R') {
        return (true);
    } else
    {
        if (strcmp (str1ParRef, str2ParRef) > 0)
        {
            intLoc += 7;
            g_Int = intLoc;
            return (true);
        }
        else 
            return (false);
    }
}


/**
 *  executed once
 *  enumParVal == Ident_3 
 */
bool Func_3 (Enumeration enumParVal)
{
    Enumeration enumLoc;

    enumLoc = enumParVal;
    if (enumLoc == Ident_3)
        return (true);
    else
        return (false);
}