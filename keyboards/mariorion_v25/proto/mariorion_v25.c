// Copyright 2023 Maria @toril940
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "quantum.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	setPinOutput(A5);
	setPinOutput(A15);
	setPinOutput(C8);
	setPinOutput(C7);
	setPinOutput(C6);
	matrix_init_user();
}

__attribute__((weak)) bool led_update_kb(led_t led_state) {
	if(led_update_user(led_state)) {
		writePin(CAPS_LOCK_LED, !led_state.caps_lock);
		writePin(SCROLL_LOCK_LED, !led_state.num_lock);
	}
	return true;
}

__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case 1:
			writePinHigh(INDICATOR_0);
			writePinLow(INDICATOR_1);
			writePinLow(INDICATOR_2);
			break;
		case 2:
			writePinLow(INDICATOR_0);
			writePinHigh(INDICATOR_1);
			writePinLow(INDICATOR_2);
			break;
		case 3:
			writePinLow(INDICATOR_0);
			writePinLow(INDICATOR_1);
			writePinHigh(INDICATOR_2);
			break;
		default:
			writePinHigh(INDICATOR_0);
			writePinHigh(INDICATOR_1);
			writePinHigh(INDICATOR_2);
			break;
	}
	return state;
}

void suspend_power_down_kb(void) {
	writePinLow(INDICATOR_0);
	writePinLow(INDICATOR_1);
	writePinLow(INDICATOR_2);

	suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
	writePinHigh(INDICATOR_0);
	writePinHigh(INDICATOR_1);
	writePinHigh(INDICATOR_2);

	suspend_wakeup_init_user();
}