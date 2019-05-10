/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.string.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: snprintf
 *    BadSink : Copy string to data using snprintf
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF snprintf
#endif

wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_badData;
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68b_badSink();

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_bad()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = dataBadBuffer;
    data[0] = L'\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_badData = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68b_badSink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    data[0] = L'\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_goodG2BData = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68b_goodG2BSink();
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif