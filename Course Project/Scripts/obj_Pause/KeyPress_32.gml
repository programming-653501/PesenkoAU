if (Pause){
	instance_activate_all()
	Pause = false
}
else {
	instance_deactivate_all(true)
	Pause = true
}