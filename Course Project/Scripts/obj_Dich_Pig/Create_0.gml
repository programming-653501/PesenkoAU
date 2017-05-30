switch (x){
case -70:
	if (irandom(2)){
		target_x = room_width + 70
		target_y = irandom_range(0, room_height)
	}
	else {
		target_x = irandom_range(room_width / 4, room_width)
		target_y = irandom(1) ? -70 : room_height + 70
	}
	break
case 1606:
	if (irandom(2)){
		target_x = -70
		target_y = irandom_range(0, room_height)
	}
	else {
		target_x = irandom_range(0, room_width * 3/4)
		target_y = room_height + 70
	}
	break
default:
	if (irandom(2)){
		target_x = irandom_range(0, room_width)
		target_y = (y == -70) ? room_height + 70 : -70
	}
	else {
		target_x = (irandom(1) ? 0 : 1606 + 140) -  70
		target_y = (y == -70) ? irandom_range(room_width/4, room_width) : irandom_range(0, room_width * 3/4)
	}
	break
}

if (x > target_x)
	image_xscale = -1

move_towards_point(target_x, target_y, 10)