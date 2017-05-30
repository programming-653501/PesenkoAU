if (!global.restart){

	//Movement

	#macro left_border  100
	#macro right_border (room_width - 100)
	#macro up_border    125
	#macro down_border  (room_height - 90)
	#macro Chelik_speed 5
	#macro Chelik_diagonal_speed 3.5355339059327376220042218105242

	var isRunning = false

	var right_move = keyboard_check(vk_right) || keyboard_check(ord("D")),
		left_move  = keyboard_check(vk_left)  || keyboard_check(ord("A")),
		up_move    = keyboard_check(vk_up)    || keyboard_check(ord("W")),
		down_move  = keyboard_check(vk_down)  || keyboard_check(ord("S"))
	var button_pressed = right_move + left_move + up_move + down_move

	if (button_pressed == 2){
		x += Chelik_diagonal_speed * (((x < right_border) * right_move) - ((x > left_border) * left_move))
		y += Chelik_diagonal_speed * (((y < down_border) * down_move) - ((y > up_border) * up_move))	
	}
	else if (button_pressed > 0){
		x += Chelik_speed * (((x < right_border) * right_move) - ((x > left_border) * left_move))
		y += Chelik_speed * (((y < down_border) * down_move) - ((y > up_border) * up_move))
	}
	
	if (x != xprevious || y != yprevious)
		isRunning = true

	//Spite and Chainsaw behavior

	#macro Chainsaw_dx 25
	#macro Chainsaw_dy 25
	var dir = point_direction(x, y, mouse_x, mouse_y)

	var dx = Chainsaw_dx * dcos(dir)
	var dy = Chainsaw_dy * dsin(dir)

	if (dir >= 90 && dir <= 270){
		sprite_index = isRunning ? spr_Chelik_running_left : spr_Chelik_standing_left
	
		if (obj_Chainsaw.IsAttack && mouse_check_button(mb_left)){
			obj_Chainsaw.sprite_index = global.spr_Chainsaw[irandom(5) + 1]
			obj_Chainsaw.image_xscale = -1
		}
		else {
			obj_Chainsaw.sprite_index = spr_Chainsaw_left
			obj_Chainsaw.image_xscale = 1
		}
	
		obj_Chainsaw.x = x - Chainsaw_dx
	}
	else if (dir > 270 || dir < 90){
		sprite_index = isRunning ? spr_Chelik_running_right : spr_Chelik_standing_right	
	
		if (obj_Chainsaw.IsAttack && mouse_check_button(mb_left)){
			obj_Chainsaw.sprite_index = global.spr_Chainsaw[irandom(5) + 1]
			obj_Chainsaw.image_xscale = 1
		}
		else {
			obj_Chainsaw.sprite_index = spr_Chainsaw_right
			obj_Chainsaw.image_xscale = 1
		}
	
		obj_Chainsaw.x = x + Chainsaw_dx
	}
	obj_Chainsaw.y = y + Chainsaw_dy

	//Chainsaw rotation//
	#macro Chainsaw_vector 35.355339059327376220042218105242

	if (dir < 360 && dir > 315)
		obj_Chainsaw.image_angle = dir
	else if (dir >= 270 && dir <= 315)
		obj_Chainsaw.image_angle = 315
	else if (dir < 270 && dir >= 225)
		obj_Chainsaw.image_angle = 45
	else if (dir > 180 && dir < 225)
		obj_Chainsaw.image_angle = dir - 180
	else if (dir > 45 && dir <= 90){
		obj_Chainsaw.image_angle = 45
		obj_Chainsaw.x += dsin(45) * Chainsaw_vector
		obj_Chainsaw.y -= dsin(45) * Chainsaw_vector
	}
	else if (dir > 90 && dir <= 135){
		obj_Chainsaw.image_angle = -45
		obj_Chainsaw.x -= dsin(45) * Chainsaw_vector
		obj_Chainsaw.y -= dsin(45) * Chainsaw_vector
	}
	else if (dir >= 0 && dir <= 45){
		obj_Chainsaw.image_angle = dir;
		obj_Chainsaw.x += dsin(dir) * Chainsaw_vector
		obj_Chainsaw.y -= dsin(dir) * Chainsaw_vector
	}
	else if (dir <= 180 && dir >= 135){
		obj_Chainsaw.image_angle = dir - 180
		obj_Chainsaw.x += dsin(dir - 180) * Chainsaw_vector
		obj_Chainsaw.y -= dsin(dir) * Chainsaw_vector
	}

	#macro Chainsaw_shaking 3
	if (mouse_check_button(mb_left)){
		obj_Chainsaw.x += irandom_range(-Chainsaw_shaking, Chainsaw_shaking)
		obj_Chainsaw.y += irandom_range(-Chainsaw_shaking, Chainsaw_shaking)
	}
	/////////////////////

	//Shaking

	#macro shaking 1

	if (shaking_up){
		shaking_timer += 0.5
		if (shaking_timer == 30)
			shaking_up = false
	}
	else {
		shaking_timer -= 0.5
		if (shaking_timer == 0)
			shaking_up = true
	}

	if (shaking_timer % 2 == 0)
		y += shaking_up ? -shaking : shaking
	
	//Kick

	if (refresh > 0)
		refresh -= 0.05
	else if (refresh == 0)
		speed = 0
	
	if (x <= left_border || x >= right_border || y <= up_border || y >= down_border)
		speed = 0
	
}
else{
	image_index = 0
	speed = 0
}