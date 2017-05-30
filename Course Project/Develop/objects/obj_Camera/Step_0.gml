var dis = point_distance(x, y, obj_Chelik.x, obj_Chelik.y),
	angle = point_direction(x, y, obj_Chelik.x, obj_Chelik.y)

var catch = abs(x - obj_Chelik.x) < 15 && abs(y - obj_Chelik.y) < 15,
	reached_border_x = x < half_width_cam || x > room_width - half_width_cam,
	reached_border_y = y < half_height_cam || y > room_height - half_height_cam

if (catch || reached_border_x || reached_border_y)
	start_follow = false

#macro camera_const (half_height_cam * (3/4) / Chelik_speed)
if (start_follow){
	x += (dis / camera_const) * dcos(angle)
	y -= (dis / camera_const) * dsin(angle)

	x = clamp(x, half_width_cam, room_width - half_width_cam)
	y = clamp(y, half_height_cam, room_height - half_height_cam)
	camera_set_view_pos(view_camera[0], x - half_width_cam, y - half_height_cam)
}
else if (dis >= half_height_cam * 3/4)
	start_follow = true