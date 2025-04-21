#include <FmodMain.h>

#include <Windows.h>
#include <Objbase.h>
#include <conio.h>
#include <Combaseapi.h>



void FmodMain::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setSoftwareFormat"), &FmodMain::setSoftwareFormat);
	ClassDB::bind_method(D_METHOD("startFmod"), &FmodMain::startFmod);
	ClassDB::bind_method(D_METHOD("testFmod"), &FmodMain::testFmod);
	ClassDB::bind_method(D_METHOD("releaseFmod"), &FmodMain::releaseFmod);
	ClassDB::bind_method(D_METHOD("loadMasterBank"), &FmodMain::loadMasterBank);
	ClassDB::bind_method(D_METHOD("loadTestEventsBank"), &FmodMain::loadTestEventsBank);
	ClassDB::bind_method(D_METHOD("loadStringsBank"), &FmodMain::loadStringsBank);
	ClassDB::bind_method(D_METHOD("getEventDescription"), &FmodMain::getEventDescription);
	ClassDB::bind_method(D_METHOD("createEventInstance"), &FmodMain::createEventInstance);
	ClassDB::bind_method(D_METHOD("playEventInstance"), &FmodMain::playEventInstance);
	ClassDB::bind_method(D_METHOD("releaseEventInstance"), &FmodMain::releaseEventInstance);
	ClassDB::bind_method(D_METHOD("unloadBanks"), &FmodMain::unloadBanks);
	ClassDB::bind_method(D_METHOD("stopEventInstance"), &FmodMain::stopEventInstance);
	ClassDB::bind_method(D_METHOD("update"), &FmodMain::update);
}

FmodMain::FmodMain() {
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	FMOD::Studio::System::create(&pSystem);
	pSystem->getCoreSystem(&pCoreSystem);
}
	
int FmodMain::setSoftwareFormat() {
	return pCoreSystem->setSoftwareFormat(48000, FMOD_SPEAKERMODE_STEREO, 2);
}

int FmodMain::startFmod() {
	return pSystem->initialize(128, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);
}

bool FmodMain::testFmod() {
	return pSystem->isValid();
}

int FmodMain::loadMasterBank() {
	return pSystem->loadBankFile(R"(F:\Godot Projects\godot-cpp-template\demo\Audio_Banks\Desktop\Master.bank)", FMOD_STUDIO_LOAD_BANK_NORMAL, &pMasterBank);
}

int FmodMain::loadTestEventsBank() {
	return pSystem->loadBankFile(R"(F:\Godot Projects\godot-cpp-template\demo\Audio_Banks\Desktop\TestEvents.bank)", FMOD_STUDIO_LOAD_BANK_NORMAL, &pTestEventsBank);
}

int FmodMain::loadStringsBank() {
	return pSystem->loadBankFile(R"(F:\Godot Projects\godot-cpp-template\demo\Audio_Banks\Desktop\Master.strings.bank)", FMOD_STUDIO_LOAD_BANK_NORMAL, &pStringsBank);
}

int FmodMain::getEventDescription() {
	return pSystem->getEvent("event:/TestEvent", &pEventDescription);
}

int FmodMain::createEventInstance() {
	return pEventDescription->createInstance(&pEventInstance);
}

int FmodMain::playEventInstance() {
	return pEventInstance->start();
}

int FmodMain::stopEventInstance() {
	return pEventInstance->stop(FMOD_STUDIO_STOP_IMMEDIATE);
}

int FmodMain::releaseEventInstance() {
	return pEventInstance->release();
}

int FmodMain::unloadBanks() {
	return pSystem->unloadAll();
}

int FmodMain::releaseFmod() {
	CoUninitialize();
	return pSystem->release();
}

void FmodMain::update() {
	pSystem->update();
}
