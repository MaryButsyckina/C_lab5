#include "SmartPhone.h"
#include "Exceptions.h"
using device::SmartPhone;
using namespace smartphone_exceptions;

namespace device
{
	int SmartPhone::SetBrand(string brand)
	{
		if (brand == "") return 1;
		brand_ = brand;
		return 0;
	}
	int SmartPhone::SetModel(string model)
	{
		if (model == "") return 1;
		model_ = model;
		return 0;
	}
	int SmartPhone::SetClockRate(float cr)
	{
		if (cr <= 0) return 1;
		clock_rate_ = cr;
		return 0;
	}
	int SmartPhone::SetCores(short cores)
	{
		if (cores <= 0) return 1;
		cores_ = cores;
		return 0;
	}
	int SmartPhone::SetRAM(float ram)
	{
		if (ram <= 0) return 1;
		RAM_ = ram;
		return 0;
	}
	int SmartPhone::SetRAMtype(RAM ram_type)
	{
		if (ram_type > 1) return 1;
		RAM_type_ = ram_type;
		return 0;
	}
	int SmartPhone::SetROM(float rom)
	{
		if (rom <= 0) return 1;
		ROM_ = rom;
		return 0;
	}
	int SmartPhone::SetOSver(string os_ver)
	{
		if (os_ver == "") return 1;
		OS_ver_ = os_ver;
		return 0;
	}
	int SmartPhone::SetUsedROM(float rom)
	{
		if (rom < 0) return 1;
		used_ROM_ = rom;
		return 0;
	}
	int SmartPhone::SetIMEI(string imei)
	{
		if (imei == "") return 1;
		if (imei.length() != 15) return 1;
		IMEI_.TAC = stoi(imei.substr(0, IMEI_.lenTAC));
		IMEI_.SNR = stoi(imei.substr(IMEI_.lenTAC, IMEI_.lenSNR));
		IMEI_.FAC = stoi(imei.substr(IMEI_.lenSNR + IMEI_.lenTAC, IMEI_.lenFAC));
		IMEI_.SP = stoi(imei.substr(IMEI_.lenSNR + IMEI_.lenTAC + IMEI_.lenFAC, IMEI_.lenSP));
		return 0;
	}

	int SmartPhone::SetOS(OS os, string version)
	{
		if (SetOSver(version)) throw WRONG_OS_VERSION;
		if (os > 3) return 1;
		OS_ = os;
		return 0;
	}
	int SmartPhone::SetApps(int apps, float used_rom)
	{
		if ((apps == 0 && used_rom != 0) || (apps != 0 && used_rom == 0)) throw WRONG_APPS_AND_ROM;
		if (SetUsedROM(used_rom)) throw WRONG_USED_ROM;
		if (apps < 0) return 1;
		apps_ = apps;
		return 0;
	}

	SmartPhone::SmartPhone(string brand, string model,
		float cr, short cores,
		float ram, RAM ram_type,
		float rom, string imei,
		OS OS, string OS_ver,
		int apps, int used_rom)
	{
		if (SetBrand(brand)) throw WRONG_BRAND;
		if (SetModel(model)) throw WRONG_MODEL;
		if (SetClockRate(cr)) throw WRONG_CLOCK_RATE;
		if (SetCores(cores)) throw WRONG_CORES;
		if (SetRAM(ram)) throw WRONG_RAM;
		if (SetRAMtype(ram_type)) throw WRONG_RAM_TYPE;
		if (SetROM(rom)) throw WRONG_ROM;
		if (SetIMEI(imei)) throw WRONG_IMEI;
		try
		{
			if (SetOS(OS, OS_ver)) throw WRONG_OS;
			if (SetApps(apps, used_rom)) throw WRONG_APPS;
		}
		catch (string ex)
		{
			throw ex;
		}
	}
	SmartPhone::SmartPhone(string brand, string model,
		float cr, short cores,
		float ram, RAM ram_type,
		float rom, string imei,
		int apps, float used_rom)
	{
		if (SetBrand(brand)) throw WRONG_BRAND;
		if (SetModel(model)) throw WRONG_MODEL;
		if (SetClockRate(cr)) throw WRONG_CLOCK_RATE;
		if (SetCores(cores)) throw WRONG_CORES;
		if (SetRAM(ram)) throw WRONG_RAM;
		if (SetRAMtype(ram_type)) throw WRONG_RAM_TYPE;
		if (SetROM(rom)) throw WRONG_ROM;
		if (SetIMEI(imei)) throw WRONG_IMEI;
		if (SetOS(None, "0")) throw WRONG_OS;
		try
		{
			if (SetApps(apps, used_rom)) throw WRONG_APPS;
		}
		catch(string ex)
		{
			throw ex;
		}
	}
	
	int SmartPhone::AvApps()
	{
		if (apps_ == 0 && used_ROM_ == 0) throw NO_APPS_INSTALLED;
		return int((ROM_ - used_ROM_) / (used_ROM_ / apps_ ));
	}
	void SmartPhone::HardReset()
	{
		SetApps(0, 0);
	}

	std::ostream& operator<<(std::ostream& os, SmartPhone phone)
	{
		os << "SmartPhone:\n";
		os << "Brand: " << phone.GetBrand() << std::endl;
		os << "Model: " << phone.GetModel() << std::endl;
		os << "Clock rate: " << phone.GetClockRate() << std::endl;
		os << "Cores: " << phone.GetCores() << std::endl;
		os << "RAM: " << phone.GetRAM() << std::endl;
		os << "RAM type: " << phone.GetRAMtype() << std::endl;
		os << "ROM: " << phone.GetROM() << std::endl;
		os << "OS: " << phone.GetOS() << std::endl;
		os << "OS version: " << phone.GetOSver() << std::endl;
		os << "IMEI: " << phone.GetIMEI() << std::endl;
		os << "Apps: " << phone.GetApps() << std::endl;
		os << "Used ROM: " << phone.GetUsedROM() << std::endl;
		os << std::endl;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, SmartPhone::IMEI imei)
	{
		os << imei.TAC << "-" << imei.SNR << "-" << imei.FAC << "-" << imei.SP;
		return os;
	}
}
