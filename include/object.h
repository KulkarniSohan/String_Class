#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdarg.h>

void *string_ctor (void *self, va_list *ap);
void *string_dtor (void *self);


struct String 
{
	const void *this;
	char *text;
};

struct Class
{
	size_t size;
	void * (*constructor) (void *self, va_list *ap);
	void * (*destructor) (void *self);
};

static const struct Class _string = {	
	sizeof ( struct String),
	&string_ctor,
	&string_dtor
};


void *string_ctor (void *self, va_list *ap)
{
	struct String *string = self;
	const char *text = va_arg (*ap, const char *);
	string->text = malloc (sizeof (char) * strlen ( text ) + 1);
	if ( string->text == NULL )
	{
		fprintf (stderr, "malloc :  fatal : out of memory\n");
		exit (EXIT_FAILURE);
	}
	strcpy (string->text, text );
	return string;
}


void *string_dtor (void *self)
{
	struct String *string = self;
	free (string->text);
	return string;
}


const void *string = & _string;
