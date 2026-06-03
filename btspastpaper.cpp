#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class RB; // forward declaration
class C;

// Exception classes
class AllocationError : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Allocation Error Occurred";
    }
};

class RBUnavailableError : public exception
{
public:
    const char *what() const noexcept override
    {
        return "No RB Available";
    }
};

class BTS
{
public:
    pair<int, int> coordinate;
    string uniqueID;
    vector<RB *> RBs;

    BTS(string id, pair<int, int> coord) : uniqueID(id), coordinate(coord) {}

    void allocateRBCell(RB *rb, C *device)
    {
        if (rb->allocated)
            throw AllocationError();
        rb->allocated = true;

        if (rb->isUplinkRB)
            device->uplinkRB = rb;
        else
            device->downlinkRB = rb;
    }

    void deallocateRBCell(RB *rb, C *device)
    {
        rb->allocated = false;
        if (rb->isUplinkRB)
            device->uplinkRB = nullptr;
        else
            device->downlinkRB = nullptr;
    }

    vector<RB *> getFreeRBs()
    {
        vector<RB *> free;
        for (auto rb : RBs)
            if (!rb->allocated)
                free.push_back(rb);
        return free;
    }
};

class C
{
public:
    pair<int, int> coordinate;
    double currentTransmissionPower, minTransmissionPower, maxTransmissionPower;
    string uniqueID;
    RB *uplinkRB = nullptr, *downlinkRB = nullptr;

    C(string id, pair<int, int> coord, double currPwr, double minPwr, double maxPwr)
        : uniqueID(id), coordinate(coord), currentTransmissionPower(currPwr),
          minTransmissionPower(minPwr), maxTransmissionPower(maxPwr) {}

    void startCommunication(BTS &bts)
    {
        vector<RB *> freeRBs = bts.getFreeRBs();
        if (freeRBs.size() < 2)
            throw RBUnavailableError();

        RB *uplink = nullptr;
        RB *downlink = nullptr;

        for (auto rb : freeRBs)
        {
            if (rb->isUplinkRB && uplink == nullptr)
                uplink = rb;
            else if (!rb->isUplinkRB && downlink == nullptr)
                downlink = rb;

            if (uplink && downlink)
                break;
        }

        if (!(uplink && downlink))
            throw RBUnavailableError();

        bts.allocateRBCell(uplink, this);
        bts.allocateRBCell(downlink, this);
    }

    void endCommunication(BTS &bts)
    {
        if (uplinkRB)
            bts.deallocateRBCell(uplinkRB, this);
        if (downlinkRB)
            bts.deallocateRBCell(downlinkRB, this);
    }

    void status()
    {
        cout << "Device: " << uniqueID << endl;
        if (uplinkRB && downlinkRB)
        {
            cout << "  Uplink RB: " << uplinkRB->uniqueID << endl;
            cout << "  Downlink RB: " << downlinkRB->uniqueID << endl;
        }
        else
        {
            cout << "  Not in communication." << endl;
        }
    }
};

class RB
{
public:
    double currentTransmissionPower, minTransmissionPower, maxTransmissionPower;
    bool isUplinkRB;
    double channelFrequency;
    string uniqueID;
    bool allocated = false;

    RB(string id, double currPwr, double minPwr, double maxPwr, bool uplink, double freq)
        : uniqueID(id), currentTransmissionPower(currPwr), minTransmissionPower(minPwr),
          maxTransmissionPower(maxPwr), isUplinkRB(uplink), channelFrequency(freq) {}

    void RB::status()
    {
        cout << "RB: " << uniqueID << (isUplinkRB ? " (Uplink)" : " (Downlink)") << endl;
        cout << "  Current Power: " << currentTransmissionPower << endl;
        if (!isUplinkRB)
        {
            cout << "  Min Power: " << minTransmissionPower << endl;
            cout << "  Max Power: " << maxTransmissionPower << endl;
        }
    }
    void status()
    {
        cout << "RB: " << uniqueID << (isUplinkRB ? " (Uplink)" : " (Downlink)") << endl;
        cout << "  Current Power: " << currentTransmissionPower << endl;
        if (!isUplinkRB)
        {
            cout << "  Min Power: " << minTransmissionPower << endl;
            cout << "  Max Power: " << maxTransmissionPower << endl;
        }
    }
};
