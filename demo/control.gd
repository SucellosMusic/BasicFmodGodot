extends Control

@onready var Fmod = FmodMain.new()

func _process(_delta: float) -> void:
	Fmod.update()

func _on_set_software_format_pressed() -> void:
	print(Fmod.setSoftwareFormat())

func _on_start_fmod_pressed() -> void:
	print(Fmod.startFmod())

func _on_test_fmod_pressed() -> void:
	print(Fmod.testFmod())

func _on_load_master_bank_pressed() -> void:
	print(Fmod.loadMasterBank())

func _on_load_test_events_bank_pressed() -> void:
	print(Fmod.loadTestEventsBank())

func _on_load_strings_bank_pressed() -> void:
	print(Fmod.loadStringsBank())

func _on_get_event_description_pressed() -> void:
	print(Fmod.getEventDescription())

func _on_create_event_instance_pressed() -> void:
	print(Fmod.createEventInstance())

func _on_play_event_pressed() -> void:
	print(Fmod.playEventInstance())

func _on_stop_event_pressed() -> void:
	print(Fmod.stopEventInstance())

func _on_release_event_pressed() -> void:
	print(Fmod.releaseEventInstance())

func _on_unload_banks_pressed() -> void:
	print(Fmod.unloadBanks())

func _on_release_fmod_pressed() -> void:
	print(Fmod.releaseFmod())
