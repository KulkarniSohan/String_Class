#include <object.h>
#include <new.h>

int main (void)
{
	void *a;
	void *b;

	a = _new (string, "Sohan");
	b = _new (string, "Kulkarni");
	
	printf ("\n\t String of a : %s\n", ((struct String *)a)->text);
	printf ("\n\t String of b : %s\n", ((struct String *)b)->text);

	_delete (a);
	_delete (b);
}
