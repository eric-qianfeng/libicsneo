#ifndef __ENCODER_H_
#define __ENCODER_H_

#include "icsneo/communication/message/message.h"
#include "icsneo/communication/message/canmessage.h"
#include "icsneo/communication/packet.h"
#include "icsneo/communication/command.h"
#include "icsneo/communication/network.h"
#include "icsneo/communication/packetizer.h"
#include <queue>
#include <vector>
#include <memory>

namespace icsneo {

class Encoder {
public:
	Encoder(device_errorhandler_t err, std::shared_ptr<Packetizer> p) : packetizer(p), err(err) {}
	bool encode(std::vector<uint8_t>& result, const std::shared_ptr<Message>& message);
	bool encode(std::vector<uint8_t>& result, Command cmd, bool boolean) { return encode(result, cmd, std::vector<uint8_t>({ (uint8_t)boolean })); }
	bool encode(std::vector<uint8_t>& result, Command cmd, std::vector<uint8_t> arguments = {});

	bool supportCANFD = false;
private:
	std::shared_ptr<Packetizer> packetizer;
	device_errorhandler_t err;
};

}

#endif