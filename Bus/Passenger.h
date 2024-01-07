#pragma once
#include <string>
using namespace std;


class Passenger {
private:
    string type;
    int id;
    int arrivalTime;
    int startStation;
    int endStation;
    int priority;
    //we initialize those variables to -1 for many reasons
    //(1) easy detection
    //(2) uniqueness ass not any variable is initialized to -1 in our project as it is not a valid input
    int gettingTime = -1;
    int movingTime = -1;
    int finishTime = -1;

public:
    Passenger(string type, int id, int arrivalTime, int startStation, int endStation, int priority)
        : type(move(type)), arrivalTime(arrivalTime), startStation(startStation), endStation(endStation), priority(priority), id(id) {}

    // Getters
    string getType() const { return type; }
    int getId() const { return id; }
    int getArrivalTime() const { return arrivalTime; }
    int getStartStation() const { return startStation; }
    int getEndStation() const { return endStation; }
    int getPriority() const { return priority; }
    int getGettingTime() const { return gettingTime; }
    int getMovingTime() const { return movingTime; }
    int getWaitingTime() const { return movingTime - arrivalTime; }
    int getTripTime() const { return finishTime - movingTime; }
    int getFinishTime() const { return finishTime; }

    // Setters
    void setMovingTime(int movingTime) { this->movingTime = movingTime; }
    void setFinishTime(int finishTime) { this->finishTime = finishTime; }
    void setGettingTime(int gettingTime) { this->gettingTime = gettingTime; }
    void setPriority(int priority) { this->priority = priority; }
};
