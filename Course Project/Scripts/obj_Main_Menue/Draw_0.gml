draw_set_color(c_black)
draw_set_alpha(0.1)
draw_rectangle(camera_get_view_x(view_camera[0]), camera_get_view_y(view_camera[0]),
				   camera_get_view_x(view_camera[0]) + camera_get_view_width(view_camera[0]),
				   camera_get_view_y(view_camera[0]) + camera_get_view_height(view_camera[0]),
				   false)

if (LOGO_timer > 0){
	LOGO_timer -= delta_time / 1000000
	draw_set_alpha(1 - LOGO_timer)
}
else {
	draw_set_alpha(1)
}

draw_sprite(spr_LOGO, 0 , (room_width - sprite_get_width(spr_LOGO)) / 2, room_height / 4)

draw_set_font(fnt_menue)
draw_set_color(c_purple /*$8D2CA7*/)

if (welcome_timer > 1){
	welcome_timer -= delta_time / 1000000
	draw_set_alpha(0)
}
else if (welcome_timer > 0){
	welcome_timer -= delta_time / 1000000
	draw_set_alpha(1 - welcome_timer)
}
else{
	draw_set_alpha(1)
}

draw_text(room_width / 2 - 218, room_height * 3/4 - 20,
		  "Нажмите Enter чтобы начать игру")

draw_set_alpha(1)