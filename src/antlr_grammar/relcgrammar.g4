grammar relcgrammar;

LONG_LITERAL: ('-')?[0-9]+('U')?'L'('L')?;
INT_LITERAL: ('-')?[0-9]+('U')?;
FLOAT_LITERAL: [0-9]+.[0-9]+;

TYPE: ('void'|'char'|'int'|'long long'|'long');
CONST: 'const';

NativeProtoDecl: '__nativedecl';

ID: [a-zA-Z_][a-zA-Z0-9_]*;

fragment ESC: '\\' .;
CHAR: '\'' (ESC|.) '\'';

PLUS: '+';
MINUS: '-';
MULT: '*';
DIV: '/';
EQUAL: '=';

SEMI: ';';
COMMA: ',';

LPAREN: '(';
RPAREN: ')';

LCURL: '{';
RCURL: '}';
NATIVE_SCOPE: '::';

WS: [ \t\r\n]+ -> skip;

program: global_statement+;
global_statement:
	native_func_prototype
	| func_prototype
	| func_body
	;
statement:
	assignment SEMI
	| initialization SEMI
	| exp SEMI
	| assignment
	| initialization
	| exp
	;
assignment:
	ID EQUAL exp
	;
initialization:
	CONST TYPE ID EQUAL exp
	| TYPE ID EQUAL exp
	;
exp:
	LPAREN exp RPAREN
	| exp MULT exp
	| exp DIV exp
	| exp PLUS exp
	| exp MINUS exp	
	| native_call
	| ID LPAREN arguments_list RPAREN
	| ID LPAREN RPAREN
	| ID
	| LONG_LITERAL
	| INT_LITERAL
	| FLOAT_LITERAL
	| CHAR	
	;
native_call: NATIVE_SCOPE ID LPAREN (arguments_list)? RPAREN;
arguments_list:	exp (COMMA exp)*;
parameter:
	TYPE ID
	| CONST TYPE ID
	;
parameters_list: parameter (COMMA parameter)*;
native_func_prototype: NativeProtoDecl LPAREN ID RPAREN func_prototype;
func_prototype: func_declaration SEMI;
func_declaration:
	TYPE ID LPAREN parameters_list RPAREN
	| TYPE ID LPAREN RPAREN
	;
scope: statement+;
bordered_scope:	LCURL scope RCURL;
func_scope:
	bordered_scope
	| LCURL RCURL
	;
func_body: func_declaration func_scope;