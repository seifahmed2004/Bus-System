#pragma once
#include "Station.h"
#include "Event.h"
#include <string>
#include "DataStructures/LinkedList.h"
using namespace std;



class Event
{
protected:
	int timestep;
	int id;
public:
	Event(int timestep, int id) {
		this->timestep = timestep;
		this->id = id;
	}
	virtual void execute(Station* stations) = 0;
	int getTimestep() {
		return timestep;
	}
};

class ArrivalEvent :
    public Event
{
    string passenegerType;
    int startStation;
    int endStation;
    int priority;
public:
    ArrivalEvent(int timestep, int id, string passenegerType, int startStation, int endStation, int priority = -1)
        :Event(timestep, id),
        passenegerType(passenegerType), startStation(startStation - 1), endStation(endStation - 1), priority(priority) {}

    void execute(Station* stations) {

        Passenger* passenger = new Passenger(passenegerType, id, timestep, startStation, endStation, priority);

        stations[startStation].addPassenger(passenger);
    }
};

class LeaveEvent :
    public Event
{
    int numberOfStations;
public:
    LeaveEvent(int timestep, int id, int numberOfStations) : Event(timestep, id), numberOfStations(numberOfStations) {}
    void execute(Station* stations) {
        for (int i = 0; i < numberOfStations; i++) {
            stations[i].passengerLeave(id);
        }
    }
};

