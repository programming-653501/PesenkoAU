var score_x = camera_get_view_x(view_camera[0]) + 1330,
	score_y = camera_get_view_y(view_camera[0]) + 50

draw_sprite_ext(spr_Pig_blinking, 0, score_x, score_y, 0.4, 0.4, 0, -1, 1)

draw_set_font(fnt_main)
draw_set_color(c_black)
draw_text(score_x + 45, score_y - 45, "X " + string(global.dead_Pigs_count))


if (obj_Chelik.Chelik_hp == 0){
		global.restart = true
		
}

if (global.restart){
	draw_set_font(fnt_main)
	draw_set_color($8D2CA7)
	
	if (restart_timer > 0)
		restart_timer -= delta_time / 1000000
	else
		room_restart()
		
	if (restart_timer < 2)
		draw_text(camera_get_view_x(view_camera[0]) + 200, 
				  camera_get_view_y(view_camera[0]) + camera_get_view_height(view_camera[0]) / 2 - 75,
					":(")
}

for (i = 0; i < obj_Chelik.Chelik_hp; i++){
	draw_sprite_ext(spr_Health, 0, score_x - 1300 + i * 75, score_y - 30, 0.35, 0.35, 0, -1, 1)	
}