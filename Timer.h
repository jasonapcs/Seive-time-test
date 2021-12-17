#pragma once

/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <array>
#include <chrono>

static unsigned long long time_micro() {
	return std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()).time_since_epoch().count();
}

class timer {
public:
	timer() : prevtime(time_micro()) { }

	void reset() {
		prevtime = time_micro();
	}

	double elapsed_ms() {
		unsigned long long t = time_micro();
		double e = (t - prevtime) / 1000.0;
		prevtime = t;
		return e;
	}

private:
	unsigned long long prevtime;
};

class avgtime {
public:
	avgtime() : times({ 0.0 }), timel(0) { }
	double get() {
		return (times[0] + times[1] + times[2] + times[3] + times[4] + times[5] + times[6] + times[7] + times[8] + times[9]) / 10.0;
	}
	void update(const double elapsed) {
		times[timel] = elapsed;
		timel = (timel + 1) % 10;
	}

	void reset() {
		times = { 0.0 };
		timel = 0;
	}

private:
	std::array<double, 10> times;
	int timel;
};