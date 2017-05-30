if (Pigs_count > 0 && respawn_timer < 0){
	respawn_timer = respawn_time
	Pigs_count--
	var xcreate, ycreate,
		xcam = camera_get_view_x(view_camera[0]), ycam = camera_get_view_y(view_camera[0])
		
	xcreate = irandom(room_width)
	ycreate = irandom(room_height)
	
	while (xcreate > xcam - 70 && xcreate < xcam + cwidth + 70)
		xcreate = irandom(room_width)
	while (ycreate > ycam - 60 && ycreate < ycam + cheight + 85)
		ycreate = irandom(room_height)
	
	instance_create_layer(xcreate, ycreate, "Instances", obj_Pig)
}
else
	respawn_timer -= 0.05