#include <stdio.h>

int		to_rgb(int h, int s, int b)
{
	int		rgb;
	float	min;
	float	tmp;

	min = b - (s * b / 255);
	tmp = b - min;
	if (h < 60)
		rgb = (b << 16) + ((int)(h * tmp / 60 + min) << 8) + (int)min;
	else if (h < 120)
		rgb = ((int)((120 - h) * tmp / 60 + min) << 16) + (b << 8) + (int)min;
	else if (h < 180)
		rgb = ((int)min << 16) + (b << 8) + (int)((h - 120) * tmp / 60 + min);
	else if (h < 240)
		rgb = ((int)min << 16) + ((int)((240 - h) * tmp / 60 + min) << 8) + b;
	else if (h < 300)
		rgb = ((int)((h - 240) * tmp / 60 + min) << 16) + ((int)min << 8) + b;
	else
		rgb = (b << 16) + ((int)min << 8) + (int)((360 - h) * tmp / 60 + min);
	return (rgb);
}

int main(void)
{
	int	rgb;
	int	i;

	i = 0;
	while (i < 360)
	{
		rgb = to_rgb(i, 100, 100);
		printf("%d(%x), ", rgb, rgb);
		if (i % 6 == 5)
			printf("\n");
		i++;
	}
	return (0);
}
