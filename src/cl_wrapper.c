#include "fractol.h"


void            initialize_opencl(t_opencl *cl)
{
    getPlatrofrmsId(cl);
	getDeviceId(cl);
	createContex(cl);
	createCommandQueue(cl);

    build_cl(cl);

    if (cl->ret != CL_SUCCESS)
    {
        ft_printf(RED"ERROR WITH OPENCL HAPPEND"RESET);
        exit(1);
    }

    cl_mem memobj = NULL;
    int memLenth = 1000;
    cl_int* mem = (cl_int *)malloc(sizeof(cl_int) * memLenth);
   
    for (int i = 0; i < memLenth; ++i)
    {
        mem[i] = 0;
    }
     for (int i = 0; i < memLenth; ++i)
    {
        ft_printf("%i ", mem[i]);
    }
    ft_printf("\n");
    memobj = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, memLenth * sizeof(cl_int), NULL, &cl->ret);
    cl->ret |= clEnqueueWriteBuffer(cl->command_queue, memobj, CL_TRUE, 0, memLenth * sizeof(cl_int), mem, 0, NULL, NULL);
    cl->ret |= clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), (void *)&memobj);
    size_t global_work_size[1] = { 1000 };
    cl->ret |= clEnqueueNDRangeKernel(cl->command_queue, cl->kernel, 1, NULL, global_work_size, NULL, 0, NULL, NULL);

    cl->ret |= clEnqueueReadBuffer(cl->command_queue, memobj, CL_TRUE, 0, memLenth * sizeof(cl_int), mem, 0, NULL, NULL);

    if (cl->ret != CL_SUCCESS)
    {
        ft_printf(RED"ERROR WITH OPENCL HAPPEND"RESET);
        exit(1);
    }
    for (int i = 0; i < memLenth; ++i)
    {
        ft_printf("%i ", mem[i]);
    }
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