/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "Sieve.h"
#include "Timer.h"
#include <chrono>

int main() {
	timer t;
	avgtime avgt;
	std::array<double, 8> results;

	std::cout << "Slow Sieve w/ Bitset (1st time, doesn't count):" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_slow s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	std::cout << "Time (10 run avg): " << avgt.get() << " ms" << std::endl;

	std::cout << "Slow Sieve w/ Bitset:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_slow s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[0] = avgt.get();
	std::cout << "Time (10 run avg): " << results[0] << " ms" << std::endl;

	std::cout << "Fast Sieve w/ Bitset:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_fast s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[1] = avgt.get();
	std::cout << "Time (10 run avg): " << results[1] << " ms" << std::endl;

	std::cout << "Slow Sieve w/ Vector:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_slow_vec s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[2] = avgt.get();
	std::cout << "Time (10 run avg): " << results[2] << " ms" << std::endl;

	std::cout << "Fast Sieve w/ Vector:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_fast_vec s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[3] = avgt.get();
	std::cout << "Time (10 run avg): " << results[3] << " ms" << std::endl;

	std::cout << "Slow Sieve w/ Bitset & ll out:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_slow_ll s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[4] = avgt.get();
	std::cout << "Time (10 run avg): " << results[4] << " ms" << std::endl;

	std::cout << "Fast Sieve w/ Bitset & ll out:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_fast_ll s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[5] = avgt.get();
	std::cout << "Time (10 run avg): " << results[5] << " ms" << std::endl;

	std::cout << "Slow Sieve w/ Vector & ll out:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_slow_vec_ll s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[6] = avgt.get();
	std::cout << "Time (10 run avg): " << results[6] << " ms" << std::endl;

	std::cout << "Fast Sieve w/ Vector & ll out:" << std::endl;
	avgt.reset();
	for (int i = 0; i < 10; i++) {
		t.reset();
		sieve_fast_vec_ll s;
		std::cout << s.calculate_num() << std::endl;
		avgt.update(t.elapsed_ms());
	}
	results[7] = avgt.get();
	std::cout << "Time (10 run avg): " << results[7] << " ms" << std::endl;

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-\nOVERALL:" << std::endl;
	std::cout << "Slow Sieve w/ Bitset: " << results[0] << " ms" << std::endl;
	std::cout << "Fast Sieve w/ Bitset: " << results[1] << " ms" << std::endl;
	std::cout << "Slow Sieve w/ Vector: " << results[2] << " ms" << std::endl;
	std::cout << "Fast Sieve w/ Vector: " << results[3] << " ms" << std::endl;
	std::cout << "Slow Sieve w/ Bitset & ll out: " << results[4] << " ms" << std::endl;
	std::cout << "Fast Sieve w/ Bitset & ll out: " << results[5] << " ms" << std::endl;
	std::cout << "Slow Sieve w/ Vector & ll out: " << results[6] << " ms" << std::endl;
	std::cout << "Fast Sieve w/ Vector & ll out: " << results[7] << " ms" << std::endl;


	std::cin.get();

}