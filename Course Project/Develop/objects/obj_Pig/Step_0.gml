if (!global.restart){

	direction = point_direction(x, y, obj_Chelik.x, obj_Chelik.y)
	if (direction > 90 && direction < 270)
		image_xscale = -1
	else
		image_xscale = 1
	
	if (IsAttacked && !mouse_check_button(mb_left)){
		IsAttacked = false
		if (irandom(3) == 3){
			speed = 0
			sprite_index = spr_Pig_blinking
			refresh = 2
		}
	}
	if (refresh > 0)
		refresh -= 0.05
	else if (refresh == 0){
		sprite_index = spr_Pig_running
		speed = 3.5
		refresh--
	}

	if (Pig_hp < 0){
		instance_create_layer(x, y, "Dead_Pigs", obj_Pig_dead)
		instance_destroy()
	}

}
else {
	sprite_index = spr_Pig_blinking
	image_index = 0
	speed = 0
}