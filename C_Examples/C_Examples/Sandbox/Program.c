void swap(int x, int y);

void main()
{
	int x = 1;
	int y = 2;

	swap(x, y);
}

void swap(int foo, int bar)
{
	int temp = foo;
	foo = bar;
	bar = temp;
}