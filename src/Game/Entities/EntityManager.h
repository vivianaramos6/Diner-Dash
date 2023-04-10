#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"
#include "StoveCounter.h"
class EntityManager {

private:
	int clientsThatLeft = 0;

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeClients(bool onlyLeavingClients = false);
	void removeLeavingClients();
	void resetClients();
	void resetStoves();
	std::vector<Entity*> entities;

	// Getters and setters
	int getClientsThatLeft() { return clientsThatLeft; }
	void clientLeft() { clientsThatLeft++; }
};