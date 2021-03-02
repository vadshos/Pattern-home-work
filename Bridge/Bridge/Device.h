#pragma once
#include<iostream>

__interface Device
{
	const bool isEnabled() const;
	void enable();
	void disable();
	const size_t& getVolume() const;
	void setVolume(const size_t& percent);
	const size_t& getChannel() const;
	void setChannel(const size_t& channel);
};

class TV : public Device
{
public:
	TV(const size_t MAX_VOLUME = 100, const size_t MAX_CHANNEL = 100);
	const bool isEnabled() const;
	void enable();
	void disable();
	const size_t& getVolume() const;
	void setVolume(const size_t& percent);
	const size_t& getChannel() const;
	void setChannel(const size_t& channel);
private:
	bool enabled;
	size_t currentChannel = 0;
	size_t currentVolume = 0;
	const size_t MAX_VOLUME;
	const size_t MAX_CHANNEL;
};

class Radio : public Device
{
public:
	Radio(const size_t MAX_VOLUME = 100, const size_t MAX_CHANNEL = 100);
	const bool isEnabled() const;
	void enable();
	void disable();
	const size_t& getVolume() const;
	void setVolume(const size_t& percent);
	const size_t& getChannel() const;
	void setChannel(const size_t& channel);
private:
	bool enabled;
	size_t currentChannel = 0;
	size_t currentVolume = 0;
	const size_t MAX_VOLUME;
	const size_t MAX_CHANNEL;
};

class Remote
{
public:
	Remote(Device* device = nullptr);
	void setDevice(Device* device);
	void togglePower();
	void volumeDown();
	void volumeUp();
	void channelDown();
	void channelUp();
protected:
	Device* device;
};

class AdvancedRemote : public Remote
{
public:
	AdvancedRemote(Device* device = nullptr) : Remote(device) {

	}
	void mute();
};

