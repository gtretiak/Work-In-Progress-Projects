#include "header.h"

struct	abstract
{
	int	width;
	int	height;
};

void	calc(struct abstract *obj)
{
	int res = obj->width * obj->height;
	printf("result: %d\n", res);
}

int	main(void)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	y = 0;
	printf("set value for x:");
	scanf("%d", &x);
	printf("set value for y:");
	scanf("%d", &y);
	res = x + y;
	printf("Hello, res = %d\n", res);
	switch(res)
	{
		case 10: printf("10!\n");
			 break;
		case 5: printf("5!\n");
			break;
			default:
			printf("error\n");
			break;
	}
	for(int i = 100; i > 10; i/=2)
	{
		if (i / 5 == 10)
			continue;
		printf("%d\n", i);
	}
	bool isit = true;
	do
	{
		printf("ok, ");
	}
	while (!isit);
	while (isit)
	{
		printf("try to guess\n");
		scanf("%d", &x);
		if(x == 1)
		{
			isit = false;
			printf("Match!\n");
		}	
	}
	struct	car 
	{
		int	speed;
		char	name[50];
		float	weight;
	};
	struct car bmw;
	bmw.speed = 250;
	strcpy(bmw.name, "BMW X5");
	bmw.weight = 2500.00f;
	struct car audi = {300, "AUDI TT", 2800.00f};
	printf("%s, its speed is %d, its weight is %f\n", audi.name, audi.speed, audi.weight);
	printf("%s, it speed is %d, its weight is %f\n", bmw.name, bmw.speed, bmw.weight);
	struct abstract square = {5, 7};
	calc(&square);
	int num = 10;
	int	*pnum = &num;
	printf("Value: %d (int itself) - %d (via pointer)\n", num, *pnum);
	printf("Address: %p (& to int) - %p (pointer itself)\n", &num, pnum);

	char line[255] = "12345gnsjgskjhgkjsh";
	FILE *test = fopen("test.txt", "r");
	fprintf(test, "Hello!");
	fgets(line, 50, test);
	printf("%s", line);	
	fclose(test);
}

