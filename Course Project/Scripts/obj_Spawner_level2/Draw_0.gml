draw_set_font(fnt_main)

switch(hello_caption){
case 3:
	if (hello_timer > 0){
		hello_timer -= delta_time / 1000000
		draw_set_alpha(1 - hello_timer)
	}
	else {
		hello_caption--
		hello_timer = 1
	}
	draw_set_color($8D2CA7)
	draw_text(camera_get_view_x(view_camera[0]) + 200, 
			  camera_get_view_y(view_camera[0]) + cheight / 2 - 75,
				"Уровень 2")
	break;
case 2:
	if (hello_timer > 0){
		hello_timer -= delta_time / 3000000
	}
	else {
		hello_caption--
		hello_timer = 1
	}
	draw_set_color($8D2CA7)
	draw_text(camera_get_view_x(view_camera[0]) + 200, 
			  camera_get_view_y(view_camera[0]) + cheight / 2 - 75,
				"Уровень 2")
	break;
case 1:
	if (hello_timer > 0){
		hello_timer -= delta_time / 1000000
		draw_set_color($8D2CA7)
		draw_set_alpha(hello_timer)
		draw_text(camera_get_view_x(view_camera[0]) + 200, 
				  camera_get_view_y(view_camera[0]) + cheight / 2 - 75,
					"Уровень 2")
	}
	else {
		hello_caption--
		hello_timer = 1
	}
	break;	
}

if (default_Pigs_count - global.dead_Pigs_count == 0){

	if (font_timer > 0){
		draw_set_alpha(1 - font_timer)
		font_timer -= delta_time / 1000000
	}
	else 
		draw_set_alpha(1)

	draw_set_color($8D2CA7)
	draw_text(camera_get_view_x(view_camera[0]) + 200, 
			  camera_get_view_y(view_camera[0]) + cheight / 2 - 75,
				"Уровень 2 пройден")
				
	if (next_level_timer > 0){
		next_level_timer -= delta_time / 1000000
	}
	else
		room_goto_next()
}

draw_set_alpha(1)