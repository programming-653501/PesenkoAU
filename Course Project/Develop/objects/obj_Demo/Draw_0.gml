draw_set_color(c_black)
draw_set_alpha(0.1)
draw_rectangle(camera_get_view_x(view_camera[0]), camera_get_view_y(view_camera[0]),
				   camera_get_view_x(view_camera[0]) + camera_get_view_width(view_camera[0]),
				   camera_get_view_y(view_camera[0]) + camera_get_view_height(view_camera[0]),
				   false)

draw_set_alpha(1)
draw_set_font(fnt_main)

if (Demo_text){
	draw_set_color(c_purple)
	draw_text(220, 330, "Спасибо что сыграли в демо-версию!\n"
			  +	"       Ждите официальный релиз :)")
}
else {
	if (Demo_text_timer > 0){
		Demo_text_timer -= delta_time / 1000000
		draw_set_alpha(1 - Demo_text_timer)
	}
	else {
		draw_set_alpha(1)
	}

	draw_set_color(c_black)
	draw_text(620, 250, "AUTHORS\n")
	draw_text(386, 330, "Programming:")
	draw_set_color(c_purple)
	draw_text(800, 330, "Queen Aleks\n")
	draw_set_color(c_black)
	draw_text(500, 400, "Graphics:")
	draw_set_color(c_purple)
	draw_text(800, 400, "Robber")
	
	if (Demo_text_timer + 0.5 < 0){
		draw_set_alpha(1)
		draw_set_font(fnt_menue)
		draw_set_color(c_black)
		draw_text(655, 700, "Enter - новая игра\n")
		draw_text(695, 730, "Esc - выход")
	}
	else if (Demo_text_timer <= 0){
		Demo_text_timer -= delta_time / 1000000
	}
}