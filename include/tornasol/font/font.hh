#pragma once
#include <vector>
#include <filesystem>
#include "tornasol/common/common.hh"

namespace fs = std::filesystem;

namespace tornasol {

class font {
public:


private:
};

class TORNASOL_EXPORT font_manager {
public:


    auto load_font(fs::path path) -> result<font> {}

private:
    std::vector<font> m_loaded_fonts_list;
};

} // namespace tornasol