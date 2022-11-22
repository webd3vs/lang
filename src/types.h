#ifndef __LANG_TYPES_H
#define __LANG_TYPES_H 1

#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include "util/array.h"

typedef unsigned char small;
typedef unsigned char bool;
typedef char *string;

#define true (bool)1
#define false (bool)0

typedef enum __attribute__((__packed__)) Types {
	// COMPARE
	CMP_EQ,  //* ==
	CMP_GT,  //* >
	CMP_LT,  //* <
	CMP_NEQ, //* !=
	CMP_LEQ, //* <=
	CMP_GEQ, //* >=

	// ASSIGN
	EQ,        // * =
	ADD_EQ,    // * +=
	SUB_EQ,    // * -=
	MUL_EQ,    // * *=
	DIV_EQ,    // * /=
	INCR,      // * ++
	DECR,      // * --
	LAND_EQ,   // * &&=
	LOR_EQ,    // * ||=
	BAND_EQ,   // * &=
	BOR_EQ,    // * |=
	BXOR_EQ,   // * ^=
	BNOT_EQ,   // * ~=
	REM_EQ,    // * %=
	RSHIFT_EQ, // * >>=
	LSHIFT_EQ, // * <<=

	// KEYWORD
	FOR,
	CLASS,
	FUNC,
	TRUE,
	FALSE,
	_NULL,
	WHILE,
	IF,
	DO,
	ELSE,
	FROM,
	IMPORT,
	NEW,
	AWAIT,
	AS,
	ASYNC,
	RET,

	// TYPE
	STR,      //* "hello world"
	NAME,     //* var_name
	DEC,      //* 123
	DOT,      //* .
	DELMT,    //* ;
	SEP,      //* ,
	AT,       //* @
	UNDEF,
	BRACKET,  //* []
	PAREN,    //* ()
	CBRACKET, //* {}
	HEX,      //* 0xff
	OCTAL,    //* 0o77
	BIN,      //* 0b1111
	COLON,    //* :
	_EOF,     //* \0

	// OPERATION
	ADD,    //* +
	SUB,    //* -
	MUL,    //* *
	DIV,    //* /
	LAND,   //* &&
	LOR,    //* ||
	BAND,   //* &
	BOR,    //* |
	BXOR,   //* ^
	BNOT,   //* ~
	LNOT,   //* !
	LSHIFT, //* <<
	RSHIFT, //* >>
	POW,    //* **
	REM     //* %
} Type;

typedef struct Point {
	int line;
	int character;
} Point;

typedef struct Position {
	Point start;
	Point end;
	int absoluteStart;
	int absoluteEnd;
} Position;

typedef struct Token {
	Type type;
	Position pos;
} Token;

typedef enum __attribute__((__packed__)) AST_Types {
	PROGRAM = 1,
	IMPORT_DECLARATION,
	IMPORT_SPECIFIER
} AST_Type;

typedef struct Typed {
	AST_Type type;
} Typed;

typedef struct Program { // extends Typed
	AST_Type type;
	Array *body;
} Program;

typedef struct ImportSpecifier { // extends Typed
	AST_Type type;
	string name;
	string local;
} ImportSpecifier;

typedef struct ImportDeclaration { // extends Typed
	AST_Type type;
	string source;
	Array *specifiers;
} ImportDeclaration;

typedef struct Result {
	Array *errors;
	void *data;
} Result;

extern void freeProgram(Program *);
extern string getType(Type, ...);
extern Program *initProgram(int);
extern ImportSpecifier *initImportSpecifier(string name, string local_name);
extern ImportDeclaration *initImportDeclaration(string, Array *import_specifier_array);

#endif
