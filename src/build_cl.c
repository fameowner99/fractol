#include "fractol.h"

void    build_cl(t_opencl *cl)
{
    const char file_name[] = "src/cl/draw.cl";
    int fd;
    char *line;
    char *source;

    cl->program = NULL;
    cl->kernel = NULL;
    source = NULL;
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("ERROR OPENING .cl FILE\n");
        exit(1);
    }
    while (get_next_line(fd, &line) > 0)
    {
        source = ft_append(source, line);
        free(line);
    }
    close(fd);
    size_t source_size = ft_strlen(source);
   	
    cl->program = clCreateProgramWithSource(cl->context, 1, (const char **)&source, 
        (const size_t *)&source_size, &cl->ret);
    fd = clBuildProgram(cl->program, 1, &cl->device_id, NULL, NULL, NULL);
    cl->kernel = clCreateKernel(cl->program, "test", &cl->ret);
}