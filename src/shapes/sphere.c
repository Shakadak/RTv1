t_shape	new_sphere(t_coordinate const pos, double const radius, t_color const color)
{
	t_shape	sphere;

	sphere.kind = SPHERE;
	sphere.shape.sphere.radius = radius;
	sphere.coordinate = pos;
	sphere.color = color;
	return (sphere);
}
