#include "fractol.h"


void            initialize_opencl(t_opencl *cl)
{
    getPlatrofrmsId(cl);
	getDeviceId(cl);
	createContex(cl);
	createCommandQueue(cl);

    build_cl(cl);
}


void			getPlatrofrmsId(t_opencl *cl)
{
    cl->ret = clGetPlatformIDs(1, &cl->platform_id, &cl->ret_num_platforms);

    if (cl->ret != CL_SUCCESS)
    {
        ft_printf(RED"ERROR GET PLATFORM\n"RESET);
        exit(1);
    }
}

void				getDeviceId(t_opencl *cl)
{
    cl->ret = clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &cl->device_id, &cl->num_devices);

    if (cl->ret != CL_SUCCESS)
    {
        ft_printf(RED"ERROR GET DEVICE\n"RESET);
        exit(1);
    }
}

void    			createContex(t_opencl *cl)
{
    cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &cl->ret);

    if (cl->ret != CL_SUCCESS)
    {
        ft_printf(RED"ERROR CREATE CONTEX\n"RESET);
        exit(1);
    }
}

void				createCommandQueue(t_opencl *cl)
{
    cl->command_queue = clCreateCommandQueue(cl->context, cl->device_id, 0, &cl->ret);
    
    if (cl->ret != CL_SUCCESS)
    {
        ft_printf(RED"ERROR CREATE COMMAND QUEUE\n"RESET);
        exit(1);
    }
}