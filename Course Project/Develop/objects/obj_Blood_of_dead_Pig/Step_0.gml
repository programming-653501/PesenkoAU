if (timer > 0){
	image_xscale = 1 - timer
	image_yscale = 1 - timer
	timer -= 0.005
}
else {
	image_xscale = 1
	image_yscale = 1
}