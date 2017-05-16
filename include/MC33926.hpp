/* COPYRIGHT (c) 2016-2017 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#pragma once

#include <ModuleConfiguration.hpp>

#include <core/hw/PWM.hpp>
#include <core/hw/GPIO.hpp>
#include <core/utils/BasicActuator.hpp>

namespace core {
namespace MC33926_driver {
class MC33926
{
public:
    MC33926(
        core::hw::PWMChannel& channel0,
        core::hw::PWMChannel& channel1,
        core::hw::Pad&        enable,
        core::hw::Pad&        d1
    );

    virtual
    ~MC33926();

public:
    bool
    probe();


public:
    core::hw::PWMChannel& _channel0;
    core::hw::PWMChannel& _channel1;
    core::hw::Pad&        _enable;
    core::hw::Pad&        _d1;
};


class MC33926_SignMagnitude:
    public core::utils::BasicActuator<float>
{
public:
    MC33926_SignMagnitude(
        const char* name,
        MC33926&    device
    );

    virtual
    ~MC33926_SignMagnitude();

public:
    bool
    init();

    bool
    configure();

    bool
    start();

    bool
    stop();

    bool
    waitUntilReady();

    bool
    set(
        const DataType& data
    );


protected:
    core::os::Time _set_timestamp;

private:
    MC33926& _device;
};
}
}
