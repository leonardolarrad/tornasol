#pragma once
#include "tornasol/common/common.hh"

namespace sol {

class TORNASOL_EXPORT engine;
TORNASOL_EXPORT auto init_engine() -> result<engine>; 

class TORNASOL_EXPORT engine {
public:
    ~engine();
    engine(engine&&) noexcept;
    engine& operator=(engine&&) noexcept;
    engine(engine const&) = delete;
    engine& operator=(engine const&) = delete;

    auto poll_events() noexcept -> void;
    
private:    
    engine() noexcept;
    
    TORNASOL_EXPORT
    friend auto init_engine() -> result<engine>;

    bool _main_instance = false;
};

} // namespace sol