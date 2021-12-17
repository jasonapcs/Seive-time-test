#pragma once

/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#define MAX_SIZE 1000'000'000
#include <bitset>
#include <vector>
#include <iostream>
#include <memory>

class sieve_slow {
public:
	sieve_slow() : set(std::make_unique<std::bitset<MAX_SIZE>>()) {
		set->flip();
	}

	int calculate_num() {
		// 0 and 1 aren't prime
		set->reset(0);
		set->reset(1);
		// start with the first prime
		for (int n = 2; n < MAX_SIZE; n++) {
			if ((*set)[n]) {
				// remove all multiples of primes
				for (int i = 2 * n; i < MAX_SIZE; i += n) {
					set->reset(i);
				}
			}
		}
		return set->count();
	}

	std::unique_ptr<std::bitset<MAX_SIZE>> set;
};

class sieve_fast {
public:
	sieve_fast() : set(std::make_unique<std::bitset<MAX_SIZE / 2 + 1>>()) {
		set->flip();
	}

	int calculate_num() {
		// remove 0 and 1
		set->reset(0);
		set->reset(1);
		// set a max limit of sqrt(sz)
		int uplim = (int)sqrt(MAX_SIZE);
		// start at 3 and go only through the odds
		for (int n = 3; n < uplim; n += 2) {
			if (get(n)) {
				// Skip even multiples
				for (int i = 3 * n; i < MAX_SIZE; i += 2 * n) {
					reset(i);
				}
			}
		}
		// Add 1 to include 2
		return set->count() + 1;
	}

	void reset(int idx) {
		set->reset((idx + 1) / 2);
	}

	bool get(int idx) {
		return (*set)[(idx + 1) / 2];
	}

	std::unique_ptr<std::bitset<MAX_SIZE / 2 + 1>> set;
};

class sieve_slow_vec {
public:
	sieve_slow_vec() : set(MAX_SIZE) {
		set.flip();
	}

	int calculate_num() {
		// 0 and 1 aren't prime
		set[0] = false;
		set[1] = false;
		// start with the first prime
		for (int n = 2; n < MAX_SIZE; n++) {
			if (set[n]) {
				// remove all multiples of primes
				for (int i = 2 * n; i < MAX_SIZE; i += n) {
					set[i] = false;
				}
			}
		}
		return std::count(set.begin(), set.end(), true);
	}

	std::vector<bool> set;
};

class sieve_fast_vec {
public:
	sieve_fast_vec() : set(MAX_SIZE / 2 + 1) {
		set.flip();
	}

	int calculate_num() {
		// remove 0 and 1
		set[0] = false;
		set[1] = false;
		// set a max limit of sqrt(sz)
		int uplim = (int)sqrt(MAX_SIZE);
		// start at 3 and go only through the odds
		for (int n = 3; n < uplim; n += 2) {
			if (get(n)) {
				// Skip even multiples
				for (int i = 3 * n; i < MAX_SIZE; i += 2 * n) {
					reset(i);
				}
			}
		}
		// Add 1 to include 2
		return std::count(set.begin(), set.end(), true) + 1;
	}

	void reset(int idx) {
		set[(idx + 1) / 2] = false;
	}

	bool get(int idx) {
		return set[(idx + 1) / 2];
	}

	std::vector<bool> set;
};

class sieve_slow_ll {
public:
	sieve_slow_ll() : set(std::make_unique<std::bitset<MAX_SIZE>>()) {
		set->flip();
	}

	long long calculate_num() {
		// 0 and 1 aren't prime
		set->reset(0);
		set->reset(1);
		// start with the first prime
		for (long long n = 2; n < MAX_SIZE; n++) {
			if ((*set)[n]) {
				// remove all multiples of primes
				for (long long i = 2 * n; i < MAX_SIZE; i += n) {
					set->reset(i);
				}
			}
		}
		return set->count();
	}

	std::unique_ptr<std::bitset<MAX_SIZE>> set;
};

class sieve_fast_ll {
public:
	sieve_fast_ll() : set(std::make_unique<std::bitset<MAX_SIZE / 2 + 1>>()) {
		set->flip();
	}

	long long calculate_num() {
		// remove 0 and 1
		set->reset(0);
		set->reset(1);
		// set a max limit of sqrt(sz)
		long long uplim = (long long)sqrt(MAX_SIZE);
		// start at 3 and go only through the odds
		for (long long n = 3; n < uplim; n += 2) {
			if (get(n)) {
				// Skip even multiples
				for (long long i = 3 * n; i < MAX_SIZE; i += 2 * n) {
					reset(i);
				}
			}
		}
		// Add 1 to include 2
		return set->count() + 1;
	}

	void reset(long long idx) {
		set->reset((idx + 1) / 2);
	}

	bool get(long long idx) {
		return (*set)[(idx + 1) / 2];
	}

	std::unique_ptr<std::bitset<MAX_SIZE / 2 + 1>> set;
};

class sieve_slow_vec_ll {
public:
	sieve_slow_vec_ll() : set(MAX_SIZE) {
		set.flip();
	}

	long long calculate_num() {
		// 0 and 1 aren't prime
		set[0] = false;
		set[1] = false;
		// start with the first prime
		for (long long n = 2; n < MAX_SIZE; n++) {
			if (set[n]) {
				// remove all multiples of primes
				for (long long i = 2 * n; i < MAX_SIZE; i += n) {
					set[i] = false;
				}
			}
		}
		return std::count(set.begin(), set.end(), true);
	}

	std::vector<bool> set;
};

class sieve_fast_vec_ll {
public:
	sieve_fast_vec_ll() : set(MAX_SIZE / 2 + 1) {
		set.flip();
	}

	long long calculate_num() {
		// remove 0 and 1
		set[0] = false;
		set[1] = false;
		// set a max limit of sqrt(sz)
		long long uplim = (long long)sqrt(MAX_SIZE);
		// start at 3 and go only through the odds
		for (long long n = 3; n < uplim; n += 2) {
			if (get(n)) {
				// Skip even multiples
				for (long long i = 3 * n; i < MAX_SIZE; i += 2 * n) {
					reset(i);
				}
			}
		}
		// Add 1 to include 2
		return std::count(set.begin(), set.end(), true) + 1;
	}

	void reset(long long idx) {
		set[(idx + 1) / 2] = false;
	}

	bool get(long long idx) {
		return set[(idx + 1) / 2];
	}

	std::vector<bool> set;
};