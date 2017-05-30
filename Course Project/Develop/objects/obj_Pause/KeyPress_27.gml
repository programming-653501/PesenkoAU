if (Pause){
	room_goto(rm_Main_Menue)
}
else {
	instance_deactivate_all(true)
	Pause = true
}