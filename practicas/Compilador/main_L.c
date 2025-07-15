//++++++++++++ BIBLIOTECAS ++++++++++
#include<ctype.h>
#include<stdio.h>
#define DS_IMPLEMENTATION
#include"ds.h"
#include<string.h>
//-+-+-+-+-+ Estructuras -+-+-+-+-+-+
//

//	Inician estructuras para el ANALISIS LEXICO

//Tipo de dato TOKEN inicia definicion
//requiere de una dato enumerado para identificar el tipo de Lexer
enum token_kind{
	IDENT,
	LABEL,
	INT,
	INPUT,
	OUTPUT,
	GOTO,
	IF,
	THEN,
	EQUAL,
	PLUS,
	LESS_THAN,
	INVALID,
	END
};
struct token{//los toquen estan formados por pares(lexer, valor)
	enum token_kind kind; //Almacenamos el dato Tipo de TOKEN
	char *value;//Algunso TOKEN requiren valores
};
//Tipo de dato TOKEN termina definicion

//Tipo de dato LEXER inicia definicion
struct lexer{//esta estructura guarda los datos necesarios para realizar el analisis lexico
	char *buffer;
	unsigned int buffer_len;
	unsigned int pos;//posición del caracter guardado en la variable chr (de mas abajo)
	unsigned read_pos;//siguiente posición a leer para el analisis (peek)
	char ch;//caracter leido para ingresar al automata finito
};
//Tipo de dato LEXER termina definicion
//	Terminan estructuras para el ANALISIS LEXICO

//-+-+-+-+-+ Inician prototipos de las funciones -+-+-+-+-+-+
//
//Inician protos de funciones para el analisis LEXICO

//inician sub funciones de apoyo
//static char lexer_peek_char(struct lexer *l);
//static char lexer_read_char(struct lexer *l);
//static void skip_whitespaces(struct lexer *l);
//terminan sub funciones de apoyo

//funciones principales
static void lexer_init(struct lexer *l, char *buffer, unsigned int buffer_len);
static struct token lexer_next_token(struct lexer *l);
int lexer_tokenize(char *buffer, unsigned int lenght, ds_dynamic_array *tokens);
//Termina protos de funciones para el analisis LEXICO

//Inician funciones para visualizar el contenido del arreglo dinamico de Tokens (tabla de simbolos)
const char *show_token_kind(enum token_kind kind);
void print_token(struct token tok);
//Terminan funciones para visualizar el contenido del arreglo dinamico de Tokens (tabla de simbolos)

//-+-+-+-+-+ Terminan prototipos de las funciones -+-+-+-+-+-+
int main(){
	char *buffer=NULL;//preparamos el buffer donde almacenaremos los caracteres durante la traducción
	int length=ds_io_read_file(NULL, &buffer);//Leeremos desde el "archivo" STDOUT (salida estandar) de linux
	
	//------------- ANALISIS LEXICO Inicia ------------	
	ds_dynamic_array tokens;//usando una funcion de libreria externa creamos un arreglo dinamico para los tokens
	ds_dynamic_array_init(&tokens, sizeof(struct token));//inicalizamos el arreglo de tokens 
							     //con el dato struct token
	lexer_tokenize(buffer, length, &tokens);//Metodo que realiza el ANALISIS LEXICO	retorna el resultado
						//en una variable Estatica de array tipo TOKEN
	//------------- ANALISIS LEXICO Finaliza ------------	
	


	return 0;
}

//=========== DEFINICIONES DE LAS FUNCIONES ==========
//
//	ANALISIS LEXICO
//inician sub funciones de apoyo
static char lexer_peek_char(struct lexer *l) 
{
    if (l->read_pos >= l->buffer_len) {
        return EOF;
    }

    return l->buffer[l->read_pos];
}

static char lexer_read_char(struct lexer *l) 
{
    l->ch = lexer_peek_char(l);

    l->pos = l->read_pos;
    l->read_pos += 1;

    return l->ch;
}

static void skip_whitespaces(struct lexer *l) 
{
    while (isspace(l->ch)) {
        lexer_read_char(l);
    }
}
//terminan sub funciones de apoyo

//Inician definiciones PRINCIPALES
static void lexer_init(struct lexer *l, char *buffer, unsigned int buffer_len) 
{
    l->buffer = buffer;
    l->buffer_len = buffer_len;
    l->pos = 0;
    l->read_pos = 0;
    l->ch = 0;

    lexer_read_char(l);
}

static struct token lexer_next_token(struct lexer *l) 
{
    skip_whitespaces(l);

    if (l->ch == EOF) {
        lexer_read_char(l);
        return (struct token){.kind = END, .value = NULL};
    } else if (l->ch == '=') {
        lexer_read_char(l);
        return (struct token){.kind = EQUAL, .value = NULL};
    } else if (l->ch == '+') {
        lexer_read_char(l);
        return (struct token){.kind = PLUS, .value = NULL};
    } else if (l->ch == '<') {
        lexer_read_char(l);
        return (struct token){.kind = LESS_THAN, .value = NULL};
    } else if (l->ch == ':') {
        lexer_read_char(l);
        ds_string_slice slice = {.str = l->buffer + l->pos, .len = 0};
        while (isalnum(l->ch) || l->ch == '_') {
            slice.len += 1;
            lexer_read_char(l);
        }
        char *value = NULL;
        ds_string_slice_to_owned(&slice, &value);
        return (struct token){.kind = LABEL, .value = value};
    } else if (isdigit(l->ch)) {
        ds_string_slice slice = {.str = l->buffer + l->pos, .len = 0};
        while (isdigit(l->ch)) {
            slice.len += 1;
            lexer_read_char(l);
        }
        char *value = NULL;
        ds_string_slice_to_owned(&slice, &value);
        return (struct token){.kind = INT, .value = value};
    } else if (isalnum(l->ch) || l->ch == '_') {
        ds_string_slice slice = {.str = l->buffer + l->pos, .len = 0};
        while (isalnum(l->ch) || l->ch == '_') {
            slice.len += 1;
            lexer_read_char(l);
        }
        char *value = NULL;
        ds_string_slice_to_owned(&slice, &value);
        if (strcmp(value, "input") == 0) {
            return (struct token){.kind = INPUT, .value = NULL};
        } else if (strcmp(value, "output") == 0) {
            return (struct token){.kind = OUTPUT, .value = NULL};
        } else if (strcmp(value, "goto") == 0) {
            return (struct token){.kind = GOTO, .value = NULL};
        } else if (strcmp(value, "if") == 0) {
            return (struct token){.kind = IF, .value = NULL};
        } else if (strcmp(value, "then") == 0) {
            return (struct token){.kind = THEN, .value = NULL};
        } else {
            return (struct token){.kind = IDENT, .value = value};
        }
    } else {
        ds_string_slice slice = {.str = l->buffer + l->pos, .len = 1};
        char *value = NULL;
        ds_string_slice_to_owned(&slice, &value);
        lexer_read_char(l);
        return (struct token){.kind = INVALID, .value = value};
    }
}
//Terminan definiciones PRINCIPALES

//Inician definiciones para Depuracion
int lexer_tokenize(char *buffer, unsigned int length, ds_dynamic_array *tokens)
{
	struct lexer lexer;
	lexer_init(&lexer, (char *)buffer, length);

	struct token tok;
	do{
		tok = lexer_next_token(&lexer);
		if (ds_dynamic_array_append(tokens, &tok) != 0){
			DS_PANIC("Failed to append token to array");
		}
		// funcion para ir observando la generación de los tokens
		print_token(tok);
		//se usa para Depuración
	} while (tok.kind != END);
	
	return 0;
}

const char *show_token_kind(enum token_kind kind) 
{
    switch (kind) {
    case IDENT:
        return "ident";
    case LABEL:
        return "label";
    case INT:
        return "int";
    case INPUT:
        return "input";
    case OUTPUT:
        return "output";
    case GOTO:
        return "goto";
    case IF:
        return "if";
    case THEN:
        return "then";
    case EQUAL:
        return "equal";
    case PLUS:
        return "plus";
    case LESS_THAN:
        return "less_than";
    case INVALID:
        return "invalid";
    case END:
        return "end";
    }
}

void print_token(struct token tok) 
{
    const char *kind = show_token_kind(tok.kind);
    printf("%s", kind);
    if (tok.value != NULL) {
        printf("(%s)", tok.value);
    }
    printf("\n");
}

//Terminan definiciones para Depuracion

