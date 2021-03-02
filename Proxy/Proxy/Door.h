#pragma once
#include<iostream>
#include<vector>

#include<map>

#define LOGIN std::string
#define PASSWORD std::string

enum class States{CLOSED,OPENED};

class State;

__interface IDoor
{
	virtual void setState(const States& state);
	virtual void setStatus(State* status);
	virtual void close();
	virtual void open();

};

class State abstract {
protected:
	IDoor* door;
public:
	State(IDoor* door) : door(door) {};
	virtual void close() = 0;
	virtual void open() = 0;
};

class Door : public IDoor
{
private:
	class DoorOpen : public State
	{
	protected:
		IDoor* door;
	public:
		DoorOpen(IDoor* door) : State(door) {
			this->door = door;
		};
		void close() override {
			door->setState(States::CLOSED);

			door->setStatus(new DoorClose(door));
			std::cout << "Door closed" << std::endl;

		}
		void open() override {
			std::cout << "Door is alredy open" << std::endl;
		};
	};
	class DoorClose : public State
	{
	protected:
		IDoor* door;
	public:
		DoorClose(IDoor* door) : State(door) {
			this->door = door;
		};
		void close() override {
			std::cout << "Door is alredy close";
		}
		void open() override {
			std::cout << "Door opened" << std::endl;
			door->setState(States::OPENED);
			door->setStatus(new DoorOpen(door));
		};
	};
protected:
	class State* status;
	States state;
public:
	Door(States states = States::OPENED) {
		setState(states);
		if (state == States::OPENED) {
			
			status  = new DoorOpen(this);
		}
		else if (state == States::CLOSED) {
			status = new DoorClose(this);
		}
	}
	
	void close() override {
		status->close();
	}
	void open(){
		status->open();
	}
	const bool getStatus() const {
		return (int)state;
	}
	const void showStatus() const {
		std::vector<std::string> stat{ "Open,Close" };
		std::cout << "Door is " << stat[(int)state];
	}
	void setState(const  States& state) override{
		this->state = state;
	}
	void setStatus(State* status) override {
		if (status != nullptr)
			this->status = status;
	}
};

class SecureProxy : public IDoor
{
public:
	void open() {};
	void setState(const States& state) {};
	void setStatus(State* status) {};
	SecureProxy(Door* door) : door(door) {};
	void open(const LOGIN login, const PASSWORD password) {
		if (getAutorisation(login, password))
		{
			door->open();
		}
		else {
			std::cout << "access error"<<std::endl;
		}

	}
	virtual void close() override {
		door->close();
	}
private:
	std::map<LOGIN, PASSWORD> users{ {"Petro","12345"} };
	const bool getAutorisation(const LOGIN login, const PASSWORD password) const {
		auto it = users.find(login);
		if (it != users.end()) {
			if(it->second == password)
			return true;
		}
		return false;
	}
	Door* door;
};