#include "Device.h"

Remote::Remote(Device* device)
{
	setDevice(device);
}

void Remote::setDevice(Device* device)
{
	if (device) {
		this->device = device;
	}
}

void Remote::togglePower()
{
	if (device->isEnabled()) {
		device->disable();
		std::cout << "Device off";
	}
	else {
		std::cout << "Device on";
		device->enable();
	}
}

void Remote::volumeDown()
{
	if (device->getVolume() > 0) {
		size_t volume = device->getVolume();
		device->setVolume(--volume);
	}
}

void Remote::volumeUp()
{
	size_t volume = device->getVolume();
	device->setVolume(++volume);
}

void Remote::channelDown()
{
	if (device->getChannel() > 0) {
		size_t channel = device->getChannel();
		device->setChannel(--channel);
	}
}

void Remote::channelUp()
{
	size_t channel = device->getChannel();
	device->setChannel(++channel);
}

void AdvancedRemote::mute()
{
	device->setVolume(0);
}

TV::TV(const size_t MAX_VOLUME, const size_t MAX_CHANNEL) : MAX_CHANNEL(MAX_CHANNEL), MAX_VOLUME(MAX_VOLUME)
{
	enabled = false;
}

const bool TV::isEnabled() const
{
	return enabled;
}

void TV::enable()
{
	enabled = true;
}

void TV::disable()
{
	enabled = false;
}

const size_t& TV::getVolume() const
{
	return currentVolume;
}

void TV::setVolume(const size_t& percent)
{
	if (percent <= MAX_VOLUME) {
		currentVolume = percent;
		std::cout << "Volume " << currentVolume << std::endl;
	}
}

const size_t& TV::getChannel() const
{
	return currentChannel;
}

void TV::setChannel(const size_t& channel)
{
	if (channel <= MAX_CHANNEL) {
		currentChannel = channel;
		std::cout << "Channel " << currentChannel << std::endl;
	}
}

Radio::Radio(const size_t MAX_VOLUME, const size_t MAX_CHANNEL) : MAX_CHANNEL(MAX_CHANNEL), MAX_VOLUME(MAX_VOLUME)
{
	enabled = false;
}

const bool Radio::isEnabled() const
{
	return enabled;
}

void Radio::enable()
{
	enabled = true;
}

void Radio::disable()
{
	enabled = false;
}

const size_t& Radio::getVolume() const
{
	return currentVolume;
}

void Radio::setVolume(const size_t& percent)
{
	if (percent <= MAX_VOLUME) {
		currentVolume = percent;
		std::cout << "Volume " << currentVolume << std::endl;
	}
}

const size_t& Radio::getChannel() const
{
	return currentChannel;
}

void Radio::setChannel(const size_t& channel)
{
	if (channel <= MAX_CHANNEL) {
		currentChannel = channel;
		std::cout << "Channel " << currentChannel << std::endl;
	}
}

