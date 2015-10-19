#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


void *xcalloc (int, int );

void * _new (const void  *_class, ...)
{
	void *p;
	const struct Class *class = _class;
	p = xcalloc (1, class->size);
	*(unsigned int *)p = (unsigned int )class; 
	if ( class->constructor != NULL )
	{
		va_list ap;
		va_start (ap, _class);
		p = class->constructor (p, &ap);
		va_end (ap);
	}
	return p;
}

void *_delete (void *self)
{
	const struct Class *ptr = self;
	if ( self != NULL )
	{
		if ( ptr->destructor != NULL )
		{
			self = ptr->destructor (self);
		}
	}
	free (self);
}



void *xcalloc (int nr_elements, int size_per_element)
{
	void *ptr;
	ptr = calloc (nr_elements, size_per_element);
	if ( ptr == NULL)
	{
		fprintf (stderr, "calloc:fatal:out of memory\n");
		exit (EXIT_FAILURE);
	}
	return ptr;
}
