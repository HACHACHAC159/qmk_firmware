    
/* Copyright 2020
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
#include "candida.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 0 , 1 , 2 , 3 },
    { 7 , 6 , 5 , 4 },
    { 8 , 9 , 10, NO_LED },
    { 13, 12, 11 , NO_LED},
    { 14, 15, 16 ,  17 }

}, {
    {  0, 0 }, {  75,  0 }, {  149,  0 }, {  24,  0 },
	{  224, 16 }, {  149,  16 }, {  75,  16 }, {  0,  16 }, 
	{  0,  32 }, {  75,   32 }, {  149,   32 }, 
	{  149,  48 }, {  75,  48 }, {  0,  48 },
    {  0,  64 }, {  75,  64 }, {  149,  64 }, {  224,   64 }
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 4
} };
#endif
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}
