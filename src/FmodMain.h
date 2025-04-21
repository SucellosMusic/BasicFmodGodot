#pragma once

#include <fmod.h>
#include <fmod.hpp>
#include <fmod_codec.h>
#include <fmod_common.h>
#include <fmod_errors.h>
#include <fmod_output.h>
#include <fmod_studio.hpp>
#include <fmod_studio.h>
#include <fmod_studio_common.h>

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class FmodMain : public Object {
	GDCLASS(FmodMain, Object);

	protected:
		static void _bind_methods();

	private:
		FmodMain::FmodMain();
		
	public:
		FMOD::Studio::System *pSystem = nullptr;
		FMOD::Studio::Bank *pMasterBank = nullptr;
		FMOD::Studio::Bank *pStringsBank = nullptr;
		FMOD::Studio::Bank *pTestEventsBank = nullptr;
		FMOD::Studio::EventDescription *pEventDescription = nullptr;
		FMOD::Studio::EventInstance *pEventInstance = nullptr;

		FMOD::System *pCoreSystem = nullptr;

		//studio functions
		bool testFmod();
		int startFmod();
		int loadMasterBank();
		int loadTestEventsBank();
		int loadStringsBank();
		int getEventDescription();
		int createEventInstance();
		int playEventInstance();
		int stopEventInstance();
		int releaseEventInstance();
		int unloadBanks();
		int releaseFmod();
		void update();

		//Core functions
		int setSoftwareFormat();
};
