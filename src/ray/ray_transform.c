#include "rtv1.h"

#include <stdio.h>////////////
t_ray	ray_transform(t_ray const ray, t_pipe const pipe)
{
	t_ray	transformed;

/*	printf("non-transformed ray.pos.x: %f, ray.pos.t: %f, ray.pos.z: %f, ray.pos.w: %f\n", ray.pos.x, ray.pos.y, ray.pos.z, ray.pos.w);
	printf("\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n",
			pipe.inverse.m[0][0], pipe.inverse.m[0][1], pipe.inverse.m[0][2], pipe.inverse.m[0][3],
			pipe.inverse.m[1][0], pipe.inverse.m[1][1], pipe.inverse.m[1][2], pipe.inverse.m[1][3],
			pipe.inverse.m[2][0], pipe.inverse.m[2][1], pipe.inverse.m[2][2], pipe.inverse.m[2][3],
			pipe.inverse.m[3][0], pipe.inverse.m[3][1], pipe.inverse.m[3][2], pipe.inverse.m[3][3]);
*/	transformed.pos = mtx_product(pipe.i_pos, ray.pos);
//:w
//printf("transformed transformed.pos.x: %f, transformed.pos.t: %f, transformed.pos.z: %f, transformed.pos.w: %f\n", transformed.pos.x, transformed.pos.y, transformed.pos.z, transformed.pos.w);
	transformed.dir = mtx_product(pipe.i_dir, ray.dir);
	return (transformed);
}
