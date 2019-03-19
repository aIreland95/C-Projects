// Project6Redo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <deque>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

class Alert {

public:

	Alert() {}

	Alert(string name, int severity, int locationID) {

		mName = name;
		mSeverity = severity;
		mLocationID = locationID;
	}

	string getAlertInfo() {

		return "[" + (to_string(mSeverity)) + "]" + mName + "<" + (to_string(mLocationID)) + ">";
	}

	string mName;
	int mSeverity;
	int mLocationID;
};

class AlertManager {

public:

	deque<Alert*> alerts;

	void addAlert(const Alert& alert) {

		Alert* new_alert = new Alert(alert.mName, alert.mSeverity, alert.mLocationID);

		if (alerts.size() == 0) {

			alerts.push_front(new_alert);
			return;
		}

		if (alerts.back()->mSeverity < new_alert->mSeverity) {

			alerts.push_back(new_alert);
			return;
		}
		else {

			deque<Alert*>::iterator it = alerts.begin();

			for (int i = 0; it != alerts.end(); it++, i++) {

				if (alerts[i]->mSeverity > new_alert->mSeverity) {

					it = alerts.insert(it, new_alert);
					break;
				}
			}
		}
	}

	Alert getNext() {

		Alert copy(alerts.front()->mName, alerts.front()->mSeverity, alerts.front()->mLocationID);
		alerts.pop_front();
		return copy;
	}

	void printWaiting() {

		for (auto& a : alerts) {
			
			cout << a->getAlertInfo() << endl;
		}
		cout << endl;
	}

	~AlertManager() {

		for (auto& a : alerts) {
			delete a;
		}
	}

};

int main()
{
	cout << "-----Security Alert Manager-----\n" << endl;

	AlertManager manager;

	Alert test = Alert("Smoke Alarm", 1, 32);
	Alert test2 = Alert("Temperature", 3, 48);
	Alert test3 = Alert("Front Door", 2, 24);
	Alert test4 = Alert("Carbon Monoxide", 1, 15);

	manager.addAlert(test);
	manager.addAlert(test2);
	manager.addAlert(test3);
	manager.addAlert(test4);

	for (int i = 0; i < 4; i++) {

	manager.printWaiting();
	manager.getNext();
	}

    return 0;
}

