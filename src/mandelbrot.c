#include "fractol.h"

#define MAX_ITER 30

void	mandelbrot(int x, int y, t_union *un)
{
	/*un = (void *)un;
	x = (int)x;
	y = (int)y;
	double cr = x + -2.05;
	double ci = y + -1.3;
	double zr = 0;
	double zi = 0;


	int i = 0;
	while (i < MAX_ITER && zr * zr + zi * zi < 4)
	{
		double tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;

		++i;
	}
	if (i == MAX_ITER)
		ft_putpixel(un->img, x, y, 0x000000);
	else
		ft_putpixel(un->img, x, y, 0xCC0000);
*/

            // c_real 
            double cx = x * 1 + -1.6; 
  
            // c_imaginary 
            double cy = y * 1 + -1.3; 
  
            // z_real 
            double zx = 0; 
  
            // z_imaginary 
            double zy = 0; 
            int count = 0; 
  
            // Calculate whether c(c_real + c_imaginary) belongs 
            // to the Mandelbrot set or not and draw a pixel 
            // at coordinates (x, y) accordingly 
            // If you reach the Maximum number of iterations 
            // and If the distance from the origin is 
            // greater than 2 exit the loop 
            while ((zx * zx + zy * zy < 4) && (count < MAX_ITER)) 
            { 
                // Calculate Mandelbrot function 
                // z = z*z + c where z is a complex number 
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real 
                double tempx = zx * zx - zy * zy + cx; 
  
                // 2*z_real*z_imaginary + c_imaginary 
                zy = 2 * zx * zy + cy; 
  
                // Updating z_real = tempx 
                zx = tempx; 
  
                // Increment count 
                count = count + 1; 
            } 
  				ft_printf("COUNT: %i\n", count);
            // To display the created fractal 
            if (count == MAX_ITER)
		ft_putpixel(un->img, x, y, 0x000000);
		//	else
		//ft_putpixel(un->img, x, y, 0xCC0000);
        } 
