#include <iostream>
#include <vector>

class Receiver {
public:
	void LogMessage(std::string msg) {
		std::cout << msg << std::endl;
	}
};

class Sender {
public:
	virtual void AddReceiver(Receiver* r) = 0;
	virtual void RemoveReceiver(Receiver* r) = 0;
};

class Actor : public Sender, public Receiver {
	std::vector<Receiver*> subscribers;
public:
	void MessageBomb(std::string m) {
		for (Receiver* r : subscribers)
			r->LogMessage(m);
	}
	void AddReceiver(Receiver* r) override {
		subscribers.push_back(r);
	}
	void RemoveReceiver(Receiver* r) override {
		subscribers.erase(std::find(subscribers.begin(), subscribers.end(), r));
	}
};

int main()
{
	Actor* actor1 = new Actor;
	Actor* actor2 = new Actor;
	Actor* actor3 = new Actor;

	actor1->AddReceiver(actor2);
	actor1->AddReceiver(actor3);
	actor1->MessageBomb("message");

	delete actor1;
	delete actor2;
	delete actor3;
	return 0;
}