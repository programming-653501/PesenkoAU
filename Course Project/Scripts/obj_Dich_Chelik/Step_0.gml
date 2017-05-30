if (!irandom(15))
	image_xscale *= -1

if (abs(x - target_x) < 3 && abs(y - target_y) < 3)
	instance_destroy()