var dir = point_direction(x, y, other.x, other.y)

#macro dont_touch_another_Pigs 3
if (sprite_index != spr_Pig_blinking){
	x -= dont_touch_another_Pigs * dcos(dir)
	y -= dont_touch_another_Pigs * dsin(dir)
}