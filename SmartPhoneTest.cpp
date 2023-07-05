#include "SmartPhoneTest.h"
#include "Exceptions.h"
#include "iostream"
namespace test
{
	using device::SmartPhone;
	using std::cout;
	using namespace constants;
	using namespace test_constructor;
	using namespace test_getter;
	using namespace test_method;
	using namespace test_friend;
	using namespace smartphone_exceptions;


	SmartPhone create_obj()
	{
		SmartPhone ph = SmartPhone(brand_corr, model_corr,
			clock_rate_corr, cores_corr,
			RAM_corr, RAM_type_corr,
			ROM_corr, IMEI_corr,
			OS_corr, OS_ver_corr,
			apps_corr, usedROM_corr);
		return ph;
	}
	int test_constructors()
	{
		cout << "\nTesting construcotrs\n";
		test_const1_allright1();
		test_const1_allright2();
		test_const1_allright3();
		test_const1_wrong_brand();
		test_const1_wrong_model();
		test_const1_wrong_clock_rate();
		test_const1_wrong_cores();
		test_const1_wrong_RAM();
		test_const1_wrong_RAM_type();
		test_const1_wrong_ROM();
		test_const1_wrong_OS();
		tets_const1_wrong_OS_ver();
		test_const1_wrong_apps();
		test_const1_wrong_usedROM();
		test_const1_wrong_apps_usedROM();
		test_conts1_wrong_IMEI1();
		test_const1_wrong_IMEI2();
		test_const2_allright();
		cout << "Passed " << passed_tests << " out of " << tests << std::endl << float(passed_tests) / tests * 100 << "%\n";
		return 0;
	}
	int test_getters()
	{
		cout << "\nTesting getters\n";
		test_get_brand();
		test_get_model();
		test_get_clock_rate();
		test_get_cores();
		test_get_RAM();
		test_get_RAM_type();
		test_get_ROM();
		test_get_OS();
		test_get_OS_ver();
		test_get_apps();
		test_get_IMEI();
		test_get_Used_ROM();
		cout << "Passed " << passed_tests << " out of " << tests << std::endl << float(passed_tests) / tests * 100 << "%\n";
		return 0;
	}
	int test_methods()
	{
		cout << "\nTesting methods\n";
		test_AvApps1();
		test_AvApps2();
		test_HardReset();
		cout << "Passed " << passed_tests << " out of " << tests << std::endl << float(passed_tests) / tests * 100 << "%\n";
		return 0;
	}
	int test_friends()
	{
		cout << "\nTesting friends\n";
		test_output_IMEI();
		test_output_SmartPhone();
		cout << "Passed " << passed_tests << " out of " << tests << std::endl << float(passed_tests) / tests * 100 << "%\n";
		return 0;
	}
	int all_tests()
	{
		cout << "START TEST\n\n";
		test_constructors();
		test_getters();
		test_methods();
		test_friends();
		cout << "\nEND TEST\n\n";
		return 0;
	}

	namespace test_constructor
	{
		int test_const1_allright1()
		{
			tests++;
			cout << "Testing constructor 1. Full argument list, all right.\n";
			int err = 0;
			SmartPhone ph = SmartPhone(brand_corr, model_corr,
				clock_rate_corr, cores_corr,
				RAM_corr, RAM_type_corr,
				ROM_corr, IMEI_corr,
				OS_corr, OS_ver_corr,
				apps_corr, usedROM_corr);
			if (ph.GetBrand() != brand_corr)
			{
				err++;
				cout << "\tBrand is incorrect.\n";
			}
			if (ph.GetModel() != model_corr)
			{
				err++;
				cout << "\tModel is incorrect.\n";
			}
			if (ph.GetClockRate() != clock_rate_corr)
			{
				err++;
				cout << "\tClock rate is incorrect.\n";
			}
			if (ph.GetCores() != cores_corr)
			{
				err++;
				cout << "\tCores are incorrect.\n";
			}
			if (ph.GetRAM() != RAM_corr)
			{
				err++;
				cout << "\tRAM is incorrect.\n";
			}
			if (ph.GetRAMtype() != RAM_type_corr)
			{
				err++;
				cout << "\tRAM type is incorrect.\n";
			}
			if (ph.GetROM() != ROM_corr)
			{
				err++;
				cout << "\tROM is incorrect.\n";
			}
			if (string(ph.GetIMEI()) != IMEI_corr)
			{
				err++;
				cout << "\tIMEI is incorrect.\n";
			}
			if (ph.GetOS() != OS_corr)
			{
				err++;
				cout << "\tOS is incorrect.\n";
			}
			if (ph.GetOSver() != OS_ver_corr)
			{
				err++;
				cout << "\tOS version is incorrect.\n";
			}
			if (ph.GetApps() != apps_corr)
			{
				err++;
				cout << "\tApps are incorrect.\n";
			}
			if (ph.GetUsedROM() != usedROM_corr)
			{
				err++;
				cout << "\tUsed ROM is incorrect.\n";
			}
			cout << "Test passed with " << 12 - err << "/12: " << double(err) / 12.0 << std::endl;
			if (err == 0) passed_tests++;
			return err;
		}
		int test_const1_allright2()
		{
			tests++;
			cout << "Testing constructor 1. Necessary arguments only, all right.\n";
			int err = 0;
			SmartPhone ph = SmartPhone(brand_corr, model_corr,
				clock_rate_corr, cores_corr,
				RAM_corr, RAM_type_corr,
				ROM_corr, IMEI_corr);
			if (ph.GetBrand() != brand_corr)
			{
				err++;
				cout << "\tBrand is incorrect.\n";
			}
			if (ph.GetModel() != model_corr)
			{
				err++;
				cout << "\tModel is incorrect.\n";
			}
			if (ph.GetClockRate() != clock_rate_corr)
			{
				err++;
				cout << "\tClock rate is incorrect.\n";
			}
			if (ph.GetCores() != cores_corr)
			{
				err++;
				cout << "\tCores are incorrect.\n";
			}
			if (ph.GetRAM() != RAM_corr)
			{
				err++;
				cout << "\tRAM is incorrect.\n";
			}
			if (ph.GetRAMtype() != RAM_type_corr)
			{
				err++;
				cout << "\tRAM type is incorrect.\n";
			}
			if (ph.GetROM() != ROM_corr)
			{
				err++;
				cout << "\tROM is incorrect.\n";
			}
			if (string(ph.GetIMEI()) != IMEI_corr)
			{
				err++;
				cout << "\tIMEI is incorrect.\n";
			}
			if (ph.GetOS() != OS_null)
			{
				err++;
				cout << "\tOS is incorrect.\n";
			}
			if (ph.GetOSver() != OS_ver_null)
			{
				err++;
				cout << "\tOS version is incorrect.\n";
			}
			if (ph.GetApps() != apps_null)
			{
				err++;
				cout << "\tApps are incorrect.\n";
			}
			if (ph.GetUsedROM() != usedROM_null)
			{
				err++;
				cout << "\tUsed ROM is incorrect.\n";
			}
			cout << "Test passed with " << 12 - err << "/12: " << double(err) / 12.0 << std::endl;
			if (err == 0) passed_tests++;
			return err;
		}
		int test_const1_allright3()
		{
			tests++;
			cout << "Testing constructor 1. Full argument list + OS and its version, all right.\n";
			int err = 0;
			SmartPhone ph = SmartPhone(brand_corr, model_corr,
				clock_rate_corr, cores_corr,
				RAM_corr, RAM_type_corr,
				ROM_corr, IMEI_corr,
				OS_corr, OS_ver_corr);
			if (ph.GetBrand() != brand_corr)
			{
				err++;
				cout << "\tBrand is incorrect.\n";
			}
			if (ph.GetModel() != model_corr)
			{
				err++;
				cout << "\tModel is incorrect.\n";
			}
			if (ph.GetClockRate() != clock_rate_corr)
			{
				err++;
				cout << "\tClock rate is incorrect.\n";
			}
			if (ph.GetCores() != cores_corr)
			{
				err++;
				cout << "\tCores are incorrect.\n";
			}
			if (ph.GetRAM() != RAM_corr)
			{
				err++;
				cout << "\tRAM is incorrect.\n";
			}
			if (ph.GetRAMtype() != RAM_type_corr)
			{
				err++;
				cout << "\tRAM type is incorrect.\n";
			}
			if (ph.GetROM() != ROM_corr)
			{
				err++;
				cout << "\tROM is incorrect.\n";
			}
			if (string(ph.GetIMEI()) != IMEI_corr)
			{
				err++;
				cout << "\tIMEI is incorrect.\n";
			}
			if (ph.GetOS() != OS_corr)
			{
				err++;
				cout << "\tOS is incorrect.\n";
			}
			if (ph.GetOSver() != OS_ver_corr)
			{
				err++;
				cout << "\tOS version is incorrect.\n";
			}
			if (ph.GetApps() != apps_null)
			{
				err++;
				cout << "\tApps are incorrect.\n";
			}
			if (ph.GetUsedROM() != usedROM_null)
			{
				err++;
				cout << "\tUsed ROM is incorrect.\n";
			}
			cout << "Test passed with " << 12 - err << "/12: " << double(err) / 12.0 << std::endl;
			if (err == 0) passed_tests++;
			return err;
		}
		int test_const1_wrong_brand()
		{
			tests++;
			cout << "Testing constructor 1. Wrong brand.\n";
			try {
				SmartPhone ph = SmartPhone(brand_incorr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex != WRONG_BRAND)
				{
					cout << "\t Handled unknown error.\n";
					return 1;
				}

				passed_tests++;
				cout << "\tTest passed.\n";
				return 0;
			}
			catch (...)
			{
				cout << "\t Handled unknown error.\n";
				return 1;
			}
		}
		int test_const1_wrong_model()
		{
			tests++;
			cout << "Testing constructor 1. Wrong model.\n";
			try {
				SmartPhone ph = SmartPhone(brand_corr, model_incorr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_MODEL) 
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_const1_wrong_clock_rate()
		{
			tests++;
			cout << "Testing constructor 1. Wrong clock rate.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_incorr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_CLOCK_RATE) 
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknonw error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknonw error.\n";
				return 1;
			}
		}
		int test_const1_wrong_cores()
		{
			tests++;
			cout << "Testing constructor 1. Wrong cores.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_incorr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr);
				cout << "\tDidn't catch error.";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_CORES) 
				{
					passed_tests++;
					cout << "Test passed.";
					return 0;
				}
				cout << "Handled unknown error.";
				return 1;
			}
			catch (...)
			{
				cout << "Handled unknown error.";
				return 1;
			}
		}
		int test_const1_wrong_RAM()
		{
			tests++;
			cout << "Testing constructor 1. Wrong RAM.\n";
			try {
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_incorr, RAM_type_corr,
					ROM_corr, IMEI_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_RAM)
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled uknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled uknown error.\n";
				return 1;
			}
		}
		int test_const1_wrong_RAM_type()
		{
			tests++;
			cout << "Testing constructor 1. Wrong RAM type.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_incorr,
					ROM_corr, IMEI_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_RAM_TYPE)
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_const1_wrong_ROM()
		{
			tests++;
			cout << "Testing constructor 1. Wrong ROM.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_incorr, IMEI_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_ROM)
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_const1_wrong_OS()
		{
			tests++;
			cout << "Testing constructor 1. Wrong OS.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr,
					OS_incorr, OS_ver_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_OS)
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int tets_const1_wrong_OS_ver()
		{
			tests++;
			cout << "Tetsting constructor 1. Wrong OS version.\n";
			try {
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr,
					OS_corr, OS_ver_incorr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_OS_VERSION)
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled uknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled uknown error.\n";
				return 1;
			}
		}
		int test_const1_wrong_apps()
		{
			tests++;
			cout << "Testing constructor 1. Wrong apps.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr,
					apps_incorr, usedROM_corr);
				cout << "\tDidn't catch error.";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_APPS) 
				{
					passed_tests++;
					cout << "Test passed.";
					return 0;
				}
				cout << "Handled unknown error.";
				return 1;
			}
			catch (...)
			{
				cout << "Handled unknown error.";
				return 1;
			}
		}
		int test_const1_wrong_usedROM()
		{
			tests++;
			cout << "Testing constructor 1. Wrong used ROM.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr,
					apps_corr, usedROM_incorr);
				cout << "\tDidn't catch error.";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_USED_ROM) 
				{
					passed_tests++;
					cout << "Test passed.";
					return 0;
				}
				cout << "Handled unknown error.";
				return 1;
			}
			catch (...)
			{
				cout << "Handled unknown error.";
				return 1;
			}
		}
		int test_const1_wrong_apps_usedROM()
		{
			tests++;
			cout << "Testing constructor 1. Wrong apps and used ROM.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_corr,
					apps_incorr2, usedROM_incorr2);
				cout << "\tDidn't catch error.";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_APPS_AND_ROM)
				{
					passed_tests++;
					cout << "Test passed.";
					return 0;
				}
				cout << "Handled unknown error.";
				return 1;
			}
			catch (...)
			{
				cout << "Handled unknown error.";
				return 1;
			}
		}
		int test_conts1_wrong_IMEI1()
		{
			tests++;
			cout << "Testing constructor 1. Wrong IMEI: empty name.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_incorr1,
					OS_corr, OS_ver_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_IMEI)
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_const1_wrong_IMEI2()
		{
			tests++;
			cout << "Testing constructor 1. Wrong IMEI: amount of symbols is not equal to 15.\n";
			try
			{
				SmartPhone ph = SmartPhone(brand_corr, model_corr,
					clock_rate_corr, cores_corr,
					RAM_corr, RAM_type_corr,
					ROM_corr, IMEI_incorr2,
					OS_corr, OS_ver_corr);
				cout << "\tDidn't catch error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == WRONG_IMEI) 
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
		int test_const2_allright()
		{
			tests++;
			cout << "Testing constructor 2. Full argument list, all right.\n";
			int err = 0;
			SmartPhone ph = SmartPhone(brand_corr, model_corr,
				clock_rate_corr, cores_corr,
				RAM_corr, RAM_type_corr,
				ROM_corr, IMEI_corr,
				apps_corr, usedROM_corr);
			if (ph.GetBrand() != brand_corr)
			{
				err++;
				cout << "\tBrand is incorrect.\n";
			}
			if (ph.GetModel() != model_corr)
			{
				err++;
				cout << "\tModel is incorrect.\n";
			}
			if (ph.GetClockRate() != clock_rate_corr)
			{
				err++;
				cout << "\tClock rate is incorrect.\n";
			}
			if (ph.GetCores() != cores_corr)
			{
				err++;
				cout << "\tCores are incorrect.\n";
			}
			if (ph.GetRAM() != RAM_corr)
			{
				err++;
				cout << "\tRAM is incorrect.\n";
			}
			if (ph.GetRAMtype() != RAM_type_corr)
			{
				err++;
				cout << "\tRAM type is incorrect.\n";
			}
			if (ph.GetROM() != ROM_corr)
			{
				err++;
				cout << "\tROM is incorrect.\n";
			}
			if (string(ph.GetIMEI()) != IMEI_corr)
			{
				err++;
				cout << "\tIMEI is incorrect.\n";
			}
			if (ph.GetOS() != OS_null)
			{
				err++;
				cout << "\tOS is incorrect.\n";
			}
			if (ph.GetOSver() != OS_ver_null)
			{
				err++;
				cout << "\tOS version is incorrect.\n";
			}
			if (ph.GetApps() != apps_corr)
			{
				err++;
				cout << "\tApps are incorrect.\n";
			}
			if (ph.GetUsedROM() != usedROM_corr)
			{
				err++;
				cout << "\tUsed ROM is incorrect.\n";
			}
			if (err == 0) passed_tests++;
			cout << "Test passed with " << 12 - err << "/12: " << double(err) / 12.0 << std::endl;
			return err;
		}
	}
	namespace test_getter
	{

		int test_get_brand()
		{
			tests++;
			cout << "Testing brand getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetBrand() != brand_corr)
			{
				cout << "\tNot passed. Expected: " << brand_corr << ". Got: " << ph.GetBrand() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_model()
		{
			tests++;
			cout << "Testing model getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetModel() != model_corr)
			{
				cout << "\tNot passed. Expected: " << model_corr << ". Got: " << ph.GetModel() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_clock_rate()
		{
			tests++;
			cout << "Testing clock rate getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetClockRate() != clock_rate_corr)
			{
				cout << "\tNot passed. Expected: " << clock_rate_corr << ". Got: " << ph.GetClockRate() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_cores()
		{
			tests++;
			cout << "Testing cores getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetCores() != cores_corr)
			{
				cout << "\tNot passed. Expected: " << cores_corr << ". Got: " << ph.GetCores() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_RAM()
		{
			tests++;
			cout << "Testing RAM getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetRAM() != RAM_corr)
			{
				cout << "\tNot passed. Expected: " << RAM_corr << ". Got: " << ph.GetRAM() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_RAM_type()
		{
			tests++;
			cout << "Testing RAM type getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetRAMtype() != RAM_type_corr)
			{
				cout << "\tNot passed. Expected: " << RAM_type_corr << ". Got: " << ph.GetRAMtype() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_ROM()
		{
			tests++;
			cout << "Testing ROM getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetROM() != ROM_corr)
			{
				cout << "\tNot passed. Expected: " << ROM_corr << ". Got: " << ph.GetROM() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_OS()
		{
			tests++;
			cout << "Testing OS getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetOS() != OS_corr)
			{
				cout << "\tNot passed. Expected: " << OS_corr << ". Got: " << ph.GetOS() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_OS_ver()
		{
			tests++;
			cout << "Testing OS version getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetOSver() != OS_ver_corr)
			{
				cout << "\tNot passed. Expected: " << OS_ver_corr << ". Got: " << ph.GetOSver() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_apps()
		{
			tests++;
			cout << "Testing apps getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetApps() != apps_corr)
			{
				cout << "\tNot passed. Expected: " << apps_corr << " Got: " << ph.GetApps() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_IMEI()
		{
			tests++;
			cout << "Testing IMEI getter.\n";
			SmartPhone ph = create_obj();
			if (string(ph.GetIMEI()) != IMEI_corr)
			{
				cout << "\tNot passed. Expected: " << IMEI_corr << ". Got: " << string(ph.GetIMEI()) << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_get_Used_ROM()
		{
			tests++;
			cout << "Testing IMEI getter.\n";
			SmartPhone ph = create_obj();
			if (ph.GetUsedROM() != usedROM_corr)
			{
				cout << "\tNot passed. Expected: " << usedROM_corr << ". Got: " << ph.GetUsedROM() << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
	}
	namespace test_method
	{
		int test_HardReset()
		{
			tests++;
			cout << "Testing Hard Reset.\n";
			SmartPhone ph = create_obj();
			ph.HardReset();
			float num1 = ph.GetUsedROM();
			float num2 = 0.0f;
			if (ph.GetApps() == 0 && ph.GetUsedROM() == 0.0f)
			{
				passed_tests++;
				cout << "\tTest passed.\n";
				return 0;
			}
			cout << "\tWrong output. Excepted: 0; 0. Got: " << ph.GetApps() << "; " << ph.GetUsedROM();
			return 1;
		}
		int test_AvApps1()
		{
			tests++;
			cout << "Testing AvApps.\n";
			SmartPhone ph = create_obj();
			int num = ph.AvApps();
			if (num != expected_avApps1)
			{
				cout << "\tWrong output. Excepted: " << expected_avApps1 << ". Got: " << num << std::endl;
				return 1;
			}
			passed_tests++;
			cout << "\tTest passed.\n";
			return 0;
		}
		int test_AvApps2()
		{
			tests++;
			cout << "Testing AvApps. Zero list.\n";
			SmartPhone ph = create_obj();
			ph.HardReset();
			try
			{
				int num = ph.AvApps();
				cout << "\tDidn't catch the error.\n";
				return 1;
			}
			catch (string ex)
			{
				if (ex == NO_APPS_INSTALLED)
				{
					passed_tests++;
					cout << "\tTest passed.\n";
					return 0;
				}
				cout << "\tHandled unknown error.\n";
				return 1;
			}
			catch (...)
			{
				cout << "\tHandled unknown error.\n";
				return 1;
			}
		}
	}
	namespace test_friend
	{
		int test_output_IMEI()
		{
			tests++;
			cout << "Testing output IMEI.\n";
			SmartPhone ph = create_obj();
			cout << ph.GetIMEI();
			cout << "\nIf output is correct, enter 0, else 1: ";
			int num;
			std::cin >> num;
			if (!num) passed_tests++;
			return num;
		}
		int test_output_SmartPhone()
		{
			tests++;
			cout << "Testing output SmartPhone.\n";
			SmartPhone ph = create_obj();
			cout << ph;
			cout << "\nIf output is correct, enter 0, else 1: ";
			int num;
			std::cin >> num;
			if (!num) passed_tests++;
			return num;
		}
	}
}