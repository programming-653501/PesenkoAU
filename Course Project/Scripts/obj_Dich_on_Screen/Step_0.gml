if (random_spawn_timer > 0){
	random_spawn_timer -= delta_time / 1000000
}
else {
	random_spawn_timer = 1
	var new_x, new_y
	
	switch(irandom(2)){
	case 0:
		new_x = -70
		break
	case 1:
		new_x = irandom_range(0, room_width)
		break
	case 2:
		new_x = room_width + 70
		break
	}
	switch(new_x){
	case -70:
		new_y = irandom_range(0, room_height)
		break
	case 1606:
		new_y = irandom_range(0, room_height)
		break
	default:
		new_y = irandom(1) ? -70 : room_height + 70
		break
	}
	
	switch(irandom(4)){
	case 3:
		instance_create_layer(new_x, new_y, "Dich", obj_Dich_Chelik)
		break;
	default:
		instance_create_layer(new_x, new_y, "Dich", obj_Dich_Pig)
		break;
	}
}