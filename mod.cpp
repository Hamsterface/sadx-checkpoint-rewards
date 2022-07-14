#include "pch.h"

FunctionPointer(void, GetSpeedUpP, (char pnum), 0x441DF0); // Function to give speed shoes
DataPointer(int, RandomRingDisplay, 0x3C5AB30); // How many rings to show for random boxes

static void __cdecl CheckRewards(NJS_VECTOR* Position, Rotation3* Rotation) {
	if (Rings >= 90) {
		if (((CharObj2*)playerpwp[0])->Powerups & (Powerups_Barrier | Powerups_MagneticBarrier)) {
			GetThunderBarrierP(0);

			DoThingWithItemBoxPowerupIndex(8);
		}
		else {
			GetBarrierP(0);

			DoThingWithItemBoxPowerupIndex(5);
		}
	}
	else if (Rings >= 80) {
		GetSpeedUpP(0);

		DoThingWithItemBoxPowerupIndex(0);
	}
	else if (Rings >= 60) {
		Rings += 20;

		RandomRingDisplay = 20;
		DoThingWithItemBoxPowerupIndex(4);
	}
	else if (Rings >= 40) {
		Rings += 10;

		DoThingWithItemBoxPowerupIndex(3);
	}
	else if (Rings >= 20) {
		Rings += 5;

		DoThingWithItemBoxPowerupIndex(2);
	}

	SetRestartData(Position, Rotation); // Call the function we replaced
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		WriteCall((void *)0x44f511, CheckRewards); // Override the SetRestartData call upon hitting a checkpoint
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}