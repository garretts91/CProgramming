void swap(int* param_1, int* param_2);
//void swap(int param_1, int param_2);

void main()
{
	int x = 1;
	int y = 2;

	swap(&x, &y);
	//swap(x, y);
}

void swap(int* param_1, int* param_2)
{
	int temp = *param_1;
	*param_1 = *param_2;
	*param_2 = temp;
}

//void swap(int param_1, int param_2)
//{
//	int temp = param_1;
//	param_1 = param_2;
//	param_2 = temp;
//}