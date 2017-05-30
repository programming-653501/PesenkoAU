if (Pause){
	draw_set_color(c_black)
	draw_set_alpha(0.15)
	draw_rectangle(camera_get_view_x(view_camera[0]), camera_get_view_y(view_camera[0]),
				   camera_get_view_x(view_camera[0]) + camera_get_view_width(view_camera[0]),
				   camera_get_view_y(view_camera[0]) + camera_get_view_height(view_camera[0]),
				   false)
	
	draw_set_alpha(1)
	draw_set_font(fnt_main)
	draw_text(camera_get_view_x(view_camera[0]) + 200, 
			  camera_get_view_y(view_camera[0]) + camera_get_view_height(view_camera[0]) / 2 - 75,
				"Пауза")
				
	draw_set_font(fnt_menue)
	draw_text(camera_get_view_x(view_camera[0]) + camera_get_view_width(view_camera[0]) / 2 - 45, 
			  camera_get_view_y(view_camera[0]) + camera_get_view_height(view_camera[0]) / 2 - 60,
				"Space - продолжить\nEsc - в главное меню")
}