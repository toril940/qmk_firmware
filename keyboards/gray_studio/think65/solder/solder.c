/* Copyright 2019 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "quantum.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.
#define CAPS_LOCK_LED A5
#define SCROLL_LOCK_LED A15

#define LAYER_1_PIN C8
#define LAYER_2_PIN C7
#define LAYER_3_PIN C6

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

bool led_update_kb(led_t led_state) {
  if(led_update_user(led_state)) {
    writePin(CAPS_LOCK_LED, !led_state.caps_lock);
    writePin(SCROLL_LOCK_LED, !led_state.num_lock);
  }
  return true;
}
