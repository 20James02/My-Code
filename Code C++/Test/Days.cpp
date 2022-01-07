#include <iostream>

using namespace std;

class Time {
	private:
		int hours, minutes, seconds;
	public:
		void getInformation() {
		cin >> hours >> minutes >> seconds;
	}
		void display() {
			cout << hours << ":" << minutes << ":" << seconds;
	}
		void addit(const Time &a, const Time &b) {
			hours = a.hours + b.hours;
			minutes = a.minutes + b.minutes;
			seconds = a.seconds + b.seconds;
			if (seconds >= 60) {
				seconds -= 60;
				minutes++;
			}
			if (minutes >= 60) {
				minutes -= 60;
				hours++;
			}
		}
Time &addit(const Time &b) {
	hours = hours + b.hours;
	minutes = minutes + b.minutes;
	seconds = seconds + b.seconds;
	if (seconds >= 60) {
		seconds -= 60;
		minutes++;
	}
	if (minutes >= 60) {
		minutes -= 60;
		hours++;
	}
	return *this;
    }
};

int main() {
    Time one, two, three;
	cout << "\nNhap vao thoi gian mot (gio phut giay): ";
	one.getInformation();
	cout << "\nNhap vao thoi gian hai (gio phut giay): ";
	two.getInformation();
	three.addit(one, two);
	cout << "\nKet qua la: ";
	three.display();
	three = one.addit(two);
	cout << "\nKet qua la: ";
	three.display();
	return 0;
}