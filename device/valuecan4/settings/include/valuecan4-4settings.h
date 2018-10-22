#ifndef __VALUECAN4_4_SETTINGS_H_
#define __VALUECAN4_4_SETTINGS_H_

#include "device/include/idevicesettings.h"
#include "device/valuecan4/settings/include/valuecan4-4-2elsettings.h"

#ifdef __cplusplus

namespace icsneo {

class ValueCAN4_4Settings : public ValueCAN4_4_2ELSettings {
public:
	ValueCAN4_4Settings(std::shared_ptr<Communication> com) : ValueCAN4_4_2ELSettings(com) {}
	CAN_SETTINGS* getCANSettingsFor(Network net) override {
		auto cfg = getStructurePointer<valuecan4_4_2el_settings_t>();
		switch(net.getNetID()) {
			case Network::NetID::HSCAN:
				return &(cfg->can1);
			case Network::NetID::HSCAN2:
				return &(cfg->can2);
			case Network::NetID::HSCAN3:
				return &(cfg->can3);
			case Network::NetID::HSCAN4:
				return &(cfg->can4);
			default:
				return nullptr;
		}
	}
	// CANFD_SETTINGS* getCANFDSettingsFor(Network net) override { return nullptr; }
};

}

#endif // __cplusplus

#endif