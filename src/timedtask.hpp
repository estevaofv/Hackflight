/*
   timedtask.hpp : a class for timed tasks

   This file is part of Hackflight.

   Hackflight is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hackflight is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "debug.hpp"

namespace hf {

class TimedTask {

    private:

        uint32_t usec;
        uint32_t period;

    public:

        void init(uint32_t _period) {

            period = _period;
            usec = 0;
        }

        bool checkAndUpdate(uint32_t currentTime) {

            bool result = ready(currentTime);

            if (result)
                update(currentTime);

            return result;
        }

        void update(uint32_t currentTime) {

            usec = currentTime + period;
        }

        bool ready(uint32_t currentTime) {

            return (int32_t)(currentTime - usec) >= 0;
        }
};

}
