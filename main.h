#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "src/tokenizer.h"
#include "src/parser.h"
#include "src/types.h"
#include "src/errors.h"
#include "src/util/print.h"
#include "src/util/str.h"

typedef enum __attribute__((__packed__)) Langs {
	L_UNKN,
	L_JS,
	L_C,
	L_ASM
} Lang;

extern int main(int, string *);
